//
// Created by i5 3470 on 03.01.2024.
//

#ifndef SUPER_CALCULATOR_MENU_H
#define SUPER_CALCULATOR_MENU_H

#include <iostream>

class Menu {
public:
    static void clearScreen();
    static void displayWelcomeMessage();
    static char chooseNumericSystem();
    static char enterValues(double &value1, double &value2);
    static char chooseOperation();
    static char afterOperation();
};


#endif //SUPER_CALCULATOR_MENU_H
