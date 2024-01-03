//
// Created by i5 3470 on 03.01.2024.
//

#include "menu.h"

using std::cout;
using std::cin;
using std::endl;

void Menu::displayWelcomeMessage() {
    cout << endl << "Welcome to the Super Calculator!" << endl;
}

char Menu::chooseNumericSystem() {
    char systemChoice;
    do {
        cout << endl << "1. Decimal" << endl;
        cout << "2. Binary" << endl;
        cout << "3. Octal" << endl;
        cout << "4. Hexadecimal" << endl;
        cout << "Enter your choice: ";
        cin >> systemChoice;
    } while (systemChoice < '1' || systemChoice > '4');

    return systemChoice;
}

char Menu::chooseOperation() {
    char systemChoice;
    do {
        cout << endl <<  "Choose operation:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "Enter your choice: ";
        cin >> systemChoice;
    } while (systemChoice < '1' || systemChoice > '4');

    return systemChoice;
}

char Menu::afterOperation() {
    char operationChoice;
    cout << endl <<  "Options:" << endl;
    cout << "1. Continue calculations" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> operationChoice;

    return operationChoice;
}
