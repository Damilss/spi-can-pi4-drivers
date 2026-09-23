## overview 
> Note that as of the time this documentation was committed, we have not been able to get a full loopback to run on the PI with the MCP25625

this document provides a full guide on how to setup a Raspberry Pi 4/5
for the SPI-CAN drivers. Please follow all these steps and refer to other viable
sources of documentation 

**Please see `../scripts` for the needed scripts to run.

### 1. ensure that your pi is connected to WI-FI

pleas see my personal wifi cheatsheet doc I added,
`raspberry-pi-wifi-cheatsheet.md` for more information on how to set it up through
cli.

### 2. GPIO pins

see `GPIO-pin-guide.png` for photo reference

### 3. add configuration to firmware config

Oscilloscope: 16k
run `sudo scripts/can0-setup/enable-can.sh` and follow instructions

Oscilloscope: 20k
run `sudo scripts/can0-setup/20k-enable-can.sh` and follow instructions.
> (20k might be needed for this chip, check schematic)

> [!WARNING]
> Please check your Raspberry PI OS version this script is designed for newer
> versions where `config.txt` is in `/boot/firmware/config.txt`. Older versions
> will hold it in `/boot/config.txt`.

### 4. add can-utils

**YOU MUST BE CONNECTED TO WIFI (STEP 1)** 

run `scripts/can0-setup/install-reboot.sh` This script runs **SUDO** commands.

### 5. verify tools loaded 

run `scripts/can0-setup/verifytools.sh`. 
On success you'll see a line saying the MCP251x on spi0.0 initialized successfully
as can0. The chip is reported as an MCP251x, which is expected.

---

**DONE:** Should be all set-up, refer to `docs/can0-testing.md` for testing!
