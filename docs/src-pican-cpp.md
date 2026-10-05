# Pican c++ file

### `SocketCANDevice` object
- constructor takes 1 parameter, a `string` for the can bus name, ex `SocketCANDevice can("can0")`;
- The constructor will create a socket for raw CAN, and then binds it to the CAN interface. Runtime errors with descriptions will be thrown if a failure occurs.

### `can_frame` struct (included with socketCAN)
- `can_id`: gives the can ID (1 `uint32_t`)
- `len` (or .`can_dlc`) gives the length of the data packet array (`uint8_t`)
- `data` gives an array with up to 8 `uint8_t` in it. 

### `readCANMessage()`
- Parameter: a `can_frame` struct that will be populated after the function is called.
- Returns: `true` if message is read properly, `false` if there is an error while trying to read the CAN message

### `writeCANMessage()`
- Parameter: a `can_frame` struct that will be written to the CAN bus. (Unlike for read, this one must be prepopulated with data to send to the CAN bus.)

- Returns: `true` if message writes properly, `false` if there is an error while trying to write the CAN message.

### `main()` function

The version currently present on github sends 100 CAN messages and tests if it can read the messages it wrote on loopback mode.

this version is used to test reading on an actual CAN setup:

```cpp
int main(){
  while(true){
    can_frame frame{};
    if (can.readCANMessage(frame)) {
      printf("ID: 0x%03X  len: %d  Data:",
        frame.can_id & CAN_SFF_MASK,
        frame.len);

      for (int i = 0; i < frame.len; ++i) {
        printf(" %02X", frame.data[i]);
      }
        printf("\n");
      }
    }
  }
}
```
