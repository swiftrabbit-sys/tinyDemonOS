#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <string>
#include <vector>

using namespace std;


int randomDelay(int minMs, int maxMs) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(minMs, maxMs);
    return dist(gen);
}

void loadingBar(int length = 30, int minSpeed = 80, int maxSpeed = 160) {
    cout << "[";
    for (int i = 0; i < length; i++) {
        cout << "#";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(randomDelay(minSpeed, maxSpeed)));
    }
    cout << "] [OK]" << endl;
}

void funcStep(const string &msg) {
    cout << msg; cout << "[MAPLE] " << msg << " ";
    loadingBar();
    this_thread::sleep_for(chrono::milliseconds(randomDelay(200, 500)));
}
