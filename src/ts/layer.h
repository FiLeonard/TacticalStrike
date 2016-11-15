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

#include <vector>
#include "../common/point.h"

class Layer
{
    public:
    Layer();
    Layer(int x, int y);
    int GetValue(geo::Point pt);
    int GetValue(int index);

    void Resize(int x, int y);

    void SetValue(int index, int value);
    void SetValue(geo::Point pt, int value);

    protected:
    int PointToIndex(geo::Point pt);

    std::vector<int> m_values;
    int m_x;
    int m_y;
};
