# spi-can-pi4-drivers

> This project is based for the Cal Poly FSAE New member project for the firmware
> subsystem. Ultimately decided not to make it in the org and just on my personal

## Objetive
**Write/Find functions to initialize, write, and read data using the SPI 
.
├── docs
│   ├── can20.pdf
│   ├── MCP25625-CAN-Controller-Data-Sheet-20005282C.pdf
│   ├── mcp25625-click-schematic-v100.pdf
│   └── Screenshot 2026-09-22 at 1.44.57 PM.png
├── README.md
└── src
    ├── CANStructs.h
    ├── dataIntake.cpp
    ├── dataIntake.h
    └── pican.cpp

3 directories, 9 filesperipherals from the Pi. This is in C++**

### workflow and overveiw

**Workflow documented**: Communication workflow labeled in documentation from the
official document goes as follows: 

`CAN <--  --> MCP25625 <--  --> CAN data over SPI <--- ---> RPI recieves data`

**Documentation states to use SocketCAN in the kernal on the raspberry pi 4 to
recieve and transmit data.** 

### CAN Chips

| Transiever Chip | Chip details |
| ---- | ----- | 
| [MCP25625](./docs/MCP25625-CAN-Controller-Data-Sheet-20005282C.pdf) |  CAN 2.0 Only, integrated transceiver functionality (RXCAN and TXCAN to CANL/CANH, Maximum payload is 8 bytes per frame |   


**Side Note:** Not that it will make any difference, but I will be using a raspberry pi 5 rather than a pi 4.


### Repository Structure
```sh
/spi-can-pi4-drivers
├── docs
│   ├── can20.pdf
│   ├── MCP25625-CAN-Controller-Data-Sheet-20005282C.pdf
│   ├── mcp25625-click-schematic-v100.pdf
│   └── Screenshot 2026-09-22 at 1.44.57 PM.png
├── README.md
└── src
    ├── CANStructs.h
    ├── dataIntake.cpp
    ├── dataIntake.h
    └── pican.cpp

3 directories, 9 files
```

See [Cal Poly FSAE](https://github.com/CalPolyFSAE/)
