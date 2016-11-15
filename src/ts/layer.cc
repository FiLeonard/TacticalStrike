#include "layer.h"

Layer::Layer()
{
    m_x = 0;
    m_y = 0;
};

Layer::Layer(int x, int y)
{
    Resize(x, y);
};

int Layer::GetValue(geo::Point pt)
{
    return GetValue(PointToIndex(pt));
};

int Layer::GetValue(int index)
{
    return m_values.at(index);
};

void Layer::Resize(int x, int y)
{
    m_x = x;
    m_y = y;
    m_values.resize(x*y);
};

void Layer::SetValue(int index, int value)
{
    if(index < m_values.size() && index >= 0)
    m_values[index] = value;
};
void Layer::SetValue(geo::Point pt, int value)
{
    SetValue(PointToIndex(pt), value);
};

int Layer::PointToIndex(geo::Point pt)
{
    return (pt.m_y * m_x + pt.m_x);
};
