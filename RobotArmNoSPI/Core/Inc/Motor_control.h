/*
 * Motor_control.h
 *
 *  Created on: Apr 1, 2025
 *      Author: tilen
 */

#ifndef INC_MOTOR_CONTROL_H_
#define INC_MOTOR_CONTROL_H_

#include "stm32f4xx_hal.h"

typedef struct {
    TIM_HandleTypeDef *timer;
    uint32_t channel;
    volatile int32_t current_pulses;
    volatile int32_t target_pulses;
    uint8_t is_moving;
    uint8_t direction;
} Motor_TypeDef;



extern Motor_TypeDef my_motor;


void Motor_Init(Motor_TypeDef *motor, TIM_HandleTypeDef *timer, uint32_t channel);

void Motor_Set_Target_Degrees(Motor_TypeDef *motor, float degrees);


void Motor_Start(Motor_TypeDef *motor);
void Motor_Stop(Motor_TypeDef *motor);


void Motor_TIM_Interrupt_Handler(TIM_HandleTypeDef *htim);




#endif /* INC_MOTOR_CONTROL_H_ */
