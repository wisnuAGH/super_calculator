//
// Created by Mikolaj Wisniewski on 03.01.2024.
//

#include "SuperCalculator.h"

using std::cout;
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
    } else {
        cerr << "Error: Division by zero!" << endl;
        return numeric_limits<int>::min(); // Returning a special value for error
    }
}

string Calculator::toBinary(int value) const {
    bitset<32> bits(value);
    return bits.to_string();
}

string Calculator::toOctal(int value) const {
    ostringstream oss;
    oss << oct << value;
    return oss.str();
}

string Calculator::toHex(int value) const {
    ostringstream oss;
    oss << hex << uppercase << value;
    return oss.str();
}

int Calculator::fromBinary(const std::string& binaryNum) const {
    std::bitset<32> bits(binaryNum);
    return static_cast<int>(bits.to_ulong());
}

int Calculator::fromOctal(const std::string& octalNum) const {
    int result;
    std::istringstream(octalNum) >> oct >> result;
    return result;
}

int Calculator::fromHex(const std::string& hexNum) const {
    int result;
    std::istringstream(hexNum) >> hex >> result;
    return result;
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
