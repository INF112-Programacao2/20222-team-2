#include "Position.h"

Position::Position(float pos_x, float pos_y)
  : _pos_x(pos_x)
  , _pos_y(pos_y)
{
}

float
Position::get_x()
{
  return _pos_x;
}

float
Position::get_y()
{
  return _pos_y;
}

void
Position::movepeca(float x, float y)
{
  _pos_x = x;
  _pos_y = y;
}