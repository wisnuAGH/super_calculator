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

class CalculatorBase {
public:
    virtual double add(double a, double b) const = 0;
    virtual double subtract(double a, double b) const = 0;
    virtual double multiply(double a, double b) const = 0;
    virtual double divide(double a, double b) const = 0;
    virtual string toBinary(double value) const = 0;
    virtual string toOctal(double value) const = 0;
    virtual string toHex(double value) const = 0;
    virtual ~CalculatorBase() {}
};

class FloatCalculator : public CalculatorBase {
public:
    double add(double a, double b) const override;
    double subtract(double a, double b) const override;
    double multiply(double a, double b) const override;
    double divide(double a, double b) const override;
    string toBinary(double value) const override;
    string toOctal(double value) const override;
    string toHex(double value) const override;
};

class NumericSystemCalculator {
private:
    CalculatorBase* calculator;

public:
    NumericSystemCalculator(CalculatorBase* calc);
    void addition(double a, double b) const;
    void subtraction(double a, double b) const;
    void multiplication(double a, double b) const;
    void division(double a, double b) const;
    void displayInDifferentSystems(double value) const;
};


#endif //SUPER_CALCULATOR_SUPERCALCULATOR_H
