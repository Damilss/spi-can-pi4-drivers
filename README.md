# spi-can-pi4-drivers

> This project is based for the Cal Poly FSAE New member project for the firmware
> subsystem. Ultimately decided not to make it in the org and just on my personal

> Tip: Use TAB to autocomplete certain command in your terminal, this will help navigating `./scripts`! 
## Objetive
**Write/Find functions to initialize, write, and read data using the SPI 

## Repo Structure
```sh
/spi-can-pi4-drivers
├── docs
│   ├── can0-setup.md
│   ├── can0-testing.md
│   ├── can20.pdf
│   ├── GPIO-pin-guide.png
│   ├── MCP25625-CAN-Controller-Data-Sheet-20005282C.pdf
│   ├── mcp25625-click-schematic-v100.pdf
│   ├── raspberry-pi-wifi-cheatsheet.md
│   ├── spi-setup.md
│   └── vcan0-setup.md
├── README.md
├── scripts
│   ├── can0-setup
│   │   ├── 20k-enable-can.sh
│   │   ├── enable-can.sh
│   │   ├── install-reboot.sh
│   │   └── verifytools.sh
│   ├── can0-testing
│   │   ├── checkinterrupts.sh
│   │   ├── loopback-test.sh
│   │   ├── sendcanframe.sh
│   │   └── test.sh
│   ├── check-active-networkmanagers.sh
│   ├── checkbusstate.sh
│   └── systemd-networkd-config.sh
└── src
    ├── CANStructs.h
    ├── dataIntake.cpp
    ├── dataIntake.h
    └── pican.cpp

6 directories, 25 files

```

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

See [Cal Poly FSAE](https://github.com/CalPolyFSAE/)
