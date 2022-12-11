#include "Torre.h"

#include <string>

#include "../Tabuleiro.h"
#include "../globals.h"

Torre::Torre(Cor cor, Position pos)
  : Peca(cor, pos, (cor == Cor::BRANCO ? _rookWhiteBmp : _rookBlackBmp))
{
}

std::vector<Movimento>
Torre::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  //Movimentos para baixo
  for (int y = _pos.get_y() + 1; y <= 7; ++y)
  {
    if (Movimento::geraMovimento(_pos, { _pos.get_x(), y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  //Movimentos para cima
  for (int y = _pos.get_y() - 1; y >= 0; --y)
  {
    if (Movimento::geraMovimento(_pos, { _pos.get_x(), y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  //Movimentos para a direita
  for (int x = _pos.get_x() + 1; x <= 7; ++x)
  {
    if (Movimento::geraMovimento(_pos, { x, _pos.get_y() }, tabuleiro, movimentos))
    {
      break;
    }
  }
  //Movimentos para a esquerda
  for (int x = _pos.get_x() - 1; x >= 0; --x)
  {
    if (Movimento::geraMovimento(_pos, { x, _pos.get_y() }, tabuleiro, movimentos))
    {
      break;
    }
  }

  return movimentos;
}