/**
 * @file cpu.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief
 * @date 2022-01-19
 *
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once
#include "register.h"
#include <cstdint>
#include <vector>

namespace jacky
{
class Cpu
{
public:
    Cpu();
    /**
     * @brief Load a compiled program into memory.
     */
    void load(const std::vector<uint8_t>& program);
    void run();

private:
    /// Mapping of the memory that is addressable by the CPU. Note that this mapping is not physically contiguous.
    std::vector<uint8_t> memory = std::vector<uint8_t>(0xFFFF);
    bool running { false };

    struct
    {
        /// Counter to what the CPU is currently executing from memory.
        jacky::Register16 pc { 0x0000 };
        /// Pointer to the top of the stack. It starts at 0xFFFF and goes down.
        jacky::Register16 sp { 0xFFFF };
        /// 16 bit register used to work with pointers
        jacky::Register16 h { 0x0000 };

        /// Flag register
        jacky::Register8 f { 0x00 };

        jacky::Register16 a { 0x0000 };
        jacky::Register8 b { 0x00 };
        jacky::Register8 c { 0x00 };
        jacky::Register8 d { 0x00 };
    } registers;

    int step();
};
}