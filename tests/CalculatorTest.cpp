//
// Created by Mikolaj Wisniewski on 20.01.2024.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../SuperCalculator.h"

TEST(CalculatorTest, FromBinaryTest) {
    Calculator calculator;

    // Test binary conversion for valid input
    EXPECT_EQ(calculator.fromBinary("1010"), 10);
    EXPECT_EQ(calculator.fromBinary("1101"), 13);

    // Test binary conversion for invalid input
    EXPECT_THROW(calculator.fromBinary("1021"), std::invalid_argument);
}

TEST(CalculatorTest, FromOctalTest) {
    Calculator calculator;

    // Test octal conversion for valid input
    EXPECT_EQ(calculator.fromOctal("17"), 15);
    EXPECT_EQ(calculator.fromOctal("34"), 28);

    // Test octal conversion for invalid input
    EXPECT_THROW(calculator.fromOctal("89"), std::invalid_argument);
    }

TEST(CalculatorTest, FromHexTest) {
    Calculator calculator;

    // Test hexadecimal conversion for valid input
    EXPECT_EQ(calculator.fromHex("1A"), 26);
    EXPECT_EQ(calculator.fromHex("2F"), 47);

    // Test hexadecimal conversion for invalid input
    EXPECT_THROW(calculator.fromHex("G2"), std::invalid_argument);
    }
