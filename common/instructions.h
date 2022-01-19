/**
 * @file instructions.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief List of all instructions supported by the CPU.
 * @date 2022-01-19
 *
 * @copyright Copyright Alyce (c) 2022
 */

#pragma once
#include "cpu.h"
#include <functional>

namespace jacky
{
namespace instructions
{
    class Instruction
    {
    private:
        std::string name;
    public:
        std::function<void(Cpu&)> execute;
    };

} // namespace instructions
} // namespace jacky
