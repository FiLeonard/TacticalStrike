/*
* Copyright (C) 2007 Leonard Fischer (Crimson-Skies@gmx.de)
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

#ifndef TILESET_H
#define TILESET_H

#include <string>
#include <vector>

#include <guichan.hpp>

class Tileset
{
    public:
        Tileset(std::string file, int width, int height);
        int GetTileWidth()const{return m_tile_width;};
        int GetTileHeight()const{return m_tile_height;};
        void DrawTile(gcn::Graphics* graphics,int index, int x, int y)const;
    protected:
        int m_tile_width;
        int m_tile_height;
        gcn::Image* m_tileset;
};

#endif
