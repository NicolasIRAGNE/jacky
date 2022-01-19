/**
 * @file main.cpp
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2022-01-19
 * 
 * @copyright Copyright Alyce (c) 2022
 */

#include "logger.h"
#include "jacky-exec.h"

namespace jacky
{
    namespace exec
    {
        jacky::Logger logger_g("jacky-exec");
    }
}

jacky::Logger& jacky::exec::logger()
{
    return jacky::exec::logger_g;
}

int main(int argc, char **argv)
{
    jacky::exec::logger().log_info("Initializing jacky-exec...");
    jacky::exec::logger().log_info("Done.");
    return 0;
}