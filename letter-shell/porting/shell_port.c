/**
 * @file shell_port.c
 * @author Letter (NevermindZZT@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-22
 * 
 * @copyright (c) 2019 Letter
 * 
 */

#include "shell.h"
//#include "serial.h"
#include "stm32f4xx_hal.h"
#include "usart.h"
#include "stdio.h"
#include "shell_port.h"

Shell shell;
char shellBuffer[512];

FILE *f_shell = (FILE *)&f_shell;

#define debugSerial huart3

/**
 * @brief 用户shell写
 * 
 * @param data 数据
 */
void userShellWrite(char data)
{
    serialTransmit(&debugSerial, (uint8_t *)&data, 1, 0xFF);
    //fprintf(f_shell, "%c", data);
}


/**
 * @brief 用户shell读
 * 
 * @param data 数据
 * @return char 状态
 */
signed char userShellRead(char *data)
{
    if (serialReceive(&SHELL_USART_H, (uint8_t *)data, 1, 0) == 1)
    {
        return 0;
    }
    else
    {
        return -1;
    }
    
}


/**
 * @brief 用户shell初始化
 * 
 */
void userShellInit(void)
{
    shell.write = userShellWrite;
    shell.read = userShellRead;
    shellInit(&shell, shellBuffer, 512);
}

