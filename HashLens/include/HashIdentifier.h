#ifndef HASHIDENTIFIER_H
#define HASHIDENTIFIER_H

#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>

using namespace std;

class HashIdentifier {
public:

    void identify(const string& hash) {

        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            12
        );

        cout << R"(
██╗  ██╗ █████╗ ███████╗██╗  ██╗    ████████╗██╗   ██╗██████╗ ███████╗
██║  ██║██╔══██╗██╔════╝██║  ██║    ╚══██╔══╝╚██╗ ██╔╝██╔══██╗██╔════╝
███████║███████║███████╗███████║       ██║    ╚████╔╝ ██████╔╝█████╗
██╔══██║██╔══██║╚════██║██╔══██║       ██║     ╚██╔╝  ██╔═══╝ ██╔══╝
██║  ██║██║  ██║███████║██║  ██║       ██║      ██║   ██║     ███████╗
╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝       ╚═╝      ╚═╝   ╚═╝     ╚══════╝
)" << endl;

        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            7
        );

        bool isHex = true;

        for (char c : hash) {
            if (!isxdigit(static_cast<unsigned char>(c))) {
                isHex = false;
                break;
            }
        }

        if (!isHex) {
            cout << "Unknown hash type." << endl;
        }
        else if (hash.length() == 32) {
            cout << "Possible hash type: MD5" << endl;
        }
        else if (hash.length() == 40) {
            cout << "Possible hash type: SHA-1" << endl;
        }
        else if (hash.length() == 64) {
            cout << "Possible hash types: SHA-256 / SHA3-256" << endl;
        }
        else if (hash.length() == 128) {
            cout << "Possible hash types: SHA-512 / SHA3-512" << endl;
        }
        else {
            cout << "Unknown / custom hash type." << endl;
        }
    }
};

#endif