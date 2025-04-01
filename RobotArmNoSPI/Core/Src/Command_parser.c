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
    int motor;
    float degrees;



    if(sscanf(cmd, "M%d %f", &motor, &degrees) == 2) {
        if(motor >= 1 && motor <= 7) {
            // Call motor control function here
        	Motor_Set_Target_Degrees(&my_motor, degrees);
        	Motor_Start(&my_motor);
            USB_Send_Response("MOVING\n");
        }
    }
	if (sscanf(cmd, "E%d", &motor) == 1) {
		if (motor >= 1 && motor <= 7) {
			HAL_GPIO_WritePin(ENABLE1_GPIO_Port, ENABLE1_Pin, GPIO_PIN_RESET);
			USB_Send_Response("MOTOR ENABLED\n");
		}
	}
	if (sscanf(cmd, "D%d", &motor) == 1) {
		if (motor >= 1 && motor <= 7) {
			HAL_GPIO_WritePin(ENABLE1_GPIO_Port, ENABLE1_Pin, GPIO_PIN_SET);
			USB_Send_Response("MOTOR DISABLED\n");
		}
	}



}
