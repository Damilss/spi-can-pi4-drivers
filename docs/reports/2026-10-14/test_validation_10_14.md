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

## Conclusion

## Next steps


## Attachments / References

