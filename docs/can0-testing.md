## Overview

This document covers how to test can0, and should come after `./docs/can0-setup.md`
Please follow all steps in this document and refer to other applicable
documentation.

(It would also be smart to look at what all of these commands do exactly,
feel free to take a peek) 

### 1. MAKE SURE YOU'VE SETUP can0

If you haven't gone through `./docs/can0-setup.md`, make sure to do so

### 2. Test in loopback mode

run `scripts/can0-testing/loopback-test.sh`.

**NOTE**: You will need have **TWO** windows. If you don't know how to do that, look it up... (I use tmux) 

then in a separate window, 

run `sendcanframe.sh`

You should see the frame echoed back by `candump` in the first window you opened
if it worked.
### 3. systemd-networkd configuration (making can0 config persistent)
**SIDE NOTE:** Modern Raspberry Pi OS uses `NetworkManager` as it's **primary**
    network manager instead of  `systemd-networkd`. make sure that can0 is
    unmanaged by `NetworkManager`.
    
    *To check:*
    - run `scripts/check-active-networkmanagers.sh`
    
    see what is active, if `NetworkManager` is active alongside systemd-networkd,
    make sure can0 is unmanaged by `NetworkManager`. 
    - run `nmcli device status` to see what `NetworkManager` is running
    it should say "unmanaged" by nmcli

run `scripts/systemd-networkd-config.sh` to configure and enable can0 in
`systemd-networkd`. This makes the config persistent.

### troubleshooting (PARTS 1-3)
1. MCP251x didn't enter in conf mode after reset / probe failed
The Pi can't talk to the chip over SPI. This usually points to a hardware or wiring problem. Check:
    - MOSI and MISO aren't swapped.
    - CS is on CE0 and secure
    - VIO has 3.3 V.
    - RESET isn't held low

2. can0 exists, but loopback shows nothing in candump
The interrupt isn't reaching the Pi. Check that INT goes to GPIO25, or that interrupt= matches the pin you actually used.

3. Garbage or error frames on a real bus
    - The `Ocillator=` value doesn't match the crystal, so every bit timing is off

4. TX error counter climbs, state goes from ERROR-PASSIVE or BUS-OFF; check:
    - STBY is actually low
    - at least one other node is on thebust
    - the Bus is terminated and terminated correctly
    - CANH and CANL aren't accidently swapped (happens)

**to see the bus state and error counters RUN:**

```sh
scripts/checkbusstate.sh 
```

### testing (no loopback mode)

run `scripts/can0-testing/test.sh`

**NOTE:** You will need to have *TWO* windows open.

then in a seperate window `scripts/can0-testing/sendcanframe.sh`

### What is what is the difference between having loopback mode on VS. off?

With loopback on, when your system sends a CAN frame on can0, the 
kernel/controller can make that frame appear as if it were received locally. 
it's useful for testing software without needing another CAN node or even,
in some setups, a fully functioning physical bus.

with loopback off, transmitted frames are expected to go out onto the actual CAN
bus. Your system will only receive frames that come back from the real bus
through the CAN controller/transceiver.

Loopback mode is mainly for testing when you don’t have a complete physical CAN
bus available. It lets the CAN controller behave as though a transmitted frame
made the round trip through the controller and was received back locally.

### getting intterupts

run `scripts/can0-testing.sh/checkinterrupts.sh` to check interrupts

You'll get something like 

```sh 
51:          0          0          0          0  ...  spi0
```

/proc/interrupts is roughly structered like:
```sh
IRQ:   CPU0   CPU1   CPU2   CPU3   interrupt-controller ... device
```
- **CPU0-3 is where the interrupts appear**

if nothing returns, it usually means there is currently no interrupt entry whose name contains spi0`

**this happens when**:
- the SPI controller/driver is not loaded
- SPI is disabled
- the kernel names the interrupt something other than spi0
- that SPI controller does not currently have an IRQ registered
- you're grepping for the wrong device label

Check for interrupts if you're having issue with anything!!
