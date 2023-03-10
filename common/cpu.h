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
#include <limits>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace jacky
{

class unsupported_opcode : public std::runtime_error
{
private:
    uint8_t m_opcode;

public:
    explicit unsupported_opcode(uint8_t opcode)
        : std::runtime_error("unsupported opcode " + std::to_string(opcode))
        , m_opcode(opcode)
    {
    }

    uint8_t opcode() const
    {
        return m_opcode;
    }
};

using opcode_t = uint8_t;

class Cpu
{
public:
    template <opcode_t opcode>
    void opcode_handler()
    {
        throw unsupported_opcode(opcode);
    }

private:
    std::map<opcode_t, void (Cpu::*)()> m_opcode_handlers;

public:
    Cpu();
    virtual ~Cpu() = default;

    void execute(opcode_t opcode);

private:
    bool     m_halted { false };
    opcode_t m_loaded_opcode { std::numeric_limits<opcode_t>::min() };
};

template <>
void Cpu::opcode_handler<0x00>(); // NOP

} // namespace jacky