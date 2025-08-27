#!/bin/bash
# fakeboot.sh - MapleOS cinematic slow boot with mostly positive checkbars

# ===== COLORS =====
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RED="\033[1;31m"
BLUE="\033[1;34m"
RESET="\033[0m"

BOOT_START=$(date +%s)

# ===== CHECKBAR FUNCTIONS =====
checkbar_ok()   { echo -e "[ ${GREEN}OK${RESET} ] $1"; sleep 0.25; }
checkbar_fail() { echo -e "[${RED}FAILED${RESET}] $1"; sleep 0.4; }
checkbar_warn() { echo -e "[${YELLOW}WARN${RESET} ] $1"; sleep 0.3; }

# ===== RANDOM MESSAGE POOLS =====
positive_msgs=(
    "Memory management system initialized"
    "CPU microcode updated successfully"
    "GPU firmware loaded"
    "Audio system ready"
    "Network stack configured"
    "Filesystem clean"
    "Security daemon active"
    "Background scheduler started"
    "User session manager ready"
    "Time synchronization complete"
    "Swap space enabled"
    "Power management system ready"
    "MapleOS update service ready"
    "Input devices active"
    "Disk I/O scheduler online"
)

random_positive() {
    echo -e "[ ${GREEN}OK${RESET} ] ${positive_msgs[$RANDOM % ${#positive_msgs[@]}]}"
    sleep 0.25
}

random_checkbar() {
    case $((RANDOM % 6)) in
        0) checkbar_warn "Sound driver slow to initialize" ;;
        1) checkbar_warn "MapleCloud service retrying connection" ;;
        2) checkbar_fail "maple_touchpad.sys not found - ignoring" ;;
        *) random_positive ;;
    esac
}

# ===== LOADING BAR =====
loading_bar() {
    local total=30
    for ((i=0; i<=total; i++)); do
        local percent=$((i * 100 / total))
        local filled=$(printf "%-${i}s" "#" | tr ' ' '#')
        local empty=$(printf "%-$((total-i))s" " ")
        printf "\r[${GREEN}%s${RESET}%s] %3d%%" "$filled" "$empty" "$percent"
        sleep 0.05  # Slower for realism
    done
    echo
}

# ===== SPLASH =====
clear
echo -e "${GREEN}"
cat << "EOF"
 __  __              _      ____   ____
|  \/  | __ _ _ __  | | __ / ___| / ___|
| |\/| |/ _` | '_ \ | |/ / \___ \ \___ \
| |  | | (_| | | | ||   <   ___) | ___) |
|_|  |_|\__,_|_| |_||_|\_\ |____/ |____/
EOF
echo -e "${RESET}${BLUE}          MapleOS Boot Sequence v1.0${RESET}"
sleep 2  # Pause for splash screen

# ===== BIOS =====
checkbar_ok "UEFI BIOS v2.3.1 Initialized"
checkbar_ok "POST memory test"
checkbar_ok "POST CPU check"
random_positive
random_positive
checkbar_ok "POST complete - No errors found"
sleep 0.5

# ===== BOOTLOADER =====
checkbar_ok "MapleCore Bootloader loaded"
random_positive
random_positive
checkbar_ok "Bootloader initialization complete"
sleep 0.5

# ===== KERNEL =====
checkbar_ok "Loading maple_kernel.sys"
checkbar_ok "Loading maple_io.sys"
random_positive
random_checkbar
random_positive
random_checkbar
checkbar_ok "Kernel initialization complete"
sleep 0.5

# ===== HARDWARE =====
random_positive
random_positive
random_positive
random_checkbar
random_positive
random_positive
random_positive
sleep 0.5

# ===== FILESYSTEM =====
checkbar_ok "Mounting /dev/maple0 at /"
random_positive
random_positive
random_positive
checkbar_ok "Filesystem integrity check passed"
sleep 0.5

# ===== SERVICES =====
random_positive
random_positive
random_positive
random_checkbar
random_positive
random_positive
random_positive
random_positive
sleep 0.5

# ===== NETWORK =====
random_positive
random_positive
random_positive
random_positive
random_checkbar
random_positive
sleep 0.5

# ===== SECURITY =====
random_positive
random_positive
random_positive
random_checkbar
random_positive
sleep 0.5

# ===== FINALIZE =====
checkbar_ok "Finalizing boot sequence"
loading_bar

# ===== BOOT TIME =====
BOOT_END=$(date +%s)
BOOT_TIME=$((BOOT_END - BOOT_START))
checkbar_ok "MapleOS boot completed in ${BOOT_TIME}s"

echo
echo -e "${YELLOW}Welcome to MapleOS!${RESET}"
echo "login"
echo -n "user: "
read user
echo -n "password: "
read pass
./boot

