//
// Created by Mikolaj Wisniewski on 03.01.2024.
//

#ifndef SUPER_CALCULATOR_MENU_H
#define SUPER_CALCULATOR_MENU_H

#include <iostream>

using std::string;

class Menu {
public:
    static void clearScreen();
    static void displayWelcomeMessage();
    static char chooseNumericSystem();
    static char enterValues(string &value1, string &value2);
    static char chooseOperation();
    static char afterOperation();
};


#endif //SUPER_CALCULATOR_MENU_H
