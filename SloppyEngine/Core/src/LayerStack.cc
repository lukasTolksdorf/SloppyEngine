#include "SloppyEngine/Core/LayerStack.hpp"

#include <algorithm>
#include <optional>

namespace Sloppy::Core {
LayerStack::LayerStack() : layers_(), layerInsertIndex_(0) {
  // intentionally left empty
}

LayerStack::~LayerStack() {
  for (auto &layer : layers_) {
    layer->onDetach();
  }
}

void LayerStack::pushLayer(std::unique_ptr<Layer> &&layer) {
  layer->onAttach();
  layers_.emplace(layers_.begin() + layerInsertIndex_, std::move(layer));
  ++layerInsertIndex_;
}
void LayerStack::pushOverlay(std::unique_ptr<Layer> &&layer) {
  layer->onAttach();
  layers_.emplace_back(std::move(layer));
}

std::optional<std::vector<std::unique_ptr<Layer>>::iterator>
LayerStack::findLayer(Layer *layer) {
  auto position =
      std::find_if(layers_.begin(), layers_.begin() + layerInsertIndex_,
                   [layer](auto &element) { return element.get() == layer; });
  if (position != (layers_.begin() + layerInsertIndex_)) {
    return position;
  } else {
    return std::nullopt;
  }
}

std::optional<std::unique_ptr<Layer>> LayerStack::popLayer(Layer *layer) {
  auto position =
      std::find_if(layers_.begin(), layers_.begin() + layerInsertIndex_,
                   [layer](auto &element) { return element.get() == layer; });
  if (position != layers_.begin() + layerInsertIndex_) {
    auto result = std::move(*position);
    result->onDetach();
    layers_.erase(position);
    return result;
  } else {
    return std::nullopt;
  }
}

std::optional<std::unique_ptr<Layer>> LayerStack::popOverlay(Layer *layer) {
  auto position =
      std::find_if(layers_.begin() + layerInsertIndex_, layers_.end(),
                   [layer](auto &element) { return element.get() == layer; });
  if (position != layers_.end()) {

    auto result = std::move(*position);
    result->onDetach();

    layers_.erase(position);

    return result;
  } else {
    return std::nullopt;
  }
}

std::vector<std::unique_ptr<Layer>>::iterator LayerStack::begin() {
  return layers_.begin();
}
std::vector<std::unique_ptr<Layer>>::iterator LayerStack::end() {
  return layers_.end();
}

} // namespace Sloppy::Core
