/**
 * @file shell_port.h
 * @author Letter (NevermindZZT@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-22
 * 
 * @copyright (c) 2019 Letter
 * 
 */

#ifndef __SHELL_PORT_H__
#define __SHELL_PORT_H__

//#include "serial.h"
#include "shell.h"
#include "stdio.h"

#define serialTransmit HAL_UART_Transmit
#define serialReceive HAL_UART_Receive
#define SHELL_USART_H huart3
#define SHELL_USART_I USART3

extern Shell shell;
extern FILE *f_shell;

void userShellInit(void);
#endif
