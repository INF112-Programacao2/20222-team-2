#include "Pecas/Bispo.h"
#include <string>

Bispo::Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

bool
Bispo::validarMovimento(Position pos) const
{
  int mov_bispox = _pos.get_x() - pos.get_x();
  int mov_bispoy = _pos.get_y() - pos.get_y();
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação do Bispo
    if (pos.get_x() == _pos.get_x() + mov_bispox && pos.get_y() == _pos.get_y() + mov_bispoy ||
        pos.get_x() == _pos.get_x() - mov_bispox && pos.get_y() == _pos.get_y() - mov_bispoy ||
        pos.get_x() == _pos.get_x() - mov_bispox && pos.get_y() == _pos.get_y() + mov_bispoy ||
        pos.get_x() == _pos.get_x() + mov_bispox && pos.get_y() == _pos.get_y() - mov_bispoy)
    {
      return true;
    }
    else
      return false;
  }
}
