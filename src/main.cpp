#include "main.h"

#include "dataIntake.h"

// This should point to our current drivers, not from STMcarcode
#include "../../../../shared/drivers/cm4/can.h"

int main()
{
    const char* socketPath = "/tmp/ccm.sock";
    int server = joinSocket(socketPath);
    if(server < 0){
        return 1;
    }

    uint8_t sendbuf[MSG_BUF_SIZE];

    for (;;){

        /*
        this is where all propegation will happen
        will recv data from:
        - SPI
        will send to:
        - LOG

        read data from 3 spi peripherals
        pack data
        send to log

        poll(0)
        if recv data from ccm, send it over CAN
        */

        packMessage(CAN, LOG, 0, 0, 0, NULL, (ipcHeader*)sendbuf);
        send(server, sendbuf, sizeof(ipcHeader), 0);
    }

    close(server);
    return 0;
}
