/**
 * @file cpu.cpp
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief
 * @date 2022-01-19
 *
 * @copyright Copyright Alyce (c) 2022
 */

#include "cpu.h"

jacky::Cpu::Cpu()
    : memory(0xFFFF)
    , running(false)
    , pc(0x0000)
    , sp(0xFFFF)
{
}