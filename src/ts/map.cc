#include "map.h"

geo::Point Map::InTile(geo::Point pt)
{
    pt.m_x -=m_offset.m_x;
    pt.m_y -=m_offset.m_y;
    int r = pt.m_y / m_tileset->GetTileHeight();
    int c = pt.m_x / m_tileset->GetTileWidth();
    return geo::Point(c,r);
};

int Map::PointToIndex(geo::Point pt)
{
    return (pt.m_y * m_dimensions.m_x + pt.m_x);
};


geo::Point Map::IndexToPoint(int index)
{
    int x = index % m_dimensions.m_x;
    int y = index / m_dimensions.m_x;
    return geo::Point(x,y);
};
