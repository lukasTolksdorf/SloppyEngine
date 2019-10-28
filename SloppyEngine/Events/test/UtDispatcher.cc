#include "MockEventHandler.hpp"

#include "SloppyEngine/Events/Dispatcher.hpp"
#include "SloppyEngine/Events/WindowEvents.hpp"

#include "gtest/gtest.h"

namespace test::Sloppy::Events {

/*
 * \test
 *
 * \brief       Correct behaviour of the event dispatch mechanism
 *
 * \description This test verifies if the dispatcher dispatches the events to
 *              to the previously defined functions.
 */
TEST(Dispatcher, DifferentEvents) {

  auto handler = Mock::Sloppy::Events::MockEventHandler();

  auto onEventFcn = [&handler](::Sloppy::Events::Event &e) {
    auto dispatcher = ::Sloppy::Events::Dispatcher(e);

    dispatcher.dispatch<::Sloppy::Events::WindowCloseEvent>(
        [&handler](auto &event) { return handler.handlerFcn1(event); });
    dispatcher.dispatch<::Sloppy::Events::WindowResizeEvent>(
        [&handler](auto &event) { return handler.handlerFcn2(event); });
  };

  auto windowClose = ::Sloppy::Events::WindowCloseEvent();
  auto windowResize = ::Sloppy::Events::WindowResizeEvent(1, 2);

  EXPECT_CALL(handler, handlerFcn1(::testing::_))
      .WillOnce(::testing::Return(true));
  EXPECT_CALL(handler, handlerFcn2(::testing::_)).Times(0);
  onEventFcn(windowClose);

  EXPECT_TRUE(windowClose.handled);
  EXPECT_FALSE(windowResize.handled);

  windowClose.handled = false;

  EXPECT_CALL(handler, handlerFcn1(::testing::_)).Times(0);
  EXPECT_CALL(handler, handlerFcn2(::testing::_))
      .WillOnce(::testing::Return(true));
  onEventFcn(windowResize);

  EXPECT_FALSE(windowClose.handled);
  EXPECT_TRUE(windowResize.handled);
}

} // namespace test::Sloppy::Events
