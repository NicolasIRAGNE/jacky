/**
 * @file registers_tests.cpp
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2022-01-19
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#include <gtest/gtest.h>
#include "register.h"

TEST(RegisterTest, DefaultConstructor)
{
    jacky::Register8 reg8;
    reg8.set(0xFF);
    EXPECT_EQ(reg8.get(), 0xFF);
    jacky::Register16 reg16;
    reg16.set(0xFFFF);
    EXPECT_EQ(reg16.get(), 0xFFFF);
}

TEST(RegisterTest, Set)
{
    jacky::Register8 reg8;
    for (uint8_t i = 0; i < 0xFF; i++)
    {
        reg8.set(i);
        EXPECT_EQ(reg8.get(), i);
    }
}