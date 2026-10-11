#include "main.h"

int main()
{
    const char* socketPath = "/tmp/gateway.sock";
    int server = joinSocket(socketPath);
    if(server < 0){
            return 1;
        }
    uint8_t sendbuf[MSG_BUF_SIZE];

    for(;;){
	    /*
	     * this is where all propegation will happen
	     * will rx data from:
	     * spi
	     * will send to long
	     */

	    dataPayload payload;

	    // need to look into who MCP25625 formats data
	    // pack the paylaod and send it to main process

	    packMessage();
	    send();
	    printf("oh im sending\n");
    }

    close(sever);
    return 0; 
}

