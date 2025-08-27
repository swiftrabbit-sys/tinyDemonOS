// boot.cpp — MapleOS Bootloader with Slow Loading Bars
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <random>

using namespace std;
namespace fs = std::filesystem;

// Random number generator for varying speeds
int randomDelay(int minMs, int maxMs) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(minMs, maxMs);
    return dist(gen);
}

// Draw a slower loading bar animation
void loadingBar(int length = 30, int minSpeed = 80, int maxSpeed = 160) {
    cout << "[";
    for (int i = 0; i < length; i++) {
        cout << "#";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(randomDelay(minSpeed, maxSpeed)));
    }
    cout << "] [OK]" << endl;
}

// Boot step with bar
void bootStep(const string &msg) {
    cout << "[BOOT] " << msg << " ";
    loadingBar();
    this_thread::sleep_for(chrono::milliseconds(randomDelay(200, 500)));
}

int main() {
    cout << "=== MapleOS Bootloader v1.0 ===" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    bootStep("Loading Kernel");
    bootStep("Initializing Memory");
    bootStep("Mounting Filesystems");
    bootStep("Detecting Devices");
    bootStep("Starting MapleShell");

    cout << "\n[BOOT] Handing control to kernel..." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));

   system("./main");
    return 0;
}
