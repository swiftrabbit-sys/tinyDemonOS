# tinyDaemonOS
A lightweight sub-OS for **DaemonOS**, designed for testing, modular builds, and low-resource environments.  
tinyDaemonOS is split into multiple disks, each with its own entry point, shell, and resources — with a core kernel in C++ and shell components in Python.

---

## ✨ Features
- **Multi-disk architecture** — 4 disks with their own `main.cpp`, `shell.py`, and resources.
- **Root kernel entry** — `boot.cpp` and `main.cpp` handle the main OS initialization.
- **Python-powered shell** — Each disk has its own specialized shell, plus a global shell.
- **Header-based structure** — `headerfiles/Daemon.h` centralizes shared definitions and constants.
- **Fake boot script** — `boot.sh` simulates a real OS boot for fun/demo purposes.


---

## 📂 Folder & File Structure

```
tinyDaemonOS/
├── boot.cpp                # Bootloader stage 1
├── main.cpp                # Kernel main entry point
├── shell.py                 # Global OS shell
├── boot.sh                  # Fake boot script for demonstration
├── headerfiles/
│   └── Daemon.h             # Global OS header definitions
├── disk0/
│   ├── main.cpp             # Disk0 entry point
│   ├── shell.py             # Disk0 shell
│   ├── a1                   # Resource file 1
│   ├── a2                   # Resource file 2
│   └── a3                   # Resource file 3
├── disk1/
│   ├── main.cpp
│   ├── shell.py
│   ├── a1
│   ├── a2
│   └── a3
├── disk2/
│   ├── main.cpp
│   ├── shell.py
│   ├── a1
│   ├── a2
│   └── a3
├── disk3/
│   ├── main.cpp
│   ├── shell.py
│   ├── a1
│   ├── a2
│   └── a3
├── Makefile
├── LICENSE
└── README.md
```

---

## 💽 Disk Layout & Purpose
- **Disk 0** → Boot processes, minimal kernel hooks, early shell.
- **Disk 1** → Core libraries, driver initialization.
- **Disk 2** → Userland shell and applications.
- **Disk 3** → Optional modules, games, experimental tools.

Each disk contains:
- `main.cpp` → Entry point for that disk’s logic.
- `shell.py` → Disk-specific shell commands.
- `a1`, `a2`, `a3` → Resource files (configs, binaries, graphics, etc.).

---

## 🛠 Build Instructions

Clone and build:
```bash
git clone https://github.com/YourUsername/tinyDaemonOS.git
cd tinyDaemonOS
make build
```

---

## 🖥 Fake Boot Script

Run the fake boot simulation:
```bash
chmod +x boot.sh
./boot.sh
```

**boot.sh** example:
```bash
#!/bin/bash
echo "tinyDaemonOS Bootloader v0.1"
echo "Initializing hardware..."
sleep 1
echo "Loading kernel from boot.cpp..."
sleep 1
echo "Mounting disks..."
sleep 1
echo "Disk0 [OK]  Disk1 [OK]  Disk2 [OK]  Disk3 [OK]"
sleep 1
echo "Starting shell.py..."
python3 shell.py
```

---

## 📄 License
This project is licensed under the MIT License. See `LICENSE` for details.
