//
// Created by Mikolaj Wisniewski on 03.01.2024.
//

#include "SuperCalculator.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::numeric_limits;
using std::bitset;
using std::ostringstream;
using std::oct;
using std::hex;
using std::uppercase;
using std::stoi;
using std::overflow_error;
using std::invalid_argument;
using std::out_of_range;
using std::istringstream;

int Calculator::add(int a, int b) const {
    return a + b;
}

int Calculator::subtract(int a, int b) const {
    return a - b;
}

int Calculator::multiply(int a, int b) const {
    return a * b;
}

int Calculator::divide(int a, int b) const {
    if (b != 0) {
        return a / b;
    }
    else
    {
        cerr << "Error: Division by zero!" << endl;
        return numeric_limits<int>::min(); // Returning a special value for error
    }
}

string Calculator::toBinary(int value) const {
    try {
        bitset<32> bits(value);
        return bits.to_string();
    }
    catch (const overflow_error &e) {
        cerr << "Error: Overflow during binary conversion." << endl;
        throw;
    }
}

string Calculator::toOctal(int value) const {
    try {
        ostringstream oss;
        oss << oct << value;
        return oss.str();
    }
    catch (const std::overflow_error& e) {
        cerr << "Error: Overflow during octal conversion." << endl;
        throw;
    }
}

string Calculator::toHex(int value) const {
    try {
        ostringstream oss;
        oss << hex << uppercase << value;
        return oss.str();
    }
    catch (const std::overflow_error& e) {
        cerr << "Error: Overflow during hexadecimal conversion." << endl;
        throw;
    }
}

int Calculator::fromBinary(const string& binaryNumInput) const {
    string binaryNum = binaryNumInput;
    while (true) {
        try {
            bitset<32> bits(binaryNum);
            return static_cast<int>(bits.to_ulong());
        }
        catch (const invalid_argument& e) {
            cerr << "Error: Invalid binary input." << endl;
        }
        catch (const out_of_range& e) {
            cerr << "Error: Out of range during binary conversion." << endl;
        }
        cerr << "Please enter a valid binary (0-1) value max 32 bits: ";
        cin >> binaryNum;
    }
}

int Calculator::fromOctal(const string& octalNumInput) const {
    string octalNum = octalNumInput;
    while (true) {
        try {
            int result;
            istringstream(octalNum) >> oct >> result;
            return result;
        }
        catch (const std::invalid_argument& e) {
            cerr << "Error: Invalid octal input." << endl;
        }
        catch (const std::out_of_range& e) {
            cerr << "Error: Out of range during octal conversion." << endl;
        }
        cerr << "Please enter a valid octal value (0-7): ";
        cin >> octalNum;
    }
}

int Calculator::fromHex(const string& hexNumInput) const {
    string hexNum = hexNumInput;
    while (true) {
        try {
            int result;
            istringstream(hexNum) >> hex >> result;
            return result;
        }
        catch (const invalid_argument& e) {
            cerr << "Error: Invalid hexadecimal input." << endl;
        }
        catch (const out_of_range& e) {
            cerr << "Error: Out of range during hexadecimal conversion." << endl;
        }
        cerr << "Please enter a valid hexadecimal value (0-F): ";
        cin >> hexNum;
    }
}

NumericSystemCalculator::NumericSystemCalculator(CalculatorBase* calc) : calculator(calc) {}

void NumericSystemCalculator::displayDecimal(int value) const {
    cout << endl << "Result: " << value << endl;
}

void NumericSystemCalculator::displayBinary(int value) const {
    cout << endl << "Result: " << calculator->toBinary(value) << endl;
}

void NumericSystemCalculator::displayOctal(int value) const {
    cout << endl << "Result: " << calculator->toOctal(value) << endl;
}

void NumericSystemCalculator::displayHexadecimal(int value) const {
    cout << endl << "Result: " << calculator->toHex(value) << endl;
}
