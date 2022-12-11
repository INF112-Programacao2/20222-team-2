#include "Rainha.h"

#include <string>

#include "../Tabuleiro.h"
#include "../globals.h"

Rainha::Rainha(Cor cor, Position pos)
  : Peca(cor, pos, (cor == Cor::BRANCO ? _queenWhiteBmp : _queenBlackBmp))
{
}

std::vector<Movimento>
Rainha::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  // gera movimentos para cima e para a esquerda
  for (int x = _pos.get_x() - 1, y = _pos.get_y() - 1; x >= 0 && y >= 0; --x, --y)
  {
    if (Movimento::geraMovimento(_pos, { x, y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  // gera movimentos para cima e para a direita
  for (int x = _pos.get_x() + 1, y = _pos.get_y() - 1; x <= 7 && y >= 0; ++x, --y)
  {
    if (Movimento::geraMovimento(_pos, { x, y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  // gera movimentos para baixo e para a direita
  for (int x = _pos.get_x() + 1, y = _pos.get_y() + 1; x <= 7 && y <= 7; ++x, ++y)
  {
    if (Movimento::geraMovimento(_pos, { x, y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  // gera movimentos para cima e para a direita
  for (int x = _pos.get_x() - 1, y = _pos.get_y() + 1; x >= 0 && y <= 7; --x, ++y)
  {
    if (Movimento::geraMovimento(_pos, { x, y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  // Movimentos para baixo
  for (int y = _pos.get_y() + 1; y <= 7; ++y)
  {
    if (Movimento::geraMovimento(_pos, { _pos.get_x(), y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  // Movimentos para cima
  for (int y = _pos.get_y() - 1; y >= 0; --y)
  {
    if (Movimento::geraMovimento(_pos, { _pos.get_x(), y }, tabuleiro, movimentos))
    {
      break;
    }
  }
  // Movimentos para a direita
  for (int x = _pos.get_x() + 1; x <= 7; ++x)
  {
    if (Movimento::geraMovimento(_pos, { x, _pos.get_y() }, tabuleiro, movimentos))
    {
      break;
    }
  }
  // Movimentos para a esquerda
  for (int x = _pos.get_x() - 1; x >= 0; --x)
  {
    if (Movimento::geraMovimento(_pos, { x, _pos.get_y() }, tabuleiro, movimentos))
    {
      break;
    }
  }

  return movimentos;
}