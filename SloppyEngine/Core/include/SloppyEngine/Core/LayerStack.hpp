#ifndef SLOPPYENGINE_CORE_LAYERSTACK_HPP_
#define SLOPPYENGINE_CORE_LAYERSTACK_HPP_

#include "SloppyEngine/Core/Layer.hpp"

#include <memory>
#include <optional>
#include <vector>

namespace Sloppy::Core {
class LayerStack {
public:
  LayerStack();
  ~LayerStack();

  void pushLayer(std::unique_ptr<Layer> &&layer);
  void pushOverlay(std::unique_ptr<Layer> &&layer);
  std::optional<std::vector<std::unique_ptr<Layer>>::iterator>
  findLayer(Layer *layer);
  std::optional<std::unique_ptr<Layer>> popLayer(Layer *layer);
  std::optional<std::unique_ptr<Layer>> popOverlay(Layer *layer);

  std::vector<std::unique_ptr<Layer>>::iterator begin();
  std::vector<std::unique_ptr<Layer>>::iterator end();

private:
  std::vector<std::unique_ptr<Layer>> layers_;
  unsigned int layerInsertIndex_;
};

} // namespace Sloppy::Core

#endif // SLOPPYENGINE_CORE_LAYERSTACK_HPP_
