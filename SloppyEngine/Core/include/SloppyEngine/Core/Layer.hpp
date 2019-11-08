#ifndef SLOPPYENGINE_CORE_LAYER_HPP_
#define SLOPPYENGINE_CORE_LAYER_HPP_

#include "SloppyEngine/Events/Event.hpp"

#include <string>

namespace Sloppy::Core {

class Layer {
public:
  explicit Layer(const std::string &name = "Layer");
  virtual ~Layer() = default;

  virtual void onAttach(){};
  virtual void onDetach(){};
  virtual void onUpdate(){};
  virtual void onEvent(Events::Event &event) = 0;

  const std::string &getName() const { return debugName_; }

protected:
  std::string debugName_;
};
} // namespace Sloppy::Core

#endif // SLOPPYENGINE_CORE_LAYER_HPP_
