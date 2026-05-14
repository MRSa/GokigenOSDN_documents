# AirA01d: Android Application for OLYMPUS AIR A01

---

- [AirA01d: Android Application for OLYMPUS AIR A01](#aira01d-android-application-for-olympus-air-a01)
  - [Overview](#overview)
  - [Compatible Cameras](#compatible-cameras)
  - [Installation](#installation)
  - [Basic Operations](#basic-operations)
    - [Connecting to the Camera](#connecting-to-the-camera)
    - [Shooting](#shooting)
    - [Changing Settings](#changing-settings)
    - [Exiting the App](#exiting-the-app)
  - [Shooting Screen](#shooting-screen)
    - [Screen Layout](#screen-layout)
    - [Camera Connection Button](#camera-connection-button)
    - [Wi-Fi Settings Button](#wi-fi-settings-button)
    - [Camera Settings Button (Currently Unused)](#camera-settings-button-currently-unused)
    - [App Settings Button](#app-settings-button)
    - [Grid Display Toggle Button](#grid-display-toggle-button)
    - [Power Off Button](#power-off-button)
    - [Camera Status Area](#camera-status-area)
    - [Self-Timer](#self-timer)
    - [Camera Battery Status](#camera-battery-status)
    - [Live View Display](#live-view-display)
    - [Shooting Mode Button](#shooting-mode-button)
    - [Shutter Speed / Aperture / Exposure Compensation](#shutter-speed--aperture--exposure-compensation)
    - [Mirror Mode Toggle Button](#mirror-mode-toggle-button)
    - [Live View Magnification Button](#live-view-magnification-button)
    - [White Balance Button](#white-balance-button)
    - [Picture Mode Button](#picture-mode-button)
    - [Metering Mode Button](#metering-mode-button)
  - [App Settings Screen](#app-settings-screen)
    - [Auto-Connect to Camera](#auto-connect-to-camera)
    - [Instructions](#instructions)
    - [Privacy Policy](#privacy-policy)
  - [Others](#others)
    - [Notes \& Precautions](#notes--precautions)
    - [Permissions](#permissions)
    - [Change Log](#change-log)
    - [Source Code](#source-code)

---

## Overview

AirA01d is an Android application designed for the [Open Platform Camera OLYMPUS AIR A01](https://www.olympus-global.com/en/news/2015a/nr150205opce.html). It allows you to connect to and shoot with the OLYMPUS AIR camera directly from your smartphone.

Unlike [AirA01a](https://play.google.com/store/apps/details?id=jp.osdn.gokigen.aira01a&hl=en) or [AirA01b](https://play.google.com/store/apps/details?id=jp.osdn.gokigen.aira01b&hl=en), this app does not use the [Olympus Camera Kit](https://web.archive.org/web/20210204200324/https://dl-support.olympus-imaging.com/opc/files/en/OlympusCameraKit_EN.zip "Olympus Camera Kit"). Instead, it was developed by referring directly to the communication protocols. Consequently, it supports the **Genius Shooting Mode**, which is not supported by the official Olympus Camera Kit.

![AirA01d](images/AirA01d.png)

---

## Compatible Cameras

- [OLYMPUS AIR A01 (Press Release)](https://www.olympus-global.com/en/news/2015a/nr150205opce.html)
- [AIR A01 Support Topics](https://learnandsupport.getolympus.com/support/air-a01)

---

## Installation

(To be added later)

---

## Basic Operations

![撮影画面](images/screen1.png)

### Connecting to the Camera

When the app starts, it attempts to connect to the camera via Wi-Fi. (This can be disabled in the App Settings.)
Once successful, the camera is set to shooting mode, and the live image is displayed.

If the connection fails, a dialog will appear allowing you to open the "Wi-Fi Settings" or retry the connection. If you are not already connected to the camera's Wi-Fi, use this opportunity to go to the Wi-Fi settings and select the camera's SSID.

![connect fail dialog](images/connect_failed.png)

The Camera Connection icon changes based on the connection status:

![connection statuses](images/connect_transition.png)

The Wi-Fi Settings icon will animate while the app is receiving image data from the camera. Use the connection icon to judge whether data is being transmitted correctly.

### Shooting

Tapping on the Live View area in Auto Focus mode will set the focus to that specific point.

Press the Shutter Button to capture an image. You can also use the **Volume Up** button on your device as a shutter trigger, which allows for remote shooting using Bluetooth shutter remotes.

Live View features include grid overlays, mirror display (horizontal flip), and the ability to hide/show shooting parameters by swiping up or down in landscape mode.

![live view](aira01d_layout_2.png)

### Changing Settings

Tapping a button on the screen queries the camera for available options and displays them in a list. Selecting an option sends the corresponding command to the camera to update the setting.
*(Note: Some buttons may not respond if the current shooting mode restricts that setting or if no options are available.)*

![change setting](images/change_property.png)

### Exiting the App

To turn off the camera and exit the app, use the Power Off button. A confirmation dialog will appear; select OK to shut down both the app and the camera.

![app exit](images/exit_application.png)

---

## Shooting Screen

### Screen Layout

![screen layout](aira01d_layout.png)

The button layout adjusts slightly between portrait and landscape orientations.

- **①: Camera Connection**
- **②: Wi-Fi Settings**
- **③: (Currently Unused)**
- **④: App Settings**
- **⑤: Grid Toggle**
- **⑥: Power Off**
- **⑦: Camera Status**
- **⑧: Self-Timer**
- **⑨: Camera Battery Status**
- **⑩: Live View Display**
- **a: Shooting Mode**
- **b: Shutter Speed**
- **c: Aperture Value**
- **d: Shooting Result (Playback)**
- **e: Shutter Button**
- **f: Exposure Compensation**
- **g: Mirror Mode Toggle**
- **h: Live View Zoom**
- **k: ISO Sensitivity**
- **m: White Balance**
- **n: Picture Mode**
- **p: AE Lock/Unlock**
- **q: Metering Mode**
- **r: Drive Mode**
- **s: Focus Mode (AF/MF)**
- **t: AF Unlock / Center Focus**
- **u: (Currently Unused)**
- **w: Aspect Ratio**
- **x: RAW Mode ON/OFF**
- **y: Lens Distance / Power Zoom Control**

### Camera Connection Button

Connects/disconnects the camera. The icon reflects the current status.

![connect transition](images/connect_transition.png)

### Wi-Fi Settings Button

Opens the Android Wi-Fi settings. Animates when receiving a Live View stream.

### Camera Settings Button (Currently Unused)

Reserved for a future "Camera Settings" screen.

### App Settings Button

Opens the App Settings screen described below.

### Grid Display Toggle Button

Toggles the grid overlay on the Live View screen.

### Power Off Button

Powers down the camera and exits the app after a confirmation dialog.

![exit app](images/exit_application.png)

### Camera Status Area

Displays the camera's operational status:

- **Exposure Warning**: Indicates if the image is too dark or too bright.
- **Recording**: Displays when an image is being written to the microSD card.
- **Shooting**: Indicates active shooting in continuous or movie mode.

### Self-Timer

Toggles between "Off," "3s," "5s," and "10s." Pressing during countdown cancels the timer.

![self timer](images/self_timer.png)

### Camera Battery Status

Displays battery level in three stages (Full, Mid, Low/Empty).

### Live View Display

Displays the real-time feed from the camera.

### Shooting Mode Button

Selects the exposure mode:

- **iAuto**: Camera automatically detects the scene and applies optimal settings.
- **P (Program)**: Camera automatically sets shutter speed and aperture.
- **A (Aperture Priority)**: You set the aperture; camera sets the shutter speed.
- **S (Shutter Priority)**: You set the shutter speed; camera sets the aperture.
- **M (Manual)**: You manually set both aperture and shutter speed.
- **ART (Art Filter)**: Applies Olympus signature artistic filters.
- **movie**: Video recording mode.
- **Genius**: Automatically generates 6 different shots (7 if RAW is ON) with varying framing, colors, and effects in one shutter release.

### Shutter Speed / Aperture / Exposure Compensation

Displays current values and allows changes when applicable.

### Mirror Mode Toggle Button

Flips the Live View horizontally. Useful for selfies.

### Live View Magnification Button

Cycles magnification through: 5x → 7x → 10x → 14x → 1x (Off).

![live view magnification](images/lv_zoom.png)

### White Balance Button

- **Auto WB**: Default for most scenes.
- **Daylight / Shade / Cloudy / Tungsten / Fluorescent / Underwater**: Preset profiles for specific lighting.
- **Custom WB**: Manual setting (Default: 5400K).

### Picture Mode Button

Sets the finishing style (i-Enhance, Vivid, Natural, Muted, Portrait, Monotone, e-Portrait, Color Creator, and various Art Filters).

### Metering Mode Button

- **ESP**: Multi-pattern metering (324 zones).
- **Ctr-Weighted**: Center-weighted average.
- **Spot**: Meters a small area (approx. 2%) at the center.

![Metering mode](images/ae_mode.png)

---

## App Settings Screen

Configures app behavior. Tap "Back" to return to the shooting screen.

![App settings](images/app_settings.png)

### Auto-Connect to Camera

If ON (default), the app automatically connects to the camera if Wi-Fi is detected at startup.

### Instructions

[Opens this documentation page.](https://github.com/MRSa/GokigenOSDN_documents/blob/main/Applications/AirA01d/ReadmeJa.md)

### Privacy Policy

Displays the GOKIGEN project's [Privacy Policy(Japanese)](https://github.com/MRSa/GokigenOSDN_documents/blob/main/PrivacyPolicy.md).

---

## Others

### Notes & Precautions

* **Connection Stability**: Rapidly tapping buttons may overwhelm the camera's processing, leading to instability. It is recommended to wait for the camera to respond before the next action.

### Permissions

The app requires the following permissions:

* `ACCESS_NETWORK_STATE`, `ACCESS_WIFI_STATE`, `ACCESS_LOCAL_NETWORK`, `INTERNET`: For Wi-Fi communication with the Olympus Air.
* `VIBRATE`: For haptic feedback on button presses.

### Change Log

* **1.0.0**: Initial Release

### Source Code

Available on GitHub: [https://github.com/MRSa/AirA01d.git](https://github.com/MRSa/AirA01d.git)
