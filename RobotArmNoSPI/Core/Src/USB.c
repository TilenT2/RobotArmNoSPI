/*
 * USB.c
 *
 *  Created on: Apr 1, 2025
 *      Author: tilen
 */




#include "usb.h"
#include "usbd_cdc_if.h"

#define RX_BUFFER_SIZE 64
static uint8_t rx_buffer[RX_BUFFER_SIZE];
volatile static uint8_t data_received = 0;
static uint32_t data_size = 0;

// Called from CDC_Receive_FS
void USB_Receive_Callback(uint8_t* Buf, uint32_t *Len) {
    data_size = (*Len < RX_BUFFER_SIZE) ? *Len : RX_BUFFER_SIZE;
    memcpy(rx_buffer, Buf, data_size);
    data_received = 1;
}

void USB_Process_Received_Data(void) {
    if(data_received) {
        // Add null terminator
        char cmd[RX_BUFFER_SIZE + 1] = {0};
        memcpy(cmd, rx_buffer, data_size);
        Parse_Command(cmd);
        data_received = 0;
    }
}

void USB_Send_Response(const char *response) {
    CDC_Transmit_FS((uint8_t*)response, strlen(response));
}
