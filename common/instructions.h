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
#include <string>

namespace jacky::instructions
{
class Instruction
{
private:
    std::function<void(Cpu&)> m_execute;
    std::string               m_name;
};

} // namespace jacky::instructions