# Terminal Logs 2026-10-14

```ps1
Microsoft Windows [Version 10.0.26200.9711]
(c) Microsoft Corporation. All rights reserved.

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Permission denied, please try again.
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 19:28:21 2026 from fe80::1ace:163:186d:5ded%wlan0
brandon@logger:~ $ exit
logout
Connection to logger.local closed.

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Permission denied, please try again.
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 19:53:15 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ exit
logout
Connection to logger.local closed.

C:\Windows\System32>scp -r
usage: scp [-346ABCOpqRrsTv] [-c cipher] [-D sftp_server_path] [-F ssh_config]
           [-i identity_file] [-J destination] [-l limit] [-o ssh_option]
           [-P port] [-S program] [-X sftp_option] source ... target

C:\Windows\System32>scp -r C:\Users\VC\Documents\spi-can-pi4-drivers\src brandon@logger.local
C:\Users\VC\Documents\spi-can-pi4-drivers\src\can.cpp -> C:\Windows\System32\brandon@logger.local\can.cpp
C:\Users\VC\Documents\spi-can-pi4-drivers\src\can.h -> C:\Windows\System32\brandon@logger.local\can.h
C:\Users\VC\Documents\spi-can-pi4-drivers\src\CANTest.cpp -> C:\Windows\System32\brandon@logger.local\CANTest.cpp
C:\Users\VC\Documents\spi-can-pi4-drivers\src\dataIntake.cpp -> C:\Windows\System32\brandon@logger.local\dataIntake.cpp
C:\Users\VC\Documents\spi-can-pi4-drivers\src\dataIntake.h -> C:\Windows\System32\brandon@logger.local\dataIntake.h
5 File(s) copied

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 19:57:15 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ ls
canflash  canrec  canspy  logger  pican.zip  picanzip  uart
brandon@logger:~ $ scp --version
scp: unknown option -- -
usage: scp [-346ABCOpqRrsTv] [-c cipher] [-D sftp_server_path] [-F ssh_config]
           [-i identity_file] [-J destination] [-l limit] [-o ssh_option]
           [-P port] [-S program] [-X sftp_option] source ... target
brandon@logger:~ $ exit
logout
Connection to logger.local closed.

C:\Windows\System32>scp -r C:\Users\VC\Documents\spi-can-pi4-drivers\src brandon@logger.local:~/
brandon@logger.local's password:
can.cpp                                                                               100% 2181   355.0KB/s   00:00
can.h                                                                                 100% 1445   141.1KB/s   00:00
CANTest.cpp                                                                           100% 2416   294.9KB/s   00:00
dataIntake.cpp                                                                        100% 2594   361.9KB/s   00:00
dataIntake.h                                                                          100% 2682   374.2KB/s   00:00

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 19:59:59 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ ls
canflash  canrec  canspy  logger  pican.zip  picanzip  src  uart
brandon@logger:~ $ cd src
brandon@logger:~/src $ ls
can.cpp  can.h  CANTest.cpp  dataIntake.cpp  dataIntake.h
brandon@logger:~/src $ cd ..
brandon@logger:~ $ ls
canflash  canrec  canspy  logger  pican.zip  picanzip  src  uart
brandon@logger:~ $ mkdir spi-can-socketcan
brandon@logger:~ $ ls
canflash  canrec  canspy  logger  pican.zip  picanzip  spi-can-socketcan  src  uart
brandon@logger:~ $ mv -r src spi-can-socketcan/
mv: invalid option -- 'r'
Try 'mv --help' for more information.
brandon@logger:~ $ mv src spi-can-socketcan/
brandon@logger:~ $ cd spi-can-socketcan/
brandon@logger:~/spi-can-socketcan $ ls
src
brandon@logger:~/spi-can-socketcan $ cd src
brandon@logger:~/spi-can-socketcan/src $ g++ --version
g++ (Debian 14.2.0-19) 14.2.0
Copyright (C) 2024 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

brandon@logger:~/spi-can-socketcan/src $ ls -GAF
can.cpp  can.h  CANTest.cpp  dataIntake.cpp  dataIntake.h
brandon@logger:~/spi-can-socketcan/src $ g++ can.cpp  can.
can.cpp  can.h
brandon@logger:~/spi-can-socketcan/src $ g++ -Wall -Wextra -o out CANTest.cpp can.cpp can.
can.cpp  can.h
brandon@logger:~/spi-can-socketcan/src $ g++ -Wall -Wextra -o out CANTest.cpp can.cpp can.h
brandon@logger:~/spi-can-socketcan/src $ ls
can.cpp  can.h  CANTest.cpp  dataIntake.cpp  dataIntake.h  out
brandon@logger:~/spi-can-socketcan/src $ vim /boot/firmware/config.txt
brandon@logger:~/spi-can-socketcan/src $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN group default qlen 10
    link/can
4: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~/spi-can-socketcan/src $ sudo ip link set can0 up type can bitrate 1000000
[sudo] password for brandon:
brandon@logger:~/spi-can-socketcan/src $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: can0: <NOARP,UP,LOWER_UP,ECHO> mtu 16 qdisc pfifo_fast state UP group default qlen 10
    link/can
4: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~/spi-can-socketcan/src $ ./out
^C
brandon@logger:~/spi-can-socketcan/src $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: can0: <NOARP,UP,LOWER_UP,ECHO> mtu 16 qdisc pfifo_fast state UP group default qlen 10
    link/can
4: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~/spi-can-socketcan/src $ ip -details -statistics link show can0
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
brandon@logger:~/spi-can-socketcan/src $ ./out
^C
brandon@logger:~/spi-can-socketcan/src $ vim cantest.cpp
brandon@logger:~/spi-can-socketcan/src $ ls
can.cpp  can.h  CANTest.cpp  dataIntake.cpp  dataIntake.h  out
brandon@logger:~/spi-can-socketcan/src $ vim CANTest.cpp
brandon@logger:~/spi-can-socketcan/src $ ./out
^C
brandon@logger:~/spi-can-socketcan/src $ tmux
-bash: tmux: command not found
brandon@logger:~/spi-can-socketcan/src $ tmux
-bash: tmux: command not found
brandon@logger:~/spi-can-socketcan/src $ ./out
^C
brandon@logger:~/spi-can-socketcan/src $ vim CANTest.cpp
brandon@logger:~/spi-can-socketcan/src $ ip -details -statistics link show can0\
>
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
brandon@logger:~/spi-can-socketcan/src $ ./out
^C
brandon@logger:~/spi-can-socketcan/src $ ^C
brandon@logger:~/spi-can-socketcan/src $ socketcan --help
-bash: socketcan: command not found
brandon@logger:~/spi-can-socketcan/src $ socketcan --help
-bash: socketcan: command not found
brandon@logger:~/spi-can-socketcan/src $ ./out
^C
brandon@logger:~/spi-can-socketcan/src $ ip -details -statistics link show can0\
>
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
brandon@logger:~/spi-can-socketcan/src $ view /boot/firmware/config.txt
brandon@logger:~/spi-can-socketcan/src $ ip -details -statistics link show can0\
>
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
brandon@logger:~/spi-can-socketcan/src $ view /boot/firmware/config.txt
brandon@logger:~/spi-can-socketcan/src $ client_loop: send disconnect: Connection reset

C:\Windows\System32>ssh brandon@logger.local
ssh: Could not resolve hostname logger.local: No such host is known.

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 20:01:28 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~ $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~ $ sudo ip link set can0 type can bitrate 1000000 loopback off
[sudo] password for brandon:
Sorry, try again.
[sudo] password for brandon:
Cannot find device "can0"
brandon@logger:~ $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~ $ vim /boot/firmware/config.txt
brandon@logger:~ $ sudo reboot now
brandon@logger:~ $ Connection to logger.local closed by remote host.
Connection to logger.local closed.

C:\Windows\System32>ssh brandon@logger.local
ssh: Could not resolve hostname logger.local: No such host is known.

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Permission denied, please try again.
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 20:35:14 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~ $ vim /boot/firmware/config.txt
brandon@logger:~ $ brandon@logger:~ $ dmesg | grep - mcp251x
grep: mcp251x: No such file or directory
brandon@logger:~ $ dmesg | grep -i mcp251x
[    6.697836] mcp251x spi0.0: MCP251x didn't enter in conf mode after reset
[    6.697922] mcp251x spi0.0: Probe failed, err=110
[    6.697930] mcp251x spi0.0: probe with driver mcp251x failed with error -110
brandon@logger:~ $ ls /dev/spidev*
/dev/spidev0.1
brandon@logger:~ $ sudo raspi-config
[sudo] password for brandon:
brandon@logger:~ $ view /boot/firmware/config.txt
brandon@logger:~ $ ip link show can0
Device "can0" does not exist.
brandon@logger:~ $ sudo dmesg | grep -iE 'mcp251|spi'
[    6.697836] mcp251x spi0.0: MCP251x didn't enter in conf mode after reset
[    6.697922] mcp251x spi0.0: Probe failed, err=110
[    6.697930] mcp251x spi0.0: probe with driver mcp251x failed with error -110
[  851.895658] OF: overlay: WARNING: memory leak will occur if overlay removed, property: /soc/spi@7e204000/status
[  859.730869] OF: overlay: WARNING: memory leak will occur if overlay removed, property: /soc/spi@7e204000/status
brandon@logger:~ $ client_loop: send disconnect: Connection reset

C:\Windows\System32>ssh brandon@logger.local
ssh: Could not resolve hostname logger.local: No such host is known.

C:\Windows\System32>ssh brandon@logger.local
ssh: Could not resolve hostname logger.local: No such host is known.

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 20:41:59 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN group default qlen 10
    link/can
4: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~ $ sudo ip link set can0 type can bitrate 1000000
[sudo] password for brandon:
brandon@logger:~ $ candump can0
read: Network is down
brandon@logger:~ $ ip -details -statistics link show can0
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN mode DEFAULT group default qlen 10
    link/can  promiscuity 0 allmulti 0 minmtu 16 maxmtu 16
    can state STOPPED restart-ms 0
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
brandon@logger:~ $ ls
canflash  canrec  canspy  logger  pican.zip  picanzip  spi-can-socketcan  uart
brandon@logger:~ $ cd spi-can-socketcan
brandon@logger:~/spi-can-socketcan $ ls
src
brandon@logger:~/spi-can-socketcan $ cd src
brandon@logger:~/spi-can-socketcan/src $ ls
can.cpp  can.h  CANTest.cpp  dataIntake.cpp  dataIntake.h  out
brandon@logger:~/spi-can-socketcan/src $ ./out
readCANMessage(): Error while trying to read can message: Network is down
^C
brandon@logger:~/spi-can-socketcan/src $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN group default qlen 10
    link/can
4: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~/spi-can-socketcan/src $ sudo ip link set can0 type can bitrate 1000000
brandon@logger:~/spi-can-socketcan/src $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN group default qlen 10
    link/can
4: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~/spi-can-socketcan/src $ sudo ip link set can0 up
RTNETLINK answers: Connection timed out
brandon@logger:~/spi-can-socketcan/src $ sudo ip link set can0 type can bitrate 1000000
brandon@logger:~/spi-can-socketcan/src $ sudo ip link set can0 up
RTNETLINK answers: Connection timed out
brandon@logger:~/spi-can-socketcan/src $ ip addr shwo
Command "shwo" is unknown, try "ip address help".
brandon@logger:~/spi-can-socketcan/src $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN group default qlen 10
    link/can
4: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~/spi-can-socketcan/src $ sudo ip link set can0 up type can bitrate 1000000
RTNETLINK answers: Connection timed out
brandon@logger:~/spi-can-socketcan/src $ sudo dmesg | tail -n 30
[    6.447555] vc4-drm gpu: bound fe20a000.pixelvalve (ops vc4_crtc_ops [vc4])
[    6.447705] vc4-drm gpu: bound fe216000.pixelvalve (ops vc4_crtc_ops [vc4])
[    6.448014] vc4-drm gpu: bound fec12000.pixelvalve (ops vc4_crtc_ops [vc4])
[    6.456227] [drm] Initialized vc4 0.0.0 for gpu on minor 0
[    6.457108] vc4-drm gpu: [drm] Cannot find any crtc or sizes
[    6.462564] vc4-drm gpu: [drm] Cannot find any crtc or sizes
[    6.464015] vc4-drm gpu: [drm] Cannot find any crtc or sizes
[    6.656664] brcmfmac: brcmf_c_process_txcap_blob: no txcap_blob available (err=-2)
[    6.657058] brcmfmac: brcmf_c_preinit_dcmds: Firmware: BCM4345/6 wl0: Aug 29 2023 01:47:08 version 7.45.265 (28bca26 CY) FWID 01-b677b91b
[    6.991746] Bluetooth: hci0: BCM: features 0x2f
[    6.993015] Bluetooth: hci0: BCM43455 37.4MHz Raspberry Pi 3+-0190
[    6.993024] Bluetooth: hci0: BCM4345C0 (003.001.025) build 0382
[    8.722771] Bluetooth: BNEP (Ethernet Emulation) ver 1.3
[    8.722790] Bluetooth: BNEP filters: protocol multicast
[    8.722804] Bluetooth: BNEP socket layer initialized
[    8.748986] Bluetooth: MGMT ver 1.23
[    8.767445] NET: Registered PF_ALG protocol family
[    8.961780] Bluetooth: RFCOMM TTY layer initialized
[    8.961807] Bluetooth: RFCOMM socket layer initialized
[    8.961825] Bluetooth: RFCOMM ver 1.11
[   11.139647] bcmgenet fd580000.ethernet: configuring instance for external RGMII (RX delay)
[   11.140350] bcmgenet fd580000.ethernet eth0: Link is Down
[   11.172419] brcmfmac: brcmf_cfg80211_set_power_mgmt: power save enabled
[  212.364585] can: controller area network core
[  212.364692] NET: Registered PF_CAN protocol family
[  212.382751] can: raw protocol
[  381.203052] mcp251x spi0.0: MCP251x didn't enter in config mode
[  395.275049] mcp251x spi0.0: MCP251x didn't enter in config mode
[  506.559061] mcp251x spi0.0: MCP251x didn't enter in config mode
[  506.559183] A link change request failed with some changes committed already. Interface can0 may have been left with an inconsistent configuration, please check.
brandon@logger:~/spi-can-socketcan/src $ ip -details link show can0
3: can0: <NOARP,ECHO> mtu 16 qdisc noop state DOWN mode DEFAULT group default qlen 10
    link/can  promiscuity 0 allmulti 0 minmtu 16 maxmtu 16
    can state STOPPED restart-ms 0
          bitrate 1000000 sample-point 0.750
          tq 125 prop-seg 2 phase-seg1 3 phase-seg2 2 sjw 1 brp 1
          mcp251x: tseg1 3..16 tseg2 2..8 sjw 1..4 brp 1..64 brp_inc 1
          clock 8000000 numtxqueues 1 numrxqueues 1 gso_max_size 65536 gso_max_segs 65535 tso_max_size 65536 tso_max_segs 65535 gro_max_size 65536 gso_ipv4_max_size 65536 gro_ipv4_max_size 65536 parentbus spi parentdev spi0.0
brandon@logger:~/spi-can-socketcan/src $ /boot/firmware/config.txt
/boot/firmware/config.txt: line 46: [cm4]: command not found
/boot/firmware/config.txt: line 52: [cm5]: command not found
/boot/firmware/config.txt: line 55: [pi5]: command not found
/boot/firmware/config.txt: line 58: [all]: command not found
brandon@logger:~/spi-can-socketcan/src $ vim /boot/firmware/config.txt
brandon@logger:~/spi-can-socketcan/src $ sudo vim /boot/firmware/config.txt
brandon@logger:~/spi-can-socketcan/src $ sudo reboot
brandon@logger:~/spi-can-socketcan/src $ client_loop: send disconnect: Connection reset

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Permission denied, please try again.
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 21:02:37 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~ $ /boot/firmware/config.txt
/boot/firmware/config.txt: line 46: [cm4]: command not found
/boot/firmware/config.txt: line 52: [cm5]: command not found
/boot/firmware/config.txt: line 55: [pi5]: command not found
/boot/firmware/config.txt: line 58: [all]: command not found
brandon@logger:~ $ sudo vim /boot/firmware/config.txt
[sudo] password for brandon:
brandon@logger:~ $ sudo reboot
brandon@logger:~ $ client_loop: send disconnect: Connection reset

C:\Windows\System32>ssh brandon@logger.local
brandon@logger.local's password:
Linux logger 6.18.50+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.18.50-1+rpt1 (2026-09-11) aarch64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Wed Sep 30 21:15:22 2026 from fe80::7a:bbc6:5a40:ec4d%wlan0
brandon@logger:~ $ ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host noprefixroute
       valid_lft forever preferred_lft forever
2: eth0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc mq state DOWN group default qlen 1000
    link/ether 98:fe:54:1b:19:7e brd ff:ff:ff:ff:ff:ff
3: wlan0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 98:fe:54:1b:19:7f brd ff:ff:ff:ff:ff:ff
    inet 10.42.0.1/24 brd 10.42.0.255 scope global noprefixroute wlan0
       valid_lft forever preferred_lft forever
    inet6 fe80::9afe:54ff:fe1b:197f/64 scope link proto kernel_ll
       valid_lft forever preferred_lft forever
brandon@logger:~ $ client_loop: send disconnect: Connection reset

```
