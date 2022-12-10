#include "Pecas/Rainha.h"
#include <string>

Rainha::Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

bool
Rainha::validarMovimento(Position pos) const
{ 
  int mov_rainhax = _pos.get_x() - pos.get_x();
  int mov_rainhay = _pos.get_y() - pos.get_y();

  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação da rainha
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() + mov_rainhax ||
        pos.get_x() == _pos.get_x() - mov_rainhax && pos.get_y() == _pos.get_y() + mov_rainhay ||
        pos.get_y() == _pos.get_y() - mov_rainhay)
    {
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() - mov_rainhax ||
             pos.get_x() == _pos.get_x() + mov_rainhax && pos.get_y() == _pos.get_y() - mov_rainhay ||
             pos.get_y() == _pos.get_y() + mov_rainhay)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
