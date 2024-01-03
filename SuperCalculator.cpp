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
using std::oct;
using std::hex;
using std::ostringstream;
using std::uppercase;

double FloatCalculator::add(double a, double b) const {
    return a + b;
}

double FloatCalculator::subtract(double a, double b) const {
    return a - b;
}

double FloatCalculator::multiply(double a, double b) const {
    return a * b;
}

double FloatCalculator::divide(double a, double b) const {
    if (b != 0) {
        return a / b;
    } else {
        cerr << "Error: Division by zero!" << endl;
        return numeric_limits<double>::quiet_NaN();
    }
}

string FloatCalculator::toBinary(double value) const {
    bitset<64> bits(*reinterpret_cast<uint64_t*>(&value));
    return bits.to_string();
}

string FloatCalculator::toOctal(double value) const {
    ostringstream oss;
    oss << oct << static_cast<int>(value);
    return oss.str();
}

string FloatCalculator::toHex(double value) const {
    ostringstream oss;
    oss << hex << uppercase << *reinterpret_cast<uint64_t*>(&value);
    return oss.str();
}

NumericSystemCalculator::NumericSystemCalculator(CalculatorBase* calc) : calculator(calc) {}

void NumericSystemCalculator::addition(double a, double b) const {
    cout << "Addition: " << calculator->add(a, b) << endl;
}

void NumericSystemCalculator::subtraction(double a, double b) const {
    cout << "Subtraction: " << calculator->subtract(a, b) << endl;
}

void NumericSystemCalculator::multiplication(double a, double b) const {
    cout << "Multiplication: " << calculator->multiply(a, b) << endl;
}

void NumericSystemCalculator::division(double a, double b) const {
    cout << "Division: " << calculator->divide(a, b) << endl;
}

void NumericSystemCalculator::displayInDifferentSystems(double value) const {
    cout << "Binary: " << calculator->toBinary(value) << endl;
    cout << "Octal: " << calculator->toOctal(value) << endl;
    cout << "Hexadecimal: " << calculator->toHex(value) << endl;
}