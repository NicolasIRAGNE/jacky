/**
 * @file logger.cpp
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @version 0.1
 * @date 2020-12-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "logger.h"
#include <utility>
#include <cassert>
#include <ctime>
#include <sstream>

jacky::LogInfo::LogInfo(std::ostream** outputStream, std::string&& s)
    : stream(outputStream)
    , prefix(std::move(s))
{
}

jacky::Logger::Logger(std::ostream& outStream, std::ostream& errStream, LogLevel level, std::string source)
    : mOutStream(&outStream)
    , mErrStream(&errStream)
    , mLogLevel(level)
    , mSource(source)
    , mLogMap(
          {
              // clang-format off
              { jacky::LogType::Info,        { &mOutStream, std::string("[INFO]   ") } },
              { jacky::LogType::Warning,     { &mErrStream, std::string("[WARN]   ") } },
              { jacky::LogType::Error,       { &mErrStream, std::string("[ERROR]  ") } },
              { jacky::LogType::Fatal,       { &mErrStream, std::string("[FATAL]  ") } },
              { jacky::LogType::Debug,       { &mOutStream, std::string("[DEBUG]  ") } },
              { jacky::LogType::Unspecified, { &mOutStream, std::string("[UNKNOWN]") } },
              // clang-format on
          })
{
}

jacky::Logger::Logger(std::string source)
    : jacky::Logger(std::cout, std::cerr, jacky::DefaultLogLevel, source)
{
}

jacky::Logger::Logger()
    : jacky::Logger(std::string())
{
}

void jacky::Logger::setLogLevel(jacky::LogLevel level)
{
    mLogLevel = level;
}

jacky::LogLevel jacky::Logger::getLogLevel() const
{
    return mLogLevel;
}

void jacky::Logger::setSource(const std::string&& source)
{
    mSource = std::move(source);
}

void jacky::Logger::setSource(const std::string& source)
{
    mSource = source;
}

#ifdef DEBUG
void jacky::Logger::setSourceLevelMode(bool flag)
{
    mSourceLevelMode = flag;
}
#else
void jacky::Logger::setSourceLevelMode(bool flag)
{
    if (flag)
        log_warning("Source level logging is not available: application was not built with debug info");
}
#endif

void jacky::Logger::setOutStream(std::ostream& output)
{
    mOutStream = &output;
}

void jacky::Logger::setErrStream(std::ostream& output)
{
    mErrStream = &output;
}

void jacky::Logger::setStream(std::ostream& output)
{
    setOutStream(output);
    setErrStream(output);
}

void jacky::Logger::setFixedTime(bool flag)
{
    mUsingFixedTime = flag;
}

void jacky::Logger::log(const std::string& s, jacky::LogLevel level, jacky::LogType type) const
{

#ifndef DEBUG
    if (type == jacky::LogType::Debug)
        return;
#endif

    if (level > mLogLevel)
        return;

    assert(mLogMap.count(type) == 1);
    auto info = mLogMap.at(type);

    std::time_t t = mUsingFixedTime ? 0 : std::time(nullptr);
    std::tm* tm = std::localtime(&t);

    char fTime[64];
    strftime(fTime, 64, "[%F %H:%M:%S]", tm);
    **info.stream << info.prefix << " ";
    **info.stream << fTime << " ";
    if (!mSource.empty())
    {
        **info.stream << "<" << mSource << "> ";
    }
    **info.stream << s << std::endl;
}

void jacky::Logger::log_info(const std::string& s, LogLevel level) const
{
    log(s, level, jacky::LogType::Info);
}

void jacky::Logger::log_warning(const std::string& s, LogLevel level) const
{
    log(s, level, jacky::LogType::Warning);
}

void jacky::Logger::log_error(const std::string& s, LogLevel level) const
{
    log(s, level, jacky::LogType::Error);
}

void jacky::Logger::log_fatal(const std::string& s, LogLevel level) const
{
    log(s, level, jacky::LogType::Fatal);
}

void jacky::Logger::log_debug(const std::string& s, LogLevel level) const
{
    log(s, level, jacky::LogType::Debug);
}

void jacky::Logger::log_unspecified(const std::string& s, LogLevel level) const
{
    log(s, level, jacky::LogType::Unspecified);
}

namespace jacky
{
    jacky::Logger logger_g("jacky");
}

jacky::Logger& jacky::logger()
{
    return jacky::logger_g;
}