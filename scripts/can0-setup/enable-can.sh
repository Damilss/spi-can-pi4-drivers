#!/bin/bash

# This script enables can on Pi specific for our specific
# MCP 25625 Mikroelektronika board with integrated transciever and controller
# This scirpt was made for Raspberry Pi 4/5 runnning on newer raspberry PI OS
# version. Please check your before runing the script. 
# Usage: sudo ./enable-can.sh

set -euo pipefail

readonly USAGE='Usage: sudo ./enable-can.sh'

if (( EUID != 0 )); then
	echo "$USAGE" >&2
	exit 2
fi

# config location (possible /boot/config.txt later on)
readonly CONFIG='/boot/firmware/config.txt'

if [[ ! -e "$CONFIG" ]]; then 
	echo "$CONFIG does not exist" >&2
	exit 1
fi

# grabs users date
DATE=$(date)
comment="# enable-can ran on "$DATE", remove to disable CAN"
line1='dtparam=spi=on'
line2='dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25'

# Exit if either CAN config line already exists
if grep -qxF "$line1" "$CONFIG" || grep -qxF "$line2" "$CONFIG"; then
	echo 'config.txt already contains one or more lines for enabling CAN'
	exit 1
fi

# Insert CAN configuration
printf '\n%s\n%s\n%s\n\n' "$comment" "$line1" "$line2" >> "$CONFIG"
exit 0
