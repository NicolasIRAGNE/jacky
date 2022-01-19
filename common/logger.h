/**
 * @file logger.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief A simple custom logger for jacky. Features different logging levels and types.
 * @version 0.1
 * @date 2020-12-03
 * 
 * @copyright Copyright (c) 2020
 * 
 * Using the logger is not very convenient right now, because of how C++ handles string conversions.
 * This could be a lot better by using C++20 std::format or even using a library like boost::log or spdlog.
 * 
 */

#pragma once
#include <iostream>
#include <map>

namespace jacky
{

typedef unsigned int LogLevel;

/// The default level that is set when none is specified.
constexpr LogLevel DefaultLogLevel = 3;

namespace LogLevels
{
    enum Common
    {
        General = 1,
        Technical
    };
}

enum class LogType
{
    /// General information messages. The most common log level.
    Info,

    /// Usually benign problems or abnormal events that do not cause the program to end.
    Warning,

    /// When something bad happened but the program can still continue.
    Error,

    /// Serious errors that cause program execution.
    Fatal,

    /// Only printed when the program was built in debug mode.
    Debug,

    /// Weird stuff
    Unspecified
};

/**
 *  Used by the logger to know where to log and what prefix to prepend
 */
struct LogInfo
{
    std::ostream** stream;
    std::string prefix;
    LogInfo(std::ostream** outputStream, std::string&& s);
};

/// A simple synchronous logger.
class Logger
{
public:
    /**
     * @brief Construct a new Logger
     * 
     * @param outStream Where to output standard logs (std::cout by default)
     * @param errStream Where to output error logs (std::cerr by default)
     * @param level The level that specifies which messages should be logged or ignored
     * @param source Name of the application that invokes the logger
     */
    Logger(std::ostream& outStream, std::ostream& errStream, LogLevel level, std::string source);
    Logger(std::string source);
    Logger();

    /**
     * Logs a message according to the specified info.
     * 
     * @param s The message to log
     * @param level The level at which the message should be logged
     * @param type The type of message
     * @param source_file The name of the file from which the logger was invoked
     * @param source_line The number of the file line from which the logger was invoked
     * @see LogInfo
     */
    void log(const std::string& s, LogLevel level, LogType type) const;

    /// Logs an info message.
    void log_info(const std::string& s, LogLevel level = 1) const;
    /// Logs a warning message.
    void log_warning(const std::string& s, LogLevel level = 1) const;
    /// Logs a error message.
    void log_error(const std::string& s, LogLevel level = 1) const;
    /// Logs a fatal message.
    void log_fatal(const std::string& s, LogLevel level = 1) const;
    /// Logs a debug message.
    void log_debug(const std::string& s, LogLevel level = 1) const;
    /// Logs an unspecified message.
    void log_unspecified(const std::string& s, LogLevel level = 1) const;

    void setLogLevel(LogLevel level);
    LogLevel getLogLevel() const;
    /// Indicates the origin of the log. This is usually the name of the library or application that uses the logger.
    void setSource(const std::string&& source);
    /// Indicates the origin of the log. This is usually the name of the library or application that uses the logger.
    void setSource(const std::string& source);
    /// Toggles source level logging on or off.
    void setSourceLevelMode(bool flag);
    /// Sets the logger standard output
    void setOutStream(std::ostream& output);
    /// Sets the logger error output
    void setErrStream(std::ostream& output);
    /// Sets both logger outputs (equivalent to calling both setOutStream and setErrStream)
    void setStream(std::ostream& output);
    /// Sets the timestamp to unix epoch
    void setFixedTime(bool flag);

private:
    std::ostream* mOutStream;
    std::ostream* mErrStream;
    LogLevel mLogLevel;
    std::string mSource;
    const std::map<LogType, LogInfo> mLogMap;
    bool mSourceLevelMode { false };
    bool mUsingFixedTime { false };
};

/// @return a reference to the logger used by libjacky
jacky::Logger& logger();

}