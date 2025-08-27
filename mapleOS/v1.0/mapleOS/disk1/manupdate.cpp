#include <iostream>
#include <thread>
#include <chrono>
#include <filesystem>
#include <vector>
#include <string>
#include <random>

using namespace std;
namespace fs = std::filesystem;

// Random delay generator
int randomDelay(int minMs, int maxMs) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(minMs, maxMs);
    return dist(gen);
}

// Loading bar animation
void loadingBar(int length = 25, int minSpeed = 40, int maxSpeed = 120) {
    cout << "[";
    for (int i = 0; i < length; i++) {
        cout << "#";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(randomDelay(minSpeed, maxSpeed)));
    }
    cout << "] Done" << endl;
}

// Simulate scanning files
vector<string> findSourceFiles() {
    vector<string> files;
    for (const auto& entry : fs::recursive_directory_iterator(".")) {
        if (entry.path().extension() == ".cpp" || entry.path().extension() == ".c") {
            files.push_back(entry.path().string());
        }
    }
    return files;
}

// Simulate compilation steps
void compileFile(const string &file) {
    cout << "[BUILD] Compiling " << file << " ";
    loadingBar();
}

// Simulate linking executable for directories with main()
void linkExecutable(const string &dirName) {
    cout << "[LINK] Creating runnable for directory: " << dirName << " ";
    loadingBar();
}

bool fileContainsMain(const string &file) {
    // Simulate main() detection
    return file.find("main") != string::npos; // Simplified
}

int main() {
    cout << "=== MapleOS Update Utility v1.0 ===" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "[INFO] Scanning for source files..." << endl;

    auto files = findSourceFiles();
    this_thread::sleep_for(chrono::milliseconds(800));

    if (files.empty()) {
        cout << "[ERROR] No source files found." << endl;
        return 1;
    }

    cout << "[INFO] Found " << files.size() << " source files." << endl;

    // Fake compile
    for (auto &file : files) {
        compileFile(file);
    }

    // Simulate linking per directory with main
    cout << "\n[INFO] Linking executables..." << endl;
    for (auto &file : files) {
        if (fileContainsMain(file)) {
            string dir = fs::path(file).parent_path().string();
            if (dir.empty()) dir = ".";
            linkExecutable(dir);
        }
    }

    cout << "\n[UPDATE] Build complete! Runnables ready." << endl;

    return 0;
}

