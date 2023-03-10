/**
 * @file main.cpp
 * @author Nicolas IRAGNE (nicoragne@hotmail.fr)
 * @brief
 * @date 2022-01-19
 *
 * @copyright Copyright niragne (c) 2022
 */

#include "exec.h"
#include <spdlog/spdlog.h>
#include "cpu.h"
#include "cpus/v1/v1.h"
#include <limits>

int main()
{
    spdlog::info("Hello, World!");
    auto v1 = jacky::cpus::V1();
    std::vector<jacky::opcode_t> program = {
        0x00, 0x00, 0x00, 0x00, // NOP
        0x01,
    };
    for (auto& opcode : program)
    {
        try
        {
            v1.execute(opcode);
        }
        catch (const std::exception& e)
        {
            spdlog::error("Error: {}", e.what());
        }
    }
    return 0;
}