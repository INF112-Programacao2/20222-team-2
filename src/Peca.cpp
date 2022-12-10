#include "Peca.h"
#include "constants.h"
#include <string>

Peca::Peca(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : _cor(cor)
  , _pos(pos)
  , _sprite(sprite)
{
}

void
Peca::onRender() const
{
  al_draw_bitmap(_sprite,
                 (float)_pos.get_x() * BOARD_STEP + OFFSET_X,
                 (float)_pos.get_y() * BOARD_STEP + OFFSET_Y,
                 0);
}

Cor
Peca::getCor() const
{
  return _cor;
}

Position
Peca::setPos(Position pos)
{
  _pos = pos;
  return _pos;
}

Position
Peca::getPos() const
{
  return _pos;
}