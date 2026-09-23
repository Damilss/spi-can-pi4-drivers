#!/bin/bash

# systemd-networkd-config.sh
# creates a systemd-networkd configuration for a CAN interface named can0
# then starts/enables systemd-networkd so that configuration can be applied
# Usage: systemd-networkd-config.sh
set -euo pipefail

# see `/docs/can0-testing.md` for more info
 sudo tee /etc/systemd/network/80-can0.network <<'EOF'
[Match]
Name=can0

[Link]
RequiredForOnline=no

[CAN]
BitRate=500K
RestartSec=100ms
EOF

sudo systemctl enable --now systemd-networkd

exit 0
