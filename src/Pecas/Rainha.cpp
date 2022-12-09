#include "Pecas/Rainha.h"
#include <string>

Rainha::Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite, std::string tipo)
  : Peca(cor, pos, sprite, tipo)
{
}

bool
Rainha::validarMovimento(Position pos)
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação da rainha
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() + 1 ||
        pos.get_x() == _pos.get_x() - 1 && pos.get_y() == _pos.get_y() + 1 ||
        pos.get_y() == _pos.get_y() - 1)
    {
      _pos = pos;
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() - 1 ||
             pos.get_x() == _pos.get_x() + 1 && pos.get_y() == _pos.get_y() - 1 ||
             pos.get_y() == _pos.get_y() + 1)
    {
      _pos = pos;
      return true;
    }
    else
    {
      return false;
    }
  }
}