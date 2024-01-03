#include <iostream>
#include "SuperCalculator.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Menu::displayWelcomeMessage();

    char systemChoice = Menu::chooseNumericSystem();
    CalculatorBase* calculator;
    switch (systemChoice) {
        case '1':
            calculator = new FloatCalculator();  // decimal
            break;
        case '2':
            calculator = new FloatCalculator();  // TODO: binary
            break;
        case '3':
            calculator = new FloatCalculator();  // TODO: octal
            break;
        case '4':
            calculator = new FloatCalculator();  // TODO: hexadecimal
            break;

        default:
            cerr << "Invalid choice. Exiting program." << endl;
            return 1;
    }

    char enterValue;
    do {
        double operand1, operand2;
        cout << endl << "Enter operand 1: ";
        cin >> operand1;
        cout << "Enter operand 2: ";
        cin >> operand2;

        NumericSystemCalculator numericCalc(calculator);

        char operationChoice = Menu::chooseOperation();
        switch (operationChoice) {
            case '1':
                numericCalc.addition(operand1, operand2);
                break;
            case '2':
                numericCalc.subtraction(operand1, operand2);
                break;
            case '3':
                numericCalc.multiplication(operand1, operand2);
                break;
            case '4':
                numericCalc.division(operand1, operand2);
                break;

            default:
                cerr << "Invalid choice. Exiting program." << endl;
                return 1;
        }

        enterValue = Menu::afterOperation();

    } while (enterValue == '1');

    delete calculator;
    cout << "Exiting program." << endl;

    return 0;
}
