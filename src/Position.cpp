#include "Position.h"

Position::Position(int pos_x, int pos_y)
  : _pos_x(pos_x)
  , _pos_y(pos_y)
{
}

int
Position::get_x() const
{
  return _pos_x;
}

int
Position::get_y() const
{
  return _pos_y;
}

void
Position::movepeca(int x, int y)
{
  _pos_x = x;
  _pos_y = y;
}