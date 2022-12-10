#include "Pecas/Cavalo.h"
#include <string>

Cavalo::Cavalo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

std::vector<Movimento>
Cavalo::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;
  return movimentos;
}

bool
Cavalo::validarMovimento(Position pos) const
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação do Cavalo
    if (pos.get_x() == _pos.get_x() + 1 && pos.get_y() == _pos.get_y() + 2 ||
        pos.get_x() == _pos.get_x() + 2 && pos.get_y() == _pos.get_y() + 1 ||
        pos.get_x() == _pos.get_x() + 2 && pos.get_y() == _pos.get_y() - 1 ||
        pos.get_x() == _pos.get_x() + 1 && pos.get_y() == _pos.get_y() - 2 ||
        pos.get_x() == _pos.get_x() - 1 && pos.get_y() == _pos.get_y() - 2 ||
        pos.get_x() == _pos.get_x() - 2 && pos.get_y() == _pos.get_y() - 1 ||
        pos.get_x() == _pos.get_x() - 2 && pos.get_y() == _pos.get_y() + 1 ||
        pos.get_x() == _pos.get_x() - 1 && pos.get_y() == _pos.get_y() + 2)
    {
      return true;
    }

    else
      return false;
  }
}
