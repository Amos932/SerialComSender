#ifndef LOW_LEVEL_UART_DRIVER
#define LOW_LEVEL_UART_DRIVER

#include<windows.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int installSerialDriver(HANDLE* hCom, const char* COMPORT, int nComRate, int nComBits, COMMTIMEOUTS timeout);
void purgePort(HANDLE* hCom);
int sendMessage(HANDLE* serialComHandler, LPCVOID message, DWORD message_size);
DWORD receiveMessage(HANDLE* hCom, LPVOID buf, DWORD szBuf);

int connectSerialPort(HANDLE* hCom, const char* COMPORT);
static int configureSerialCommunication(HANDLE* hCom, int nComRate, int nComBits, COMMTIMEOUTS timeout);

#endif