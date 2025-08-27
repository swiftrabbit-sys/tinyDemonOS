#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string command;

    while (true) {
        cout << "c:/home/shell> ";
        getline(cin, command);

        if (command == "exit" || command == "quit") {
            cout << "Exiting shell...\n";
            break;
        }

        if (!command.empty()) {
            int ret = system(command.c_str());
            if (ret == -1) {
                cerr << "Error executing command.\n";
            }
        }
    }

    return 0;
}
