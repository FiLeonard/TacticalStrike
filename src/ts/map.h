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

#ifndef MAP_H
#define MAP_H

#include "../common/point.h"
#include <guichan.hpp>
#include "layer.h"
#include "tileset.h"

class Map
{
    public:

        void draw(gcn::Graphics* graphics);

        geo::Point InTile(geo::Point pt);

        int PointToIndex(geo::Point pt);
        geo::Point IndexToPoint(int index);

        bool CheckPoint(geo::Point pt);
        bool CheckIndex(geo::Point pt);

    protected:
        geo::Point m_offset;
        geo::Point m_dimensions;

        Tileset* m_tileset;
        Layer* m_tilelayer;
};
#endif
