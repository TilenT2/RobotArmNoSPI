/*
 * USB.h
 *
 *  Created on: Apr 1, 2025
 *      Author: tilen
 */

#ifndef INC_USB_H_
#define INC_USB_H_

#include "stm32f4xx_hal.h"


void USB_Process_Received_Data(void);
void USB_Send_Response(const char *response);


#endif /* INC_USB_H_ */
