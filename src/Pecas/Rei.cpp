#include "Rei.h"

#include <string>

#include "../Tabuleiro.h"
#include "../globals.h"
#include "Torre.h"

Rei::Rei(Cor cor, Position pos)
  : Peca(cor, pos, (cor == Cor::BRANCO ? _kingWhiteBmp : _kingBlackBmp))
{
}

std::vector<Movimento>
Rei::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  if (getMovimentos() == 0)
  {
    if (roque(tabuleiro, { _pos.get_x() + 3, _pos.get_y() }))
    {
      movimentos.push_back(Movimento(_pos, { _pos.get_x() + 2, _pos.get_y() }, false, false, true));
    }

    if (roque(tabuleiro, { _pos.get_x() - 4, _pos.get_y() }))
    {
      movimentos.push_back(Movimento(_pos, { _pos.get_x() - 2, _pos.get_y() }, false, false, true));
    }
  }

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

bool
Rei::roque(Peca* tabuleiro[8][8], Position posTorre) const
{
  //Posições das torres
  //Torre branca 1: (0, 7)
  //Torre branca 2: (7, 7)
  //Torre preta 1: (0, 0)
  //Torre preta 2: (7, 0)

  int x = posTorre.get_x();
  int y = posTorre.get_y();

  if (tabuleiro[x][y] != nullptr && tabuleiro[x][y]->getMovimentos() > 0)
  {
    return false;
  }

  if (x != 0 && x != 7)
  {
    return false;
  }

  if (y != 0 && y != 7)
  {
    return false;
  }

  //Roque Maior
  if (x == 0)
  {
    if (tabuleiro[1][y] != nullptr || tabuleiro[2][y] != nullptr || tabuleiro[3][y] != nullptr)
    {
      return false;
    }
  }
  //Roque
  else
  {
    if (tabuleiro[5][y] != nullptr || tabuleiro[6][y] != nullptr)
    {
      return false;
    }
  }

  return true;
}