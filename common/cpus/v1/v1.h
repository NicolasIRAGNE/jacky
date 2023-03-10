/**
 * @file v1.h
 * @author Nicolas IRAGNE (nicoragne@hotmail.fr)
 * @brief V1 CPU. Very basic CPU with only 1 register and a few instructions.
 * @date 2023-03-10
 *
 * @copyright Copyright niragne (c) 2023
 */

#pragma once

#include "cpu.h"

namespace jacky::cpus
{

class V1 : public Cpu
{
public:
    V1();
    ~V1() override;
};

template <>
void V1::opcode_handler<0x00>();

} // namespace jacky::cpus
