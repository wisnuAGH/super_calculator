#include <iostream>
#include "SuperCalculator.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    do {
        Menu::clearScreen();
        Menu::displayWelcomeMessage();

        char systemChoice = Menu::chooseNumericSystem();
        Calculator calculator;

        string input1, input2;
        Menu::enterValues(input1, input2);

        int value1, value2;

        switch (systemChoice) {
            case '1':   // decimal
                value1 = stoi(input1);
                value2 = stoi(input2);
                break;
            case '2':   // binary
                value1 = calculator.fromBinary(input1);
                value2 = calculator.fromBinary(input2);
                break;
            case '3':   // octal
                value1 = calculator.fromOctal(input1);
                value2 = calculator.fromOctal(input2);
                break;
            case '4':   // hexadecimal
                value1 = calculator.fromHex(input1);
                value2 = calculator.fromHex(input2);
                break;

            default:
                cerr << "Invalid choice. Exiting program." << endl;
                return 1;
        }

        int result;
        char operationChoice = Menu::chooseOperation();
        switch (operationChoice) {
            case '1':
                result = calculator.add(value1, value2);
                break;
            case '2':
                result = calculator.subtract(value1, value2);
                break;
            case '3':
                result = calculator.multiply(value1, value2);
                break;
            case '4':
                result = calculator.divide(value1, value2);
                break;

            default:
                cerr << "Invalid choice. Exiting program." << endl;
                return 1;
        }

        NumericSystemCalculator numericCalc(&calculator);
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
            // back to loop
        } else {
            cout << "Exiting program." << endl;

            return 0;
        }
    } while (true);
}
// TODO:
//  - add conversion option in main
//  - GTest
