#include "Rei.h"
#include <string>

Rei::Rei(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

bool
Rei::validarMovimento(Position pos) const
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação do Rei
    if (pos.get_x() == _pos.get_x() + 1 || pos.get_x() == _pos.get_x() - 1 ||
        pos.get_y() == _pos.get_y() + 1 || pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }

    else
      return false;
  }
}
