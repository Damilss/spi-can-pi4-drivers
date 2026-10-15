# Running program on startup

To run cpp program automatically, when the pi boots up you can use different
methods, but doing it through `systemd` would be the best bet

### 1. create a service file

- run `sudo vim /etc/systemd/system/can_reader.service`

**Configuring the service file should look something like this?**
```INI
[Unit]
Description=Raspberry Pi CAN Reader
After=network.target

[Service]
Type=simple
User=cm4
WorkingDirectory=/home/cm4/can-project
ExecStart=/home/cm4/can-project/can_reader
Restart=on-failure
RestartSec=3

[Install]
WantedBy=multi-user.target
```

- save it, then run: 

```
sudo systemctl daemon-reload
sudo systemctl enable --now can-reader.service
```

where can-reader reader is the service service file.

## 2. inspect process status

```
systemctl status can-reader.service
journalctl -u can-reader.service -f
``` 

`journalctl ...` command follows logs in real time


