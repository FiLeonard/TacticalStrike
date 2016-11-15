#include "videomanager.h"

bool VideoManager::Load()
{
   m_graphics = 0;
   return 1;
};

bool VideoManager::Unload()
{
	m_graphics = 0;
	ClearVideoModules();
	return 1;
};

bool VideoManager::Update()
{
    for(m_iter = m_videomodules.begin(); m_iter != m_videomodules.end(); m_iter ++)
    {
//        (*m_iter)->Draw(m_graphics);
    };
    return true;
};

void VideoManager::SetGraphics(gcn::Graphics* graphics)
{
	m_graphics = graphics;
};

VideoManager::VideoManager()
{
	m_graphics = 0;
};

VideoManager::~VideoManager()
{
	Unload();
};

void VideoManager::AddVideoModule(VideoModule* ptr)
{
	m_videomodules.push_back(ptr);
};

void VideoManager::RemoveVideoModule(VideoModule* ptr)
{
	m_videomodules.remove(ptr);
};

void VideoManager::ClearVideoModules()
{
   m_videomodules.clear();
};

