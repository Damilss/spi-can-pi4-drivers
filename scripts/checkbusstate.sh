#!/bin/bash

# checkbussstate.sh
# shows details and statistics of the can0 bus 

set -euo pipefail

echo 'checking can0 bus state details and errors...'
ip -details -statistics link show can0

exit 0

