//pluginmanager.h
//

#include "defines.h"
#include <string>
#include <vector>

class CORE_API  PluginInstance
{
public:
  explicit PluginInstance(const std::string& name);
  ~PluginInstance();
  bool Load();
  bool Unload();
  bool IsLoaded() const;
  std::string GetFileName() const;
  std::string GetDisplayName() const;

private:
  PluginInstance(const PluginInstance&);
  const PluginInstance &operator=(const PluginInstance&);
  class Impl;
  Impl *mImpl;
};

class CORE_API PluginManager
{
public:
  static PluginManager& GetInstance();
  bool LoadAll();
  bool Load(const std::string& name);
  bool UnloadAll();
  bool Unload(const std::string& name);
  std::vector<PluginInstance*> GetAllPlugins();

private:
  PluginManager();
  ~PluginManager();
  PluginManager(const PluginManager &);
  const PluginManager & operator=(const PluginManager &);

  std::vector<PluginInstance*> mPlugins;
};

bool PluginInstance::Load()
{
  typedef void (*FuncPtrT)(const char*);
  const char* error;

  // open the dynamic library
  void * handle = dlopen("libplugin.so", RTLD_LOCAL|RTLD_LAZY);
  ///HINSTANCE handle = LoadLibrary("plugin.dll");
  if (! handle) {
    std::cout << "Cannot load plugin!" << std::endl;
    exit(1);
  }
  dlerror();

  // get the DoSmtg() function from plugin
  FuncPtrT fptr = (FuncPtrT) dlsym(handle,"DoSmtg");
  ///FARPROC fptr = GetProcAddress(handle,"DoSmtg");
  if ( (error = dlerror() )) {
    std::cout << "Cannot find function in plugin: " << error << std::endl;
    dlclose(handle);
    ///FreeLibrary(handle);
    exit(1);
  }

  // call function
  (*fptr)("Text");

  // close the shared lib
  dlclose(handle);
  ///FreeLibrary(handle);
}

