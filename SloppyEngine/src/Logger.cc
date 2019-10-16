//
// Created by lukas on 16.10.19.
//

#include "SloppyEngine/Logger.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Sloppy {
namespace Core {

std::shared_ptr<spdlog::logger> Logger::coreLogger_;
std::shared_ptr<spdlog::logger> Logger::clientLogger_;

void Logger::Init() {

  spdlog::set_pattern("%^[%T] %n: %v%$");
  coreLogger_ = spdlog::stdout_color_mt("SLOPPY");
  coreLogger_->set_level(spdlog::level::trace);

  clientLogger_ = spdlog::stdout_color_mt("APP");
  clientLogger_->set_level(spdlog::level::trace);
}
} // namespace Core
} // namespace Sloppy
