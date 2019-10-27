//
// Created by lukas on 16.10.19.
//

#include "SloppyEngine/Core/Logger.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Sloppy {
namespace Core {

namespace {

class Logger {
public:
  explicit Logger() noexcept
      : coreLogger_(spdlog::stdout_color_mt("SLOPPY")),
        clientLogger_(spdlog::stdout_color_mt("APP")) {

    spdlog::set_pattern("%^[%T] %n: %v%$");
    coreLogger_->set_level(spdlog::level::trace);
    clientLogger_->set_level(spdlog::level::trace);
  }

  std::shared_ptr<spdlog::logger> getCoreLogger() const { return coreLogger_; }

  std::shared_ptr<spdlog::logger> getClientLogger() const {
    return clientLogger_;
  }

private:
  const std::shared_ptr<spdlog::logger> coreLogger_;
  const std::shared_ptr<spdlog::logger> clientLogger_;
};

const Logger logger = Logger();

} // namespace

std::shared_ptr<spdlog::logger> getCoreLogger() { return logger.getCoreLogger(); }

std::shared_ptr<spdlog::logger> getClientLogger() { return logger.getClientLogger(); }

} // namespace Core
} // namespace Sloppy
