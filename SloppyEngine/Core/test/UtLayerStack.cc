#include "MockLayer.hpp"

#include "SloppyEngine/Core/LayerStack.hpp"

#include <array>
#include <gtest/gtest.h>

#define EXPECT_CALL_FOR_LAYER_X(fcnCall, l0num, l1num, l2num, l3num)           \
  EXPECT_CALL(layer0, fcnCall).Times(l0num);                                   \
  EXPECT_CALL(layer1, fcnCall).Times(l1num);                                   \
  EXPECT_CALL(layer2, fcnCall).Times(l2num);                                   \
  EXPECT_CALL(layer3, fcnCall).Times(l3num);

namespace Test::Sloppy::Core {

TEST(UtLayerStack, Destruction) {
  using ::Mocks::Sloppy::Core::MockLayer;

  std::unique_ptr<::Sloppy::Core::Layer> l1_unique =
      std::make_unique<MockLayer>();
  auto l1_raw = l1_unique.get();
  {

    auto stack = ::Sloppy::Core::LayerStack();
    EXPECT_CALL(*dynamic_cast<MockLayer *>(l1_raw), onAttach()).Times(1);
    EXPECT_CALL(*dynamic_cast<MockLayer *>(l1_raw), onDetach()).Times(0);
    EXPECT_CALL(*dynamic_cast<MockLayer *>(l1_raw), onDestruction()).Times(0);
    stack.pushLayer(std::move(l1_unique));

    EXPECT_CALL(*dynamic_cast<MockLayer *>(l1_raw), onAttach()).Times(0);
    EXPECT_CALL(*dynamic_cast<MockLayer *>(l1_raw), onDetach()).Times(1);
    EXPECT_CALL(*dynamic_cast<MockLayer *>(l1_raw), onDestruction()).Times(0);
    l1_unique = std::move(*(stack.popLayer(l1_raw)));
  }
  // l1 going out of scope
  EXPECT_CALL(*dynamic_cast<MockLayer *>(l1_raw), onDestruction()).Times(1);
}


} // namespace Test::Sloppy::Core
