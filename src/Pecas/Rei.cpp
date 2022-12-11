#include "Rei.h"

#include <string>

#include "../Tabuleiro.h"

#include <string>

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