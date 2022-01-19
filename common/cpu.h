/**
 * @file cpu.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief
 * @date 2022-01-19
 *
 * @copyright Copyright Alyce (c) 2022
 */

#include <cstdint>
#include <vector>
#include "register.h"

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
        std::vector<uint8_t> memory;
        bool running;
        jacky::Register16 pc;
        jacky::Register16 sp;
        int step();
    };
}