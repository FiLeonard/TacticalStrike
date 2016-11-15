#include "invasion.h"

VideoManager* Invasion::m_vm = 0;
FPSControl* Invasion::m_fpsc = 0;
ModuleManager* Invasion::m_mm = 0;
//GuiManager* Invasion::m_mm = 0;
bool Invasion::m_autoclean = true;

VideoManager* Invasion::GetVideoManager()
{ return m_vm;};
//GuiManager* GetGuiManager()
//{return m_vm;};
//ModuleManager* Invasion::SetModuleManager()
//{return m_mm;};
FPSControl* Invasion::GetFPSControl()
{return m_fpsc;};

void Invasion::SetAutoClean(bool ac)
{
    m_autoclean = ac;
};
void Invasion::Initialize()
{
    SDL_Init(SDL_INIT_VIDEO);
//	TTF_Init();
	atexit(SDL_Quit);
//	atexit(TTF_Quit);
//	SDL_EnableUNICODE(1);

    m_vm = new VideoManager();
//    m_mm = new ModuleManager();
    m_fpsc = new FPSControl();
//    m_gm = new GuiManager
};

void Invasion::Update()
{
    if(m_fpsc)
    {
       if(m_fpsc->NeedsLogicRefresh())
      {
         m_fpsc->StartLogicTimer();
         m_mm->UpdateModules();
         m_fpsc->StopLogicTimer();
      };

      if(m_fpsc->NeedsGraphicRefresh())
      {
         m_fpsc->StartGraphicTimer();
//         m_vm->update();
         m_fpsc->StopGraphicTimer();
      };

      m_fpsc->Measure();
    };
};

//void Invasion::Clean();
