/*
 * Motor_control.c
 *
 *  Created on: Apr 1, 2025
 *      Author: tilen
 */
#include "Motor_control.h"
#include "main.h"
#include "math.h"
#include "usb.h"


#define PULSES_PER_DEGREE (51200.0f / 360.0f)



void Motor_Init(Motor_TypeDef *motor, TIM_HandleTypeDef *timer, uint32_t channel,
                GPIO_TypeDef* dir_port, uint16_t dir_pin,
                GPIO_TypeDef* enable_port, uint16_t enable_pin) {
    motor->timer = timer;
    motor->channel = channel;
    motor->dir_port = dir_port;
    motor->dir_pin = dir_pin;
    motor->enable_port = enable_port;
    motor->enable_pin = enable_pin;
    motor->current_pulses = 0;
    motor->target_pulses = 0;
    motor->is_moving = 0;
    motor->direction = 0;
    // HAL_GPIO_WritePin(DIR1_GPIO_Port, DIR1_Pin, GPIO_PIN_RESET);
}



void Motor_Set_Target_Degrees(Motor_TypeDef *motor, float degrees) {

	motor->direction = (degrees < 0) ? 1 : 0;

	float abs_degrees = fabsf(degrees);
    motor->target_pulses = (int32_t)(abs_degrees * PULSES_PER_DEGREE);
    motor->current_pulses = 0;
}



void Motor_Start(Motor_TypeDef *motor) {
    if(motor->target_pulses == 0) return;

    HAL_GPIO_WritePin(motor->dir_port, motor->dir_pin, motor->direction);

    motor->is_moving = 1;
    HAL_TIM_PWM_Start(motor->timer, motor->channel);
    HAL_TIM_Base_Start_IT(motor->timer);
}



void Motor_Stop(Motor_TypeDef *motor) {
    motor->is_moving = 0;
    HAL_TIM_PWM_Stop(motor->timer, motor->channel);
    HAL_TIM_Base_Stop_IT(motor->timer);
}




void Motor_TIM_Interrupt_Handler(TIM_HandleTypeDef *htim) {
    for(int i = 0; i < 7; i++) {
        if(htim->Instance == my_motors[i].timer->Instance) {
            if(my_motors[i].is_moving) {
                my_motors[i].current_pulses++;
                if(my_motors[i].current_pulses >= my_motors[i].target_pulses) {
                    Motor_Stop(&my_motors[i]);
                    USB_Send_Response("DONE\n");
                }
            }
        }
    }
}




