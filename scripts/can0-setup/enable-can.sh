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

#creates temp file
tmpfile=$(mktemp)
trap 'rm -f "$tmpfile"' EXIT

cat /boot/firmware/config.txt | grep "dtparam=spi=on|dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25" > "$tmpfile"

# if config lines already exits, exits script
 if [[ -s "$tmpfile" ]]; then
	 echo 'config.txt already contains one or more lines for enabling-can'
	 exit 1
 fi

# inserts config
echo >> "$CONFIG" && echo "$comment" >> "$CONFIG" && echo "$line1" >> "$CONFIG"
echo "$line2" >> "$CONFIG" && echo >> "$CONFIG"

exit 0
