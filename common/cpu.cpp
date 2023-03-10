/**
 * @file cpu.cpp
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief
 * @date 2022-01-19
 *
 * @copyright Copyright Alyce (c) 2022
 */

#include "cpu.h"
#include <spdlog/spdlog.h>

namespace jacky
{

Cpu::Cpu()
{
    spdlog::info("Initializing CPU...");
    m_opcode_handlers[0x00] = &Cpu::opcode_handler<0x00>;
    m_opcode_handlers[0x01] = &Cpu::opcode_handler<0x01>;
}

void Cpu::execute(opcode_t opcode)
{
    m_loaded_opcode = opcode;
    if (m_opcode_handlers.find(opcode) == m_opcode_handlers.end())
    {
        throw unsupported_opcode(opcode);
    }
    (this->*m_opcode_handlers[opcode])();
}

template <>
void Cpu::opcode_handler<0x00>()
{

}

} // namespace jacky
