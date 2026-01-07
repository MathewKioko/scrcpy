# MathewKioko's Enhanced scrcpy (v3.3.4+)

**This is an enhanced version of scrcpy with additional features and improvements by MathewKioko.**

<img src="app/data/icon.svg" width="128" height="128" alt="scrcpy" align="right" />

_pronounced "**scr**een **c**o**py**"_

This enhanced application mirrors Android devices (video and audio) connected via USB or [TCP/IP](doc/connection.md#tcpip-wireless) and allows control using the computer's keyboard and mouse. It does not require _root_ access or an app installed on the device. It works on _Linux_, _Windows_, and _macOS_.

![screenshot](assets/screenshot-debian-600.jpg)

## 🚀 Enhanced Features

### 🎨 UI & Theme Enhancements
- **Multiple Themes**: Default, Dark, Light, and Custom themes
- **Window Transparency**: Configurable transparency levels (0.0-1.0)
- **Performance Overlay**: Real-time performance monitoring display
- **Advanced Controls**: Enhanced UI with additional control panels
- **Quick Actions**: One-click access to common functions

### 📹 Advanced Recording Features
- **Smart Recording Modes**: Normal, Split, Scheduled, and Continuous recording
- **Storage Management**: Automatic storage optimization and limits
- **Compression Options**: On-save compression for space efficiency
- **Scheduled Recording**: Set specific hours for automatic recording
- **Split Duration Control**: Automatically split long recordings

### 🔧 Performance & Optimization
- **Performance Monitoring**: Real-time CPU, memory, and network usage
- **Network Optimization**: Enhanced network performance for wireless connections
- **Auto Update Check**: Automatic checking for updates
- **Crash Reporting**: Optional crash reporting for stability improvements
- **Multi-Device Support**: Enhanced support for managing multiple devices

### ⌨️ Enhanced Input & Control
- **Custom Shortcuts**: Configurable keyboard shortcuts with file-based configuration
- **Enhanced Hotkeys**: Additional hotkeys for common operations
- **Device Grouping**: Organize multiple devices into groups
- **Advanced Logging**: Detailed logging options for troubleshooting

## 📋 Prerequisites

The Android device requires at least API 21 (Android 5.0).

[Audio forwarding](doc/audio.md) is supported for API >= 30 (Android 11+).

Make sure you [enabled USB debugging][enable-adb] on your device(s).

[enable-adb]: https://developer.android.com/studio/debug/dev-options#enable

## 🛠️ Installation

### Enhanced Features Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/MathewKioko/scrcpy.git
   cd scrcpy
   ```

2. **Build with enhanced features:**
   ```bash
   # Linux/macOS
   meson setup build
   ninja -C build
   
   # Windows (using MSYS2)
   meson setup build
   ninja -C build
   ```

3. **Install dependencies** (if needed):
   - **Linux**: `sudo apt install ffmpeg libsdl2-2.0-0`
   - **macOS**: `brew install ffmpeg sdl2`
   - **Windows**: Download from official websites

## 🎯 Usage Examples

### Basic Usage
```bash
# Standard mirroring
scrcpy

# With enhanced features
scrcpy --theme dark --enable-transparency=0.7 --show-performance
```

### Advanced Recording
```bash
# Split recording every 10 minutes
scrcpy --advanced-recording split --split-duration 600 --max-storage 5

# Scheduled recording (9 AM to 6 PM only)
scrcpy --advanced-recording scheduled --max-storage 10

# Continuous recording with compression
scrcpy --advanced-recording continuous --compress-on-save
```

### Performance & Optimization
```bash
# Enable performance monitoring and network optimization
scrcpy --performance-monitoring --network-optimization

# Multi-device support
scrcpy --multi-device --serial=DEVICE1 --serial=DEVICE2
```

### Customization
```bash
# Custom theme and transparency
scrcpy --theme custom --enable-transparency=0.5

# Custom shortcuts with configuration file
scrcpy --custom-shortcuts shortcuts.conf --quick-actions

# Enhanced logging
scrcpy --advanced-logging --crash-reporting
```

## 🎨 Enhanced Command Line Options

### Theme & UI Options
```
--theme <theme>              Set UI theme (default|dark|light|custom)
--enable-transparency[=level] Enable window transparency (0.0-1.0)
--show-performance           Show performance overlay
--enable-hotkeys             Enable enhanced hotkeys
```

### Advanced Recording Options
```
--advanced-recording <mode>  Advanced recording mode (normal|split|scheduled|continuous)
--split-duration <seconds>   Split recording duration in seconds
--max-storage <gb>           Maximum storage for recordings in GB
--compress-on-save           Enable compression on save
```

### Performance & Monitoring
```
--performance-monitoring     Enable performance monitoring
--network-optimization       Enable network optimization
--auto-update-check          Enable automatic update checking
--crash-reporting            Enable crash reporting
```

### Multi-Device & Advanced Features
```
--multi-device               Enable multi-device support
--quick-actions              Enable quick actions panel
--custom-shortcuts[=file]    Enable custom shortcuts with optional config file
--advanced-logging           Enable advanced logging
```

## 🔧 Configuration Files

### Custom Shortcuts Configuration
Create a `shortcuts.conf` file:
```
# Custom shortcuts configuration
F1=HOME
F2=BACK
F3=APP_SWITCH
F4=POWER
Ctrl+Shift+R=RECORD_START
Ctrl+Shift+S=RECORD_STOP
```

### Theme Configuration
Create a `theme.conf` file for custom themes:
```
# Custom theme configuration
background_color=#1a1a1a
text_color=#ffffff
accent_color=#007bff
border_radius=8
```

## 📊 Performance Features

### Real-time Monitoring
- **CPU Usage**: Monitor device and computer CPU usage
- **Memory Usage**: Track RAM consumption
- **Network Performance**: Monitor connection quality
- **Frame Rate**: Display current FPS
- **Battery Level**: Show device battery status

### Storage Management
- **Automatic Cleanup**: Remove old recordings when storage is full
- **Compression**: Reduce file sizes without quality loss
- **Split Recording**: Manage large recordings efficiently
- **Storage Limits**: Set maximum storage usage

## 🐛 Troubleshooting

### Common Issues
1. **Device not detected**: Ensure USB debugging is enabled
2. **Poor performance**: Try reducing resolution or frame rate
3. **Audio issues**: Check Android version (requires 11+ for audio forwarding)
4. **Connection problems**: Verify ADB connection and network settings

### Enhanced Features Issues
1. **Theme not applying**: Check if theme files exist
2. **Recording not working**: Verify storage permissions and space
3. **Performance overlay not showing**: Enable with `--show-performance`
4. **Custom shortcuts not working**: Check configuration file syntax

### Debug Mode
```bash
# Enable debug logging
scrcpy --log-level debug --advanced-logging

# Check device compatibility
scrcpy --list-encoders --list-displays
```

## 🤝 Contributing

We welcome contributions to enhance this project further:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This enhanced version is based on the original scrcpy project:

```
Copyright (C) 2018 Genymobile
Copyright (C) 2018-2026 Romain Vimont
Copyright (C) 2024-2026 Mathew Kioko

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```

## 📞 Support

For support and questions:
- **Issues**: [GitHub Issues](https://github.com/MathewKioko/scrcpy/issues)
- **Discussions**: [GitHub Discussions](https://github.com/MathewKioko/scrcpy/discussions)
- **Documentation**: [Enhanced Documentation](doc/)

## 🙏 Acknowledgments

This project is built upon the excellent work of the original scrcpy team and contributors. Special thanks to:
- Romain Vimont and the Genymobile team
- All contributors to the original scrcpy project
- The open-source community for their continued support

---

**Note**: This is an enhanced version with additional features. For the original scrcpy project, visit [Genymobile/scrcpy](https://github.com/Genymobile/scrcpy).
