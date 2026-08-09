#include <iostream>
#include <windows.h>
#include "../include/HashInspector.h"

using namespace std;

int main(void) {
    SetConsoleOutputCP(CP_UTF8);

    cout << R"(
██╗  ██╗ █████╗ ███████╗██╗  ██╗    ██╗██████╗
██║  ██║██╔══██╗██╔════╝██║  ██║    ██║██╔══██╗
███████║███████║███████╗███████║    ██║██║  ██║
██╔══██║██╔══██║╚════██║██╔══██║    ██║██║  ██║
██║  ██║██║  ██║███████║██║  ██║    ██║██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚═╝╚═════╝
)" << endl;

    cout << "HashLens - Hash Identification & Analysis Tool" << endl;
    cout << "Version: 1.0.0" << endl;
    cout << "Omar Ahmed" << endl;
    cout << "Supported hash algorithms: MD5, SHA-1, SHA-256, SHA-512, "
         "SHA3-256, SHA3-512" << endl;

    char startChoice;

    cout << "\nStart hash inspection? (Y/N): ";
    cin >> startChoice;

    if (startChoice == 'Y' || startChoice == 'y') {

        HashInspector inspector;
        inspector.inspect();

    } else {

        cout << "HashLens shutting down..." << endl;
    }

    return 0;
}