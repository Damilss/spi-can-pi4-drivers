#!/bin/bash

# test.sh
# runs a full test (no loopback)
# NOTE: You must have a full CAN bus to run without loopback mode
# see can0-testing.md for more information
set -euo pipefail

echo 'setting can0 DOWN...'
sudo ip link set can0 down

echo 'setting bitrate 500000 and turning loopback OFF'
sudo ip link set can0 type can bitrate 500000 loopback off

echo 'setting can0 UP'
sudo ip link set can0 up

echo 'candump is running (ctrl+c to exit)'
candump can0

# no exit 0 because candump runs until process is terminated
