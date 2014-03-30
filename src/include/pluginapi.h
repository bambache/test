// pluginapi.h
//

#include "defines.h"
#include "renderer.h"

#define CORE_FUNC extern "C" CORE_API
#define PLUGIN_FUNC extern "C" PLUGIN_API

#define PLUGIN_API_VERSION 1

// Alternative use min and max versions
#define PLUGIN_MIN_VERSION(version)\
  PLUGIN_API int PluginMinVersion = version;

#define PLUGIN_MAX_VERSION(version)\
  PLUGIN_API int PluginMaxVersion = version;

#define PLUGIN_INIT()\
  const int PluginVersion = PLUGIN_API_VERSION;\
  PLUGIN_FUNC int PluginInit()

#define PLUGIN_FREE() PLUGIN_FUNC int PluginFree()

typedef IRenderer *(*RendererInitFunc)();
typedef void       (*RendererFreeFunc)(IRenderer*);

CORE_FUNC void RegisterRenderer(const char * type,
                                RendererInitFunc init_callback,
                                RendererFreeFunc free_callback);
