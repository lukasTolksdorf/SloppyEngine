#ifndef TEST_SLOPPYENGINE_EVENTS_MOCKEVENTHANDLER_HPP_
#define TEST_SLOPPYENGINE_EVENTS_MOCKEVENTHANDLER_HPP_

#include "SloppyEngine/Events/Event.hpp"

#include "gmock/gmock.h"

namespace Mock::Sloppy::Events {

class MockEventHandler {
public:

  virtual ~MockEventHandler();
  MOCK_METHOD1(handlerFcn1, bool(::Sloppy::Events::Event &));
  MOCK_METHOD1(handlerFcn2, bool(::Sloppy::Events::Event &));
};
} // namespace Mock::Sloppy::Events

#endif // TEST_SLOPPYENGINE_EVENTS_MOCKEVENTHANDLER_HPP_
