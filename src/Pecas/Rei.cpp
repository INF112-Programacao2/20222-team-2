#include "Rei.h"

#include <string>

#include "../Tabuleiro.h"


Rei::Rei(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

std::vector<Movimento>
Rei::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
 std::vector<Movimento> movimentos;
  if (Tabuleiro::isInside (Position(_pos.get_x() + 1, _pos.get_y() + 1)))
  {
    if (tabuleiro[_pos.get_x() + 1][_pos.get_y() + 1] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, {_pos.get_x() + 1, _pos.get_y() + 1}, false, false));
    }
    else if (tabuleiro[_pos.get_x() + 1][_pos.get_y() + 1]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, {_pos.get_x() + 1, _pos.get_y() + 1}, false, false));
    }
  }
  if (Tabuleiro::isInside (Position(_pos.get_x() + 1, _pos.get_y() - 1)))
  {
    if (tabuleiro[_pos.get_x() + 1][_pos.get_y() - 1] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, {_pos.get_x() + 1, _pos.get_y() - 1}, false, false));
    }
    else if (tabuleiro[_pos.get_x() + 1][_pos.get_y() - 1]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + 1, _pos.get_y() - 1), false, false));
    }
  }
  if (Tabuleiro::isInside (Position(_pos.get_x() - 1, _pos.get_y() + 1)))
  {
    if (tabuleiro[_pos.get_x() - 1][_pos.get_y() + 1] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - 1, _pos.get_y() + 1), false, false));
    }
    else if (tabuleiro[_pos.get_x() - 1][_pos.get_y() + 1]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - 1, _pos.get_y() + 1), false, false));
    }
  }
  if (Tabuleiro::isInside (Position(_pos.get_x() - 1, _pos.get_y() - 1)))
  {
    if (tabuleiro[_pos.get_x() - 1][_pos.get_y() - 1] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - 1, _pos.get_y() - 1), false, false));
    }
    else if (tabuleiro[_pos.get_x() - 1][_pos.get_y() - 1]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - 1, _pos.get_y() - 1), false, false));
    }
  }
  if (Tabuleiro::isInside (Position(_pos.get_x() + 1, _pos.get_y())))
  {
    if (tabuleiro[_pos.get_x() + 1][_pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + 1, _pos.get_y()), false, false));
    }
    else if (tabuleiro[_pos.get_x() + 1][_pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + 1, _pos.get_y()), false, false));
    }
  }
  if (Tabuleiro::isInside (Position(_pos.get_x() - 1, _pos.get_y())))
  {
    if (tabuleiro[_pos.get_x() - 1][_pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - 1, _pos.get_y()), false, false));
    }
    else if (tabuleiro[_pos.get_x() - 1][_pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - 1, _pos.get_y()), false, false));
    }
  }
  if (Tabuleiro::isInside (Position(_pos.get_x(), _pos.get_y() + 1)))
  {
    if (tabuleiro[_pos.get_x()][_pos.get_y() + 1] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() + 1), false, false));
    }
    else if (tabuleiro[_pos.get_x()][_pos.get_y() + 1]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() + 1), false, false));
    }
  }
  if (Tabuleiro::isInside (Position(_pos.get_x(), _pos.get_y() - 1)))
  {
    if (tabuleiro[_pos.get_x()][_pos.get_y() - 1] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() - 1), false, false));
    }
    else if (tabuleiro[_pos.get_x()][_pos.get_y() - 1]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() - 1), false, false));
    }
  }
  return movimentos;
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
