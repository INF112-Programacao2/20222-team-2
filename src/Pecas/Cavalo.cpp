#include "Cavalo.h"

#include <string>

#include "../Tabuleiro.h"
#include "../Movimento.h"
#include "../globals.h"

Cavalo::Cavalo(Cor cor, Position pos)
  : Peca(cor, pos, (cor == Cor::BRANCO ? _knightWhiteBmp : _knightBlackBmp))
{
}

// Gera uma lista de movimentos possiveis movimentos para a peça
std::vector<Movimento>
Cavalo::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  Position pos = { _pos.get_x() + 1, _pos.get_y() + 2 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  pos = { _pos.get_x() + 2, _pos.get_y() + 1 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  pos = { _pos.get_x() + 2, _pos.get_y() - 1 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  pos = { _pos.get_x() + 1, _pos.get_y() - 2 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  pos = { _pos.get_x() - 1, _pos.get_y() - 2 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  pos = { _pos.get_x() - 2, _pos.get_y() - 1 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  pos = { _pos.get_x() - 2, _pos.get_y() + 1 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  pos = { _pos.get_x() - 1, _pos.get_y() + 2 };
  if (Tabuleiro::isInside(pos))
  {
    Movimento::geraMovimento(_pos, pos, tabuleiro, movimentos);
  }

  return movimentos;
}