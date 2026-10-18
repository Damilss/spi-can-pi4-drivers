# spi-can-pi4-drivers

> This project is based for the Cal Poly FSAE project for the firmware
> subsystem. 

> Tip: Use TAB to autocomplete certain command in your terminal, this will help navigating `./scripts`! 
## Objective
**Write/Find functions to initialize, write, and read data using the SPI**

## Repo Structure
```sh
/spi-can-pi4-drivers
├── .clang-format
├── compile_flags.txt
├── CONTRIBUTING.md
├── docs
│   ├── can0-setup.md
│   ├── can0-testing.md
│   ├── can20.pdf
│   ├── exec-at-startup.md
│   ├── raspberry-pi-wifi-cheatsheet.md
│   ├── refs
│   │   ├── GPIO-pin-guide.png
│   │   ├── MCP25625-CAN-Controller-Data-Sheet-20005282C.pdf
│   │   └── mcp25625-click-schematic-v100.pdf
│   ├── reports
│   │   ├── 2026-09-23
│   │   │   └── pi_config_9_23.md
│   │   ├── README.md
│   │   └── README_TEMPLATE.md
│   ├── spi-setup.md
│   ├── src-pican-cpp.md
│   └── vcan0-setup.md
├── .editorconfig
├── .gitignore
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
├── src
│   ├── can.cpp
│   ├── can.h
│   ├── CANTest.cpp
│   ├── dataIntake.cpp
│   └── dataIntake.h
└── .vscode
    └── extensions.json

10 directories, 37 files
```

### workflow and overview

**Workflow documented**: Communication workflow labeled in documentation from the
official document goes as follows: 

`CAN <--  --> MCP25625 <--  --> CAN data over SPI <--- ---> RPI recieves data`

**Documentation states to use SocketCAN in the kernal on the raspberry pi 4 to
recieve and transmit data.** 

### CAN Chips

| Transiever Chip | Chip details |
| ---- | ----- | 
| [MCP25625](./docs/MCP25625-CAN-Controller-Data-Sheet-20005282C.pdf) |  CAN 2.0 Only, integrated transceiver functionality (RXCAN and TXCAN to CANL/CANH, Maximum payload is 8 bytes per frame |   
|[mcp25625-click](./docs/mcp25625-click-schematic-v100.pdf) | Current MCP25625 integrated transciever and controller that we're using for testing | 

### stmcarcode branch 

stmcarcode branch is for porting over into the actual car code respository and should only be manually edited


---
See [Cal Poly FSAE](https://github.com/CalPolyFSAE/)

