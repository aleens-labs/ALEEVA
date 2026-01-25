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

### 🧪 Repository Structure

hardware/   -> PCB, schematic, BOM, and manufacturing files
firmware/   -> ESP32 firmware source code (PlatformIO)
docs/       -> Technical documentation and guides
examples/   -> Module-level test programs

---
### 🤝 Contributing

Contributions are welcome.
If you have ideas for improvements, feature requests, or bug reports, please open an issue or submit a pull request.

---

📄 License

Distributed under the MIT License.
See the LICENSE file for more information.

---

🙏 Acknowledgements & References

This project builds upon open-source libraries, community research, and publicly available technical documentation:

1. **U8g2 OLED Library**  
   https://github.com/olikraus/u8g2  

2. **Adafruit GFX Library**  
   https://github.com/adafruit/Adafruit-GFX-Library  

3. **Adafruit SSD1306 Library**  
   https://github.com/adafruit/Adafruit_SSD1306  

4. **rc-switch (OOK/ASK RF Reference)**  
   https://github.com/sui77/rc-switch  

5. **SmartRC CC1101 Driver Library**  
   https://github.com/LSatan/SmartRC-CC1101-Driver-Lib  

6. **Texas Instruments CC1101 Datasheet**  
   https://www.ti.com/lit/ds/symlink/cc1101.pdf  


Special thanks to the open-source community and researchers whose work enables experimentation and learning in embedded RF systems.

---
