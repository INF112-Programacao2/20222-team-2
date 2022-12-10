#include "Pecas/Torre.h"
#include <string>

Torre::Torre(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

bool
Torre::validarMovimento(Position pos)
{
  int pos_aux_x = pos.get_x();
  int pos_aux_y = pos.get_y() - _pos.get_y();
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação da Torre
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() + 1 || pos.get_x() == _pos.get_x() - 1 ||
        pos.get_y() == _pos.get_y() + 1 || pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() + pos_aux_x ||
             pos.get_x() == _pos.get_x() - pos_aux_x || pos.get_y() == _pos.get_y() + pos_aux_y ||
             pos.get_y() == _pos.get_y() - pos_aux_y)
    {
      return true;
    }
    else
      return false;
  }
}
