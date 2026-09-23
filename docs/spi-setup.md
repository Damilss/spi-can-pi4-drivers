## Overview

This document covers how to setup SPI interfect on an PI 4/5. Please complete all
the steps and refer to other documentation

> [!WARNING]
> if you are going through `can0-setup.md` or are going to, you can skip this document ENTIRELY! DO NOT FOLLOW THESE INSTRUCTIONS!

### 1. raspi-config

run `sudo raspi-config`

### 2. select SPI options

  -> Interface Options
      → SPI
          → Yes

### 3. reboot

`sudo reboot`. And you should be all good to go! :)

