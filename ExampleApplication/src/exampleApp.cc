#include <SloppyEngine/SloppyEngine.hpp>

#include <SloppyEngine/SloppyMain.hpp>

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

