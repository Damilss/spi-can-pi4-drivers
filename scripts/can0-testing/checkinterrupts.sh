#!/bin/bash

# checkinterrupts.sh 
# checks for any interrups thrown over the SPI interface
set -euo pipefail

# You'll get something like:
# 51:          0          0          0          0  ...  spi0
# /proc/interrupts is roughlt structered like
# IRQ:   CPU0   CPU1   CPU2   CPU3   interrupt-controller ... device 
# CPU0-3 is where the interrupts appear
if ! grep spi0 /proc/interrupts; then
	echo 'No spi0 interrupt entry found; see docs/can0-testing.md for more info'
fi

exit 0

