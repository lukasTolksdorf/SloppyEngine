#ifndef SLOPPYENGINE_SLOPPYMAIN_HPP_
#define SLOPPYENGINE_SLOPPYMAIN_HPP_

extern Sloppy::Application* Sloppy::CreateApplication();

int main(int argc, char **argv) {
  SLPY_CORE_INFO("About to create the application");

  auto app = ::Sloppy::CreateApplication();
  app->run();
  delete app;

  SLPY_CORE_INFO("Deleted application");
}

#endif // SLOPPYENGINE_SLOPPYMAIN_HPP_
