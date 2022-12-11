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