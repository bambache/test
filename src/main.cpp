// main.cpp
//

#include "pluginapi.h"
#include <iostream>

class MesaRenderer: public IRenderer
{
public:
  ~MesaRenderer() {}
  bool LoadScene(const char * filename) { return true; }
  void SetViewportSize(int w, int h) {}
  void SetCameraPosition(double x, double y, double z) {}
  void SetLookAt(double x, double y, double z) {}
  void Render() { std::cout << "Mesa Renderer" << std::endl; }
  static IRenderer * Create() { return new MesaRenderer(); }
};


// create a built-in software renderer
RendererFactory::RegisterRenderer("mesa", MesaRenderer::Create);

// discover and load all plugins
PluginManager::GetInstance().LoadAll();

std::vector<PluginInstance *> plugins = PluginManager::GetInstance().GetAllPlugins();

for ( auto& it : plugins ) {
  std::cout << "Plugin: " << it->GetDisplayName() << std::endl;
}
