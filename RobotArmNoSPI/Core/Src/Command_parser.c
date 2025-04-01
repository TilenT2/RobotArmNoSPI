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

extern Motor_TypeDef my_motor;

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
    } else {
        USB_Send_Response("ERR\n");
    }
}
