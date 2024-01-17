//
// Created by i5 3470 on 03.01.2024.
//

#include "menu.h"

using std::cout;
using std::cin;
using std::endl;

void Menu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::displayWelcomeMessage() {
    cout << endl << "---| Super Calculator |---" << endl;
}

char Menu::chooseNumericSystem() {
    char systemChoice;
    do {
        cout << endl << "[1] Decimal" << endl;
        cout << "[2] Binary" << endl;
        cout << "[3] Octal" << endl;
        cout << "[4] Hexadecimal" << endl;
        cout << "Enter your choice: ";
        cin >> systemChoice;
    } while (systemChoice < '1' || systemChoice > '4');

    return systemChoice;
}

char Menu::enterValues(double &value1, double &value2) {
    cout << endl << "Enter 1st value: ";
    cin >> value1;
    cout << "\nEnter 2nd value: ";
    cin >> value2;
}

char Menu::chooseOperation() {
    char operationChoice;
    do {
        cout << endl <<  "Choose operation:" << endl;
        cout << "[1] Add" << endl;
        cout << "[2] Subtract" << endl;
        cout << "[3] Multiply" << endl;
        cout << "[4] Divide" << endl;
        cout << "Enter your choice: ";
        cin >> operationChoice;
    } while (operationChoice < '1' || operationChoice > '4');

    return operationChoice;
}

char Menu::afterOperation() {
    char exitChoice;
    cout << endl <<  "Options:" << endl;
    cout << "[1] Continue calculations" << endl;
    cout << "[any key] Exit" << endl;
    cout << "Enter your choice: ";
    cin >> exitChoice;

    return exitChoice;
}
