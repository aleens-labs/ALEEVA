<h1 align="center">ALEEVA</h1>

<p align="center">
Modular ESP32-based embedded platform for RF experimentation, signal analysis, and applied security research.
</p>

<p align="center">
  <a href="#">X / Twitter</a> ·
  <a href="#">Instagram</a> ·
  <a href="#">YouTube</a> ·
  <a href="#">Website</a>
</p>

---

## 📚 Documentation
All technical documentation, build guides, and usage notes are available in the `docs/` directory.  
This includes hardware schematics, firmware structure, flashing instructions, and troubleshooting references.

---

## 🚧 Roadmap
Planned improvements for upcoming revisions:

- Improved menu navigation and user interface flow  
- Extended RF frequency support  
- Power optimization and deep-sleep enhancements  
- Modular firmware architecture for rapid feature development  

---

## 🧠 Project Overview
ALEEVA is a custom embedded system built around the ESP32 platform, designed for RF-focused experimentation and security-oriented research.  
The device combines RF communication, local data storage, and a physical control interface into a compact, standalone platform suitable for laboratory work, prototyping, and education.

---

## 🧩 Features

### Firmware
- RF signal scanning and monitoring  
- Signal capture and retransmission workflows  
- Menu-driven navigation using rotary encoder and buttons  
- Modular and extensible codebase  

### Hardware
- **MCU**: ESP32-WROOM-32  
- **RF Module**: CC1101 with SMA antenna connector  
- **Display**: 0.96" OLED (I2C)  
- **Storage**: MicroSD card (SPI)  
- **Input**: Rotary encoder and tactile buttons  
- **Power**: Li-ion charging via TP4056 with onboard regulation  
- **Visual Feedback**: WS2812B RGB LED  

---

## 🧪 Repository Structure
```text
hardware/   -> PCB, schematic, BOM, and manufacturing files
firmware/   -> ESP32 firmware source code (PlatformIO)
docs/       -> Technical documentation and guides
examples/   -> Module-level test programs

🤝 Contributing

Contributions are welcome.
Suggestions, bug reports, and feature requests can be submitted through GitHub issues or pull requests.

📄 License

This project is released under the MIT License.
See the LICENSE file for more information.

🙏 Acknowledgements

This project builds upon open-source libraries and community-driven efforts, including:
CC1101 RF driver libraries
OLED menu frameworks
The ESP32 open-source ecosystem
Special thanks to contributors and researchers who support open embedded systems development.
