#include <iostream>
#include "SuperCalculator.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    do {
        Menu::clearScreen();
        Menu::displayWelcomeMessage();

        char systemChoice = Menu::chooseNumericSystem();
        CalculatorBase *calculator;
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

        double value1, value2;
        Menu::enterValues(value1, value2);

        double result;
        char operationChoice = Menu::chooseOperation();
        switch (operationChoice) {
            case '1':
                result = calculator->add(value1, value2);
                break;
            case '2':
                result = calculator->subtract(value1, value2);
                break;
            case '3':
                result = calculator->multiply(value1, value2);
                break;
            case '4':
                result = calculator->divide(value1, value2);
                break;

            default:
                cerr << "Invalid choice. Exiting program." << endl;
                return 1;
        }

        NumericSystemCalculator numericCalc(calculator);
        switch (systemChoice) {
            case '1': // Decimal
                numericCalc.displayDecimal(result);
                break;
            case '2': // Binary
                numericCalc.displayBinary(result);
                break;
            case '3': // Octal
                numericCalc.displayOctal(result);
                break;
            case '4': // Hexadecimal
                numericCalc.displayHexadecimal(result);
                break;
        }

        char exitChoice = Menu::afterOperation();
        if (exitChoice == '1') {
            // pass
        } else {
            delete calculator;
            cout << "Exiting program." << endl;

            return 0;
        }
    } while (true);
}
