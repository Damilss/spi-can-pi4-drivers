# Raspberry Pi Wi-Fi Cheat Sheet

A quick reference for connecting to Wi-Fi from the terminal with `nmcli`.

---

## Check Your Wi-Fi Device

See available network interfaces:

```bash
nmcli device status
```

Your Raspberry Pi's built-in Wi-Fi interface is usually:

```text
wlan0
```

Make sure Wi-Fi is enabled:

```bash
nmcli radio wifi on
```

---

## Scan for Wi-Fi Networks

```bash
nmcli device wifi list
```

You can also force a new scan:

```bash
nmcli device wifi rescan
nmcli device wifi list
```

---

# Normal WPA2 / WPA3 Wi-Fi

For a normal Wi-Fi network that uses one shared password:

```bash
sudo nmcli device wifi connect "SSID" password "PASSWORD"
```

Example:

```bash
sudo nmcli device wifi connect "MyHomeWiFi" password "my-password"
```

NetworkManager will normally save the connection and reconnect automatically after reboot.

Check that it was saved:

```bash
nmcli connection show
```

Check whether autoconnect is enabled:

```bash
nmcli connection show "MyHomeWiFi" | grep autoconnect
```

If needed:

```bash
sudo nmcli connection modify "MyHomeWiFi" connection.autoconnect yes
```

---

# eduroam / WPA-Enterprise

eduroam uses **802.1X authentication** instead of one shared Wi-Fi password.

For Cal Poly, the important settings are:

```text
SSID:             eduroam
Key management:   WPA-EAP
EAP method:       PEAP
Phase 2 auth:     MSCHAPv2
Identity:         your Cal Poly email
```

## 1. Create the Connection

```bash
sudo nmcli connection add \
    type wifi \
    ifname wlan0 \
    con-name eduroam \
    ssid eduroam
```

Where:

```text
ifname     = interface name
wlan0      = Raspberry Pi Wi-Fi interface
con-name   = NetworkManager profile name
ssid       = actual Wi-Fi network name
```

## 2. Configure 802.1X Authentication

```bash
sudo nmcli connection modify eduroam \
    wifi-sec.key-mgmt wpa-eap \
    802-1x.eap peap \
    802-1x.phase2-auth mschapv2 \
    802-1x.identity "USERNAME@calpoly.edu"
```

Example:

```bash
sudo nmcli connection modify eduroam \
    wifi-sec.key-mgmt wpa-eap \
    802-1x.eap peap \
    802-1x.phase2-auth mschapv2 \
    802-1x.identity "escott15@calpoly.edu"
```

Do **not** use:

```text
wpa-peap
```

The correct key-management value is:

```text
wpa-eap
```

`PEAP` is specified separately with:

```bash
802-1x.eap peap
```

## 3. Connect and Enter Your Password

Use `--ask` so your password is prompted for instead of being typed directly into your shell command:

```bash
sudo nmcli --ask connection up eduroam
```

Enter your Cal Poly password when prompted.

---

# Check Your Current Connection

```bash
nmcli device status
```

Example:

```text
DEVICE  TYPE      STATE      CONNECTION
wlan0   wifi      connected  eduroam
eth0    ethernet  connected  Wired connection 1
lo      loopback  connected  lo
```

See active connections:

```bash
nmcli connection show --active
```

See the IP address assigned to Wi-Fi:

```bash
ip addr show wlan0
```

---

# Disconnect Wi-Fi

```bash
sudo nmcli device disconnect wlan0
```

Reconnect:

```bash
sudo nmcli device connect wlan0
```

Or bring up a specific saved profile:

```bash
sudo nmcli connection up "PROFILE_NAME"
```

Examples:

```bash
sudo nmcli connection up "MyHomeWiFi"
sudo nmcli connection up eduroam
```

---

# Saved Networks

List all saved NetworkManager profiles:

```bash
nmcli connection show
```

Delete a saved profile:

```bash
sudo nmcli connection delete "PROFILE_NAME"
```

Example:

```bash
sudo nmcli connection delete eduroam
```

---

# Quick Reference

Normal Wi-Fi:

```bash
sudo nmcli device wifi connect "SSID" password "PASSWORD"
```

eduroam:

```bash
sudo nmcli connection add type wifi ifname wlan0 con-name eduroam ssid eduroam

sudo nmcli connection modify eduroam \
    wifi-sec.key-mgmt wpa-eap \
    802-1x.eap peap \
    802-1x.phase2-auth mschapv2 \
    802-1x.identity "USERNAME@calpoly.edu"

sudo nmcli --ask connection up eduroam
```

Check status:

```bash
nmcli device status
```

---

`nmcli` = **NetworkManager Command-Line Interface**
