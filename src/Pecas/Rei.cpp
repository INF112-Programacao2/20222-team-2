#include "Rei.h"

#include <string>

#include "../Tabuleiro.h"
#include "../globals.h"

Rei::Rei(Cor cor, Position pos)
  : Peca(cor, pos, (cor == Cor::BRANCO ? _kingWhiteBmp : _kingBlackBmp))
{
}

std::vector<Movimento>
Rei::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  Position p = Position(_pos.get_x() + 1, _pos.get_y() + 1);
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  p = Position(_pos.get_x() + 1, _pos.get_y() - 1);
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  p = Position(_pos.get_x() - 1, _pos.get_y() + 1);
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  p = Position(_pos.get_x() - 1, _pos.get_y() - 1);
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  p = Position(_pos.get_x() + 1, _pos.get_y());
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  p = Position(_pos.get_x() - 1, _pos.get_y());
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  p = Position(_pos.get_x(), _pos.get_y() + 1);
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  p = Position(_pos.get_x(), _pos.get_y() - 1);
  if (Tabuleiro::isInside(p))
  {
    Movimento::geraMovimento(_pos, p, tabuleiro, movimentos);
  }

  return movimentos;
}