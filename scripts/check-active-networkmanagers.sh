#!/bin/bash

# check-active-networkmanagers.sh
# checks to see if systemd-networkd and NetworkManager are active
set -euo pipefail

echo 'checking NetworkManager...'
systemctl is-active NetworkManager
echo

echo 'checking systemd-networkd...'
systemctl is-active systemd-networkd
exit 0 

