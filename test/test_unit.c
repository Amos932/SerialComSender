/*************************************************
 * 
 * Author: 			A.C.Middelkoop
 * Description:		This file tests all the basic functionalities of the system in order to verify the quality.
 * 
 * 
 * **********************************************/

// Include all standard C libraries.
#include <Windows.h>    
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Include selfmade files.
#include "../inc/lowLevelUARTDriver.h"
#include "../inc/configSerialData.h"

void test_function(void)
{
    HANDLE serialComHandler;
    COMMTIMEOUTS timeout;								
    configSerialData configDataSender = {
        .amountOfDataBits = 8,
        .BUFSIZE = 140,
        .COM_PORT = "COM8",
        .serialFrequency = 9600
    };

    TEST_CHECK(installSerialDriver(&serialComHandler, configDataSender.COM_PORT, configDataSender.serialFrequency, configDataSender.amountOfDataBits, timeout)==(1));

    int installSerialDriver(HANDLE* serialComHandler, const char* COMPORT, int frequencySerial, int amountOfDataBits, COMMTIMEOUTS timeout);

}

TEST_LIST= {
    {"Testing an function", test_function}, {0}
}






































void testing_install_serial_driver