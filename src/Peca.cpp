#include "Peca.h"
#include "constants.h"
#include <string>

Peca::Peca(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo)
  : _cor(cor)
  , _pos(pos)
  , _sprite(sprite)
  , _tipo(tipo)
{
}

void
Peca::onRender()
{
  al_draw_bitmap(_sprite,
                 (float)_pos.get_x() * BOARD_STEP + OFFSET_X,
                 (float)_pos.get_y() * BOARD_STEP + OFFSET_Y,
                 0);
}

std::string
Peca::getTipo()
{
  return _tipo;
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
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
    _pos = pos;
  return true;
}
