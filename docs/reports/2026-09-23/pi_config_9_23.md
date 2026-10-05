Raspberry pi config (CAN overlay)
1. `/boot/firmware/config.txt` (when using CLI can edit with `nano /boot/firmware/config.txt`
2. Enable SPI with `dtparam=spi=on`
3. Apply the CAN overlay with `dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25`
  Even though the chip is technically an `mcp25625`, the library is `mcp2515`
  The schematic says its a 20 mhz crystal but it only worked when we specified 16 mhz for the oscillator (the schematic might        differ from our actual unit)
  Interrupt pin was plugged into GPIO 25, so the interrupt is set to 25 (I believe any GPIO pin will work for the interrupt but 25   is known working)
4.Run `sudo reboot` to reboot the raspberry pi and apply the config.

Enabling CAN
  Run `sudo ip link set can0 up type can bitrate 1000000` to enable a regular (non loopback) can interface with a bitrate of 1 mhz   (that is the max speed of the chip and what the car will use)

Loopback mode test
1. Run the following sequence:
  `sudo ip link set can0 down`
  `sudo ip link set can0 type can bitrate 1000000 loopback on`
  `sudo ip link set can0 up`
2.Make sure you have can-utils installed for easy testing of the CAN bus through the CLI run sudo apt install can-utils to install if necessary
3.Run `candump can0` to tell the terminal to dump whatever values are on CAN bus 0 (this will print the data in that terminal).
4.Open a new terminal to send messages (can’t use the other one because it needs to keep running candump)
5.In the new terminal, send a message such as `cansend can0 001#DEADBEEF`.
6.The sent message should appear twice, meaning it was successfully written to the CAN bus and looped back to receive .
