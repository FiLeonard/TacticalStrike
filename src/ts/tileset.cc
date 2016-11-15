#include "tileset.h"

Tileset::Tileset(std::string file, int width, int height)
{

    m_tileset = gcn::Image::load(file);
    m_tile_width = width;
    m_tile_height = height;
};

void Tileset::DrawTile(gcn::Graphics* graphics, int index, int x, int y) const
{
    if(m_tileset)
    {
        int columns = m_tileset->getWidth()/m_tile_width;
        int rows = m_tileset->getHeight()/m_tile_height;

        int srcx = (index%columns);
        int srcy = (index/columns);
        if(srcx < columns && srcy < rows)
            graphics->drawImage(m_tileset, srcx * m_tile_width, srcy * m_tile_height,
                x, y, m_tile_width, m_tile_height);
    };

};
