#ifndef LOW_LEVEL_UART_DRIVER
#define LOW_LEVEL_UART_DRIVER

#include<windows.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>



/**
 * @brief                       This function makes it possible to install the serial driver to send serial data. 
 * 
 * 
 * 
 * @param serialComHandler      This variable manages the serial communication. 
 * @param COMPORT               This is the serial port which is used to communicate.
 * @param frequencySerial       This is the baudrate of the serial communication.         
 * @param amountOfDataBits      This is the amount of data bits.
 * @param timeout               This is the timeout of the serial communcication.
 * 
 * @return int                  Return 1 if the function is succesfully executed.
 */
int installSerialDriver(HANDLE* serialComHandler, const char* COMPORT, int frequencySerial, int amountOfDataBits, COMMTIMEOUTS timeout);



/** 
 * @brief                        This function makes it possible to clear the data of the serial bus.
 * 
 * 
 * 
 * @param serialComHandler       This variable manages the serial communication. 
 */
void purgePort(HANDLE* serialComHandler);



/**     
 * @brief                       This function makes it possible to send an serial message.
 * 
 * 
 * 
 * @param serialComHandler      This variable manages the serial communication. 
 * @param message               This variabele holds the data that needs to be send.
 * @param message_size          This is the size of the message.
 * 
 * @return int                  Return 1 if the function is succesfully executed.
 */
int sendMessage(HANDLE* serialComHandler, LPCVOID message, DWORD message_size);



/**
 * @brief                        This function makes it possible to receive messages.
 * 
 * 
 * 
 * @param serialComHandler       This variable manages the serial communication.                  
 * @param message                This variabele holds the data that needs to be send.
 * @param message_size           This is the size of the message.
 * 
 * @return DWORD                 Returns the size of the message. If it equals 0 then it the function failed.
 */
DWORD receiveMessage(HANDLE* hCom, LPVOID buf, DWORD szBuf);



/**
 * @brief                       This function makes it possible to connect to the serial port.
 * 
 * 
 * 
 * @param serialComHandler      This variable manages the serial communication.      
 * @param COMPORT               This is the serial port which is used to communicate.
 * 
 * @return int                  Return 1 if the function is succesfully executed.
 */
int connectSerialPort(HANDLE* hCom, const char* COMPORT);



/**
 * @brief                       Return if the function is succesfully executed.
 * 
 * 
 * 
 * @param serialComHandler      This variable manages the serial communication.                  
 * @param frequencySerial       This is the baudrate of the serial communication.
 * @param amountOfDataBits      This is the amount of data bits.
 * @param timeout               This is the timeout of the serial communcication.
 * 
 * @return int                  Return 1 if the function is succesfully executed.
 */
int configureSerialCommunication(HANDLE* hCom, int nComRate, int nComBits, COMMTIMEOUTS timeout);

#endif
