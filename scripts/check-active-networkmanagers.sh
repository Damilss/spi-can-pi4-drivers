#!/bin/bash

# check-active-networkmanagers.sh
# checks to see if systemd-networkd and NetworkManager are active
set -euo pipefail

# having explicit if else branches prevents the code exiting prematurely due to a 
# non-exit 0 from one of the commands. Perserves `set -euo pipefail` cleanly
# while still maintaing the same logic
if systemctl is-active --quiet systemd-networkd; then
	echo 'systemd-networkd: ACTIVE'
else
	echo 'systemd-networkd: INACTIVE'
fi

if systemctl is-active --quiet NetworkManager; then 
	echo 'NetworkManager: ACTIVE'
else
	echo 'NetworkManager: INACTIVE'
fi

exit 0
