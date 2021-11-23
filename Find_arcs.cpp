#include "Find_arcs.hpp"

Arc::Arc()
{
    num = 0;
    flag = 0;
    data = NULL;
}

void Arc::add(int x, int y)
{
    Point2i* p = new Point2i(x, y);
    data->insert(data->end(),p);
    num ++;
}

void Arc::add(Point2i* pt)
{
    data->insert(data->end(),pt);
    num ++;
}