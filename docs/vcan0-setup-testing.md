# Virtual CAN (vcan0) Setup

A quick guide to configuring a virtual CAN interface on Linux using SocketCAN.

## Overview

`vcan0` is a virtual CAN network interface provided by the Linux kernel. It allows developers to send and receive CAN frames without requiring physical CAN hardware.

Useful for testing CAN applications, debugging, and local development.

## 1. Install Dependencies

Install `can-utils`, which provides utilities for interacting with SocketCAN interfaces.

**Debian / Ubuntu:**

```bash
sudo apt update
sudo apt install can-utils
```

**Fedora:**

```bash
sudo dnf install can-utils
```

## 2. Create the Virtual CAN Interface

Load the virtual CAN kernel module:

```bash
sudo modprobe vcan
```

Create the `vcan0` interface:

```bash
sudo ip link add dev vcan0 type vcan
```

Bring the interface online:

```bash
sudo ip link set vcan0 up
```

Verify that the interface exists:

```bash
ip -details link show vcan0
```

## 3. Test CAN Communication

Open two separate terminals.

**Terminal 1 — Receive CAN frames:**

```bash
candump vcan0
```

**Terminal 2 — Transmit a CAN frame:**

```bash
cansend vcan0 123#DEADBEEF
```

Expected output in Terminal 1:

```text
vcan0  123   [4]  DE AD BE EF
```

Here:
- `123` is the CAN arbitration ID (hexadecimal).
- `DEADBEEF` is the payload (4 bytes).
- `[4]` indicates the payload length (DLC).

## 4. Disable or Remove vcan0

Bring the interface down:

```bash
sudo ip link set vcan0 down
```

Remove the interface entirely:

```bash
sudo ip link delete vcan0
```

## Notes

- `vcan0` uses the Linux SocketCAN networking subsystem.
- No physical CAN controller or transceiver is required.
- Multiple applications can communicate through the same virtual interface.
- Virtual CAN interfaces do not require a bitrate configuration.
- The interface generally needs to be recreated after reboot unless configured for automatic setup.
- `vcan0` simulates CAN frame transmission, but does not reproduce physical CAN bus behavior, timing, arbitration, or electrical errors.

## References

- [Linux Kernel — SocketCAN Documentation](https://docs.kernel.org/networking/can.html)
- [can-utils — GitHub](https://github.com/linux-can/can-utils)
