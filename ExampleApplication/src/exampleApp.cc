#include <SloppyEngine/Core/SloppyEngine.hpp>

#include <SloppyEngine/Core/SloppyMain.hpp>

class ExampleApp : public Sloppy::Application
{
public:
  ExampleApp() {
    SLPY_INFO("Created App");
  }

  ~ExampleApp() override = default;
};

Sloppy::Application* Sloppy::CreateApplication() {
  return new ExampleApp();
}

