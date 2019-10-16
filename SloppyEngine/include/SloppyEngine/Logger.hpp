//
// Created by lukas on 16.10.19.
//

#ifndef SLOPPYENGINE_LOGGER_HPP_
#define SLOPPYENGINE_LOGGER_HPP_

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Sloppy {
namespace Core {

class Logger {
public:
  static void Init();

  static std::shared_ptr<spdlog::logger> getCoreLogger() {
    return coreLogger_;
  }

  static std::shared_ptr<spdlog::logger> getClientLogger() {
    return clientLogger_;
  }

private:
  static std::shared_ptr<spdlog::logger> coreLogger_;
  static std::shared_ptr<spdlog::logger> clientLogger_;
};

}
}

#endif // SLOPPYENGINE_LOGGER_HPP_
