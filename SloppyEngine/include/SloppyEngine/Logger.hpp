//
// Created by lukas on 16.10.19.
//

#ifndef SLOPPYENGINE_LOGGER_HPP_
#define SLOPPYENGINE_LOGGER_HPP_

#include "SloppyEngine.hpp"
#include "spdlog/spdlog.h"

namespace Sloppy {
namespace Core {

std::shared_ptr<spdlog::logger> getCoreLogger();
std::shared_ptr<spdlog::logger> getClientLogger();

} // namespace Core
} // namespace Sloppy

// clang-format off
#define SLPY_CORE_TRACE(...)     ::Sloppy::Core::getCoreLogger()->trace(__VA_ARGS__)
#define SLPY_CORE_INFO(...)      ::Sloppy::Core::getCoreLogger()->info(__VA_ARGS__)
#define SLPY_CORE_WARN(...)      ::Sloppy::Core::getCoreLogger()->warn(__VA_ARGS__)
#define SLPY_CORE_ERROR(...)     ::Sloppy::Core::getCoreLogger()->error(__VA_ARGS__)
#define SLPY_CORE_CRITICAL(...)  ::Sloppy::Core::getCoreLogger()->critical(__VA_ARGS__)

#define SLPY_TRACE(...)     ::Sloppy::Core::getClientLogger()->trace(__VA_ARGS__)
#define SLPY_INFO(...)      ::Sloppy::Core::getClientLogger()->info(__VA_ARGS__)
#define SLPY_WARN(...)      ::Sloppy::Core::getClientLogger()->warn(__VA_ARGS__)
#define SLPY_ERROR(...)     ::Sloppy::Core::getClientLogger()->error(__VA_ARGS__)
#define SLPY_CRITICAL(...)  ::Sloppy::Core::getClientLogger()->critical(__VA_ARGS__)
// clang-format on

#endif // SLOPPYENGINE_LOGGER_HPP_
