/* minup - yet another pong-like game
 *
 * Copyright (C) 2005 Leonard Fischer (Crimson-Skies@gmx.de)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include <list>
#include <guichan.hpp>
#include <string>

class VideoModule
{
   public:
   virtual ~VideoModule(){};
   virtual void Draw() = 0;
};

class VideoManager
{
   public:
   VideoManager();
   virtual ~VideoManager();
   bool Load();
   bool Unload();
   bool Update();
   void SetGraphics(gcn::Graphics* graphics);

   void AddVideoModule(VideoModule* ptr);
   void RemoveVideoModule(VideoModule* ptr);
   void ClearVideoModules();

   protected:
   std::list<VideoModule*> m_videomodules;
   std::list<VideoModule*>::iterator m_iter;
   gcn::Graphics* m_graphics;
};

#endif
