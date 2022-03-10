#include "../inc/lowLevelUARTDriver.h"

int installSerialDriver (HANDLE* serialComHandler, const char* COMPORT, int serialFrequency, int amountOfDataBits, COMMTIMEOUTS timeout) 
{
    if(connectSerialPort(serialComHandler, COMPORT) == 0) 
        return (0);

     purgePort(serialComHandler);
    
    if(configureSerialCommunication(serialComHandler, serialFrequency, amountOfDataBits, timeout) == 0)
        return (0);

    purgePort(serialComHandler);

    return 1;
}

int connectSerialPort (HANDLE* serialComHandler, const char* COMPORT) 
{
    *serialComHandler = CreateFile(COMPORT, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    /* Checking if it is able to open up the serial port. */
    if(*serialComHandler == INVALID_HANDLE_VALUE)
        printf("ERROR: can't opening up the serial port. Check if your serial port is connected.");
    else 
        return (0);


    CloseHandle(serialComHandler);

    return (1);
}

void purgePort (HANDLE* serialComHandler) 
{
	PurgeComm(*serialComHandler, PURGE_RXABORT | PURGE_RXCLEAR | PURGE_TXABORT | PURGE_TXCLEAR);
}

int sendMessage (HANDLE* serialComHandler, LPCVOID message, DWORD message_size) {
	int i = 0;

	DWORD NumberofBytesTransmitted;
	LPDWORD lpErrors = 0;
	LPCOMSTAT lpStat = 0; 

	i = WriteFile(*serialComHandler, message, message_size,	&NumberofBytesTransmitted, NULL);
	

	if (i == 0) 
    {
		printf("\nWrite Error: 0x%x\n", GetLastError());
		ClearCommError(serialComHandler, lpErrors, lpStat);	
        return (0);	
    }


	printf("Successful transmission!");

    return (1);
}

DWORD receiveMessage (HANDLE* serialComHandler, LPVOID message, DWORD message_size) 
{
	int i = 0;
	DWORD NumberofBytesRead;
	LPDWORD lpErrors = 0;
	LPCOMSTAT lpStat = 0;

	i = ReadFile(*serialComHandler,	message, message_size, &NumberofBytesRead, NULL);

	if (i == 0) 
    {
		printf("\nRead Error: 0x%x\n", GetLastError());
		ClearCommError(serialComHandler, lpErrors, lpStat);		
        return 0;
    }


	printf("\nSuccessful receiced!");

	return(NumberofBytesRead);
}

int configureSerialCommunication (HANDLE* serialComHandler, const int serialFrequency, const int amountOfDataBits, COMMTIMEOUTS timeout)
{
    DCB dcb;

	memset(&dcb, 0, sizeof(dcb));
	dcb.DCBlength = sizeof(dcb);
	if (!GetCommState(*serialComHandler, &dcb))
		return(0);

	
	dcb.BaudRate = serialFrequency;						
	dcb.ByteSize = (BYTE)amountOfDataBits;					
	dcb.Parity = 0;										
	dcb.StopBits = ONESTOPBIT;						
	if (!SetCommState(*serialComHandler, &dcb))
		return(0);

	
	memset((void *)&timeout, 0, sizeof(timeout));
	timeout.ReadIntervalTimeout = 500;				
	timeout.ReadTotalTimeoutMultiplier = 1;			
	timeout.ReadTotalTimeoutConstant = 5000;		
	SetCommTimeouts(*serialComHandler, &timeout);
	return(1);
}