#ifndef HASHINSPECTOR_H
#define HASHINSPECTOR_H

#include <iostream>
#include <string>
#include <windows.h>
#include "HashIdentifier.h"

using namespace std;

class HashInspector {
public:

    void inspect() {

        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            11
        );

        cout << R"(
██╗  ██╗ █████╗ ███████╗██╗  ██╗    ██╗███╗   ██╗
██║  ██║██╔══██╗██╔════╝██║  ██║    ██║████╗  ██║
███████║███████║███████╗███████║    ██║██╔██╗ ██║
██╔══██║██╔══██║╚════██║██╔══██║    ██║██║╚██╗ ██║
██║  ██║██║  ██║███████║██║  ██║    ██║██║ ╚████║
╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚═╝  ╚═══╝
)" << endl;

        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            7
        );

        cout << "Enter hash: ";

        string hashInput;
        cin >> hashInput;

        cout << "\nHash received: " << hashInput << endl;

        char confirmChoice;

        cout << "\nProceed with hash identification? (Y/N): ";
        cin >> confirmChoice;

        if (confirmChoice == 'Y' || confirmChoice == 'y') {

            HashIdentifier identifier;
            identifier.identify(hashInput);

        } else {

            cout << "\nHash identification cancelled." << endl;
        }
    }
};

#endif