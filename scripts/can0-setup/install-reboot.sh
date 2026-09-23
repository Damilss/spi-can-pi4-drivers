#!/bin/bash

# install-reboot.sh
# this script updaate apt and installs can utils 
set -euo pipefail

#apt is just a package installer
sudo apt update && sudo apt install -y can-utils
echo 'please run `sudo reboot` to apply changes!' 

exit 0

