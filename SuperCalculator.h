//
// Created by Mikolaj Wisniewski on 03.01.2024.
//

#ifndef SUPER_CALCULATOR_SUPERCALCULATOR_H
#define SUPER_CALCULATOR_SUPERCALCULATOR_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <sstream>
#include <limits>
#include "menu.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

// Abstract Main Class
class CalculatorBase {
public:
    virtual int add(int a, int b) const = 0;
    virtual int subtract(int a, int b) const = 0;
    virtual int multiply(int a, int b) const = 0;
    virtual int divide(int a, int b) const = 0;
    virtual string toBinary(int value) const = 0;
    virtual string toOctal(int value) const = 0;
    virtual string toHex(int value) const = 0;
    virtual int fromBinary(const string& binary) const = 0;
    virtual int fromOctal(const string& octal) const = 0;
    virtual int fromHex(const string& hex) const = 0;
    virtual ~CalculatorBase() {}
};

// Main Operating Class
class Calculator : public CalculatorBase {
public:
    int add(int a, int b) const override;
    int subtract(int a, int b) const override;
    int multiply(int a, int b) const override;
    int divide(int a, int b) const override;
    string toBinary(int value) const override;
    string toOctal(int value) const override;
    string toHex(int value) const override;
    int fromBinary(const string& binaryNum) const override;
    int fromOctal(const string& octalNum) const override;
    int fromHex(const string& hex) const override;
};

// Display Class
class NumericSystemCalculator {
private:
    CalculatorBase* calculator;

public:
    NumericSystemCalculator(CalculatorBase* calc);
    void displayDecimal(int value) const;
    void displayBinary(int value) const;
    void displayOctal(int value) const;
    void displayHexadecimal(int value) const;
};


#endif //SUPER_CALCULATOR_SUPERCALCULATOR_H
