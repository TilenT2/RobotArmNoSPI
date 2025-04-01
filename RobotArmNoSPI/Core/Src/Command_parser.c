/*
 * Command_parser.c
 *
 *  Created on: Apr 1, 2025
 *      Author: tilen
 */

#include "command_parser.h"
#include "usb.h"
#include <stdio.h>
#include "motor_control.h"
#include "main.h"

extern Motor_TypeDef my_motor;


//M1-7 Number

void Parse_Command(const char *cmd) {
    int motor_num;
    float degrees;

    if(sscanf(cmd, "M%d %f", &motor_num, &degrees) == 2) {
        if(motor_num >= 1 && motor_num <= 7) {
            Motor_Set_Target_Degrees(&my_motors[motor_num-1], degrees);
            Motor_Start(&my_motors[motor_num-1]);
        }
    }
    else if(sscanf(cmd, "E%d", &motor_num) == 1) {
        if(motor_num >= 1 && motor_num <= 7) {
            HAL_GPIO_WritePin(my_motors[motor_num-1].enable_port,
                            my_motors[motor_num-1].enable_pin, GPIO_PIN_RESET);
            USB_Send_Response("ENABLED\n");
        }
    }
    else if(sscanf(cmd, "D%d", &motor_num) == 1) {
        if(motor_num >= 1 && motor_num <= 7) {
            HAL_GPIO_WritePin(my_motors[motor_num-1].enable_port,
                            my_motors[motor_num-1].enable_pin, GPIO_PIN_SET);
            USB_Send_Response("DISABLED\n");
        }
    }
    else {
		USB_Send_Response("INVALID COMMAND YOU DIPSHIT\n");

	}
}
