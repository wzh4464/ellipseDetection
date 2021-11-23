#include "Find_arcs.hpp"

Arc::Arc(int _flag)
{
    this->flag = _flag;
}

int Arc::getFlag()
{
    return flag;
}

void Arc::setFlag( int _flag )
{
    this->flag = _flag;
}

int Arc::size()
{
    return points.size();
}

void Arc_set::append(Arc * arc)
{
    data->insert(data->end(),arc);
}

// void Arc::add(Point2i* pt)
// {
//     data->insert(data->end(),pt);
//     num ++;
// }