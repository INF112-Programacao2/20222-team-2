#include "Pecas/Peao.h"
#include <string>

Peao::Peao(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

bool
Peao::validarMovimento(Position pos)
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() && pos.get_y() == _pos.get_y() + 1)
    {
      _pos = pos;
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() && pos.get_y() == _pos.get_y() - 1)
    {
      _pos = pos;
      return true;
    }
    else
      return false;
  }
}
