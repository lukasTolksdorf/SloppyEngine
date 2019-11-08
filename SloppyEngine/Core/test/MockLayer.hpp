#ifndef TEST_SLOPPYENGINE_CORE_MOCKLAYER_HPP_
#define TEST_SLOPPYENGINE_CORE_MOCKLAYER_HPP_

#include "SloppyEngine/Core/Layer.hpp"

#include <gmock/gmock.h>

namespace Mocks::Sloppy::Core {

class MockLayer : public ::Sloppy::Core::Layer {
public:
  ~MockLayer() override { onDestruction(); }

  MOCK_METHOD0(onAttach, void());
  MOCK_METHOD0(onDetach, void());
  MOCK_METHOD0(onUpdate, void());
  MOCK_METHOD0(onDestruction, void());

  MOCK_METHOD1(onEvent, void(::Sloppy::Events::Event &));
};
} // namespace Mocks::Sloppy::Core

#endif // TEST_SLOPPYENGINE_CORE_MOCKLAYER_HPP_
