# 10-14: Test validation

**Authors:** Emilio Ledesma, Thomas Baltz, Isaiah Rivera, Trevor Choy
**Status**: Partial
**Related docs:** All of it lol

> Note: tests were ran in `test` branch

## Goal 

Verify that the PI is able to read and write data through a full CAN bus, 
connected to the MCP25625 IC and a Pedalbox

## Setup

<Thomas if you could enter what went down on your end on the CAN end>

**for Raspberry pi 4B:**
- Configure `/boot/firmware/config.txt` on the Raspberry Pi 4 B, but it was configured
- set network interface up by running: `sudo ip link set can0 type can bitrate 1000000 loopback on`
- set can0 to up: `sudo ip link set can0 up`
- cd to src, compile all the programs, and then run program and wait for prints

## Expected results

When everything is configured, the segment in CANtest.cpp should run:

```cpp
printf("ID: 0x%03X  len: %d  timestamp: %" PRIu64 ", Data:",
E                         frame.can_id & CAN_SFF_MASK,
                          frame.len,
                          timestamp);

                          for (int i = 0; i < frame.len; ++i) {
                                  printf(" %02X", frame.data[i]);
                          }
```

## Actual results

We had Hardware MCP25625 IC <--> PI issues

7pm we had everything setup. but at some point the network interface "can0"  on the PI disappeared after no changes between the IC and the PI. After going through extensive troubleshooting came down to faulty jumper wires.

We changed jumper wires and can0 network interface reappeared but when trying to set the status to "UP" for can0, it failed.

We tried more troubleshooting and research we tried changing the oscillator frequency from 16mhz to 20 mhz. testing with loopback mode in the past (sept 23) succeeded on 16mhz but schematic states 20mhz. after switching to 20mhz,  the can0 network interface disappeared again. We switch backed to 16mhz from 20mhz and the can0 was still gone again. The issue isn't clear. We have terminal logs and everything to test before monday, we will do more research and hopefully resolve this before Monday

On a semi-positive positive note, the independent drivers we created were able to catch one of the errors as it it tried to READ. meaning that our drivers initialize and successfully and independently creates and binds the socket in the way that we want. After more research, there isn't any way our software could be an issue from this as well.

The most eccentric part of this all is after merely changing the oscillator frequency value, the whole interface disappeared. and when we changed it back to 16mhz it still was gone. That is really what's throwing me off and it seems to me it has to be something with the hardware.

## Issues / Observations

When we first connected to the PI, we were able to set the ```can0``` network to up, as confirmed by this message:
```
3: can0: <NOARP,UP,LOWER_UP,ECHO> mtu 16 qdisc pfifo_fast state UP group default qlen 10
    link/can
```

The module was connected to the pedalbox can board, which we are pretty sure was outputting can messages, it is unlikely that the other board is at fault. running our test program produced no messages, as the ```readCANMessage()``` function never detected any CAN messages.

we then tried to dump the CAN straight from the terminal (bypassing our c++ library), and it showed that no messages were recieved:
```
3: can0: <NOARP,UP,LOWER_UP,ECHO> mtu 16 qdisc pfifo_fast state UP mode DEFAULT group default qlen 10
    link/can  promiscuity 0 allmulti 0 minmtu 16 maxmtu 16
    can state ERROR-ACTIVE restart-ms 0
          bitrate 1000000 sample-point 0.750
          tq 125 prop-seg 2 phase-seg1 3 phase-seg2 2 sjw 1 brp 1
          mcp251x: tseg1 3..16 tseg2 2..8 sjw 1..4 brp 1..64 brp_inc 1
          clock 8000000
          re-started bus-errors arbit-lost error-warn error-pass bus-off
          0          0          0          0          0          0         numtxqueues 1 numrxqueues 1 gso_max_size 65536 gso_max_segs 65535 tso_max_size 65536 tso_max_segs 65535 gro_max_size 65536 gso_ipv4_max_size 65536 gro_ipv4_max_size 65536 parentbus spi parentdev spi0.0
    RX:  bytes packets errors dropped  missed   mcast
             0       0      0       0       0       0
    TX:  bytes packets errors dropped carrier collsns
             0       0      0       0       0       0
```

it then disconnected somehow ```brandon@logger:~/spi-can-socketcan/src $ client_loop: send disconnect: Connection reset```

and when we re-sshed, the ```can0``` network would not show up when running ```ip addr show```.

GPT says based on the terminal that it is likely a hardware fault instead of a software one. This seems accurate considering the issue would go away and then reappear. GPT also noted that the board could potentially drive pi MISO at 5V, which would mess stuff up and potentially damage the pi, but seems unlikely since loopback mode worked in the past.

GPT also recommended a full powercycle after configs are changed, in our testing we had just been using ```sudo reboot```.

Note that this GPT stuff was done after our testing and output was generated from our terminal.

We came to the conclusion that faulty jumpers could be a problem, we performed a full rewire that allowed the ```can0``` network to show up when running ```ip addr show```.

It is worth noting that during the rewire, the pi was unplugged, meaning that turning it back on was effectively a full power cycle. We thought that the full rewire had fixed something due to faulty jumpers, but the continuity of every jumper wire used was confirmed with a multimeter after the tests. The breadboards have not been tested, as those could also be a potential point of failure.

we were then met with this response displaying that the ```can0``` network exists:
```
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN group default qlen 10
link/can
```
along with other unrelated networks.

We then tried to set the ```can0``` network to ```up``` by running ```brandon@logger:~/spi-can-socketcan/src $ sudo ip link set can0 up```.
and were met with this response ```RTNETLINK answers: Connection timed out```, showing that attempting to put the can network up failed.

We then decided to test if setting the crystal to 20 mhz instead of 16 mhz would solve the issue, as the schematic describes the oscillator in the chip as 20 mhz. We modified the ```/boot/firmware/config.txt``` and ran ```sudo reboot``` to apply the config. After this, ```ip addr show``` did not display the ```can0``` network anymore.

After that failed we decided to set the oscillator back to 16 mhz in the config, as that had worked in loopback mode. we once again ran ```sudo reboot``` after modifying the config, and once again ```ip addr show``` did not display the ```can0``` network. We never got the ```can0``` network to display again.

## Conclusion

## Next steps


## Attachments / References

