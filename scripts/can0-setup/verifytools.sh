#!/bin/bash

# verifytools.sh
# run this after reboot and config to verify tools loaded properly.

# on success you'll see a line saying the MCP251x on spi0.0 initialized
# successfully as can0. the chip is reported as an MCP251x, which is expected

# dmesg displays kernel's ring buffer, which includes information about 
# hardware, device drivers, and system events
set -euo pipefail

dmesg | grep -i mcp251x
ip link show can0

exit 0

