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
Peca::getCor()
{
  return _cor;
}

Position
Peca::setpos(Position pos)
{
  _pos = pos;
  return _pos;
}

int
Peca::getTurno()
{
  return turno;
}

void
Peca::setTurno(int turno)
{
  this->turno = turno;
}

void
Peca::trocarTurno()
{
  if (turno == 1)
  {
    turno = 2;
  }
  else
  {
    turno = 1;
  }
}

bool
Peca::validarMovimento(Position pos)
{}