#include "Cavalo.h"

#include <string>

#include "../Tabuleiro.h"

Cavalo::Cavalo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

//Gera uma lista de movimentos possiveis movimentos para a peça
std::vector<Movimento>
Cavalo::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  if (Tabuleiro::isInside({_pos.get_x() + 1, _pos.get_y() + 2}))
  {
    Position pos(_pos.get_x() + 1, _pos.get_y() + 2);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  if (Tabuleiro::isInside({_pos.get_x() + 2, _pos.get_y() + 1}))
  {
    Position pos(_pos.get_x() + 2, _pos.get_y() + 1);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  if (Tabuleiro::isInside({_pos.get_x() + 2, _pos.get_y() - 1}))
  {
    Position pos(_pos.get_x() + 2, _pos.get_y() - 1);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  if (Tabuleiro::isInside({_pos.get_x() + 1, _pos.get_y() - 2}))
  {
    Position pos(_pos.get_x() + 1, _pos.get_y() - 2);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  if (Tabuleiro::isInside({_pos.get_x() - 1, _pos.get_y() - 2}))
  {
    Position pos(_pos.get_x() - 1, _pos.get_y() - 2);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  if (Tabuleiro::isInside({_pos.get_x() - 2, _pos.get_y() - 1}))
  {
    Position pos(_pos.get_x() - 2, _pos.get_y() - 1);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  if (Tabuleiro::isInside({_pos.get_x() - 2, _pos.get_y() + 1}))
  {
    Position pos(_pos.get_x() - 2, _pos.get_y() + 1);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  if (Tabuleiro::isInside({_pos.get_x() - 1, _pos.get_y() + 2}))
  {
    Position pos(_pos.get_x() - 1, _pos.get_y() + 2);
    if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
    {
      movimentos.push_back(Movimento(_pos, pos, false, false));
    }

    else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
    {
      movimentos.push_back(Movimento(_pos, pos, true, false));
    }
  }

  return movimentos;
}