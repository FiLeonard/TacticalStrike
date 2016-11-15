#include "modulemanager.h"

void ModuleManager::AddModule(std::string name, Module* module)
{
   ModuleHolder* ptr = new ModuleHolder;
   m_modules[name] = ptr;
   ptr->m_module = module;
   ptr->m_state = UNLOADED;
   ptr->m_module->SetManager(this);
};

void ModuleManager::RemoveModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   {
      delete iter->second;
      m_modules.erase(iter);
   };
};

void ModuleManager::StartModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   iter->second->m_state = RUNNING;
};

void ModuleManager::StartModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   iter->second->m_state = RUNNING;
};

void ModuleManager::HaltModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   iter->second->m_state = LOADED;
};

void ModuleManager::HaltModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   if(iter->second->m_state == RUNNING)
   iter->second->m_state = LOADED;
};

bool ModuleManager::LoadModule(std::string name)
{

   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end() && iter->second->m_state == UNLOADED)
   {
      if(iter->second->m_module->Load())
      {
         iter->second->m_state = LOADED;
         return 1;
      } else
      return 0;
   };
   return 0;
};

void ModuleManager::LoadModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   {
      if(iter->second->m_state == UNLOADED)
      {
         iter->second->m_module->Load();
         iter->second->m_state = LOADED;
      };
   };
};

bool ModuleManager::UnloadModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end() && iter->second->m_state == LOADED)
   {
      if(iter->second->m_module->Unload())
      {
         iter->second->m_state = UNLOADED;
         return 1;
      } else
      return 0;
   };
   return 0;
};

void ModuleManager::UnloadModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   {
      if(iter->second->m_state == LOADED)
      {
         iter->second->m_module->Unload();
         iter->second->m_state = UNLOADED;
      };
   };
};

int ModuleManager::GetModuleState(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   return iter->second->m_state;
   else
   return (-1);
};

bool ModuleManager::UpdateModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end() && iter->second->m_state == RUNNING)
   return iter->second->m_module->Update();
   else
   return 0;
};

void ModuleManager::UpdateModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   if(iter->second->m_state == RUNNING)
   iter->second->m_module->Update();
};

void* ModuleManager::AskFor(std::string name, std::string data)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   return iter->second->m_module->AskFor(data);
   else
   return 0;
};

void ModuleManager::SentSignal(std::string name)
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   iter->second->m_module->GetSignal(name);
};


