#include <Windows.h>    
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../inc/lowLevelUARTDriver.h"

const int BUFSIZE = 140;							
const char* COM_PORT = "COM7";									

HANDLE serialComHandler;										
int serialFrequency = 9600;							
int amountOfDataBits = 8;									
COMMTIMEOUTS timeout;								

int main() {

	installSerialDriver(&serialComHandler, COM_PORT, serialFrequency, amountOfDataBits, timeout);	// Initialize the Tx port
	Sleep(500);


	char msgOut[] = "Hi there person";			
    for(int i = 0; i < 500; i++)				
    {
        sendMessage(&serialComHandler, msgOut, strlen(msgOut)+1);	
        Sleep(1000);		
    }
	
	purgePort(&serialComHandler);										
	CloseHandle(serialComHandler);										
	
	system("pause");
}