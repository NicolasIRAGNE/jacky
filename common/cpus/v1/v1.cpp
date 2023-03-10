/**
 * @file v1.cpp
 * @author Nicolas IRAGNE (nicoragne@hotmail.fr)
 * @brief V1 CPU. Very basic CPU with only 1 register and a few instructions.
 * @date 2023-03-10
 *
 * @copyright Copyright niragne (c) 2023
 */

#include "v1.h"
#include <spdlog/spdlog.h>

namespace jacky::cpus
{

V1::V1()
{
    spdlog::info("Initializing V1 CPU...");
}

V1::~V1()
{
    spdlog::info("Destroying V1 CPU");
}

} // namespace jacky::cpus