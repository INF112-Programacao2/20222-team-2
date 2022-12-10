#include "Pecas/Torre.h"

#include <string>

#include "Tabuleiro.h"

Torre::Torre(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

std::vector<Movimento>
Torre::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  //Movimentos para a baixo
  for (int i = 1; i < 8; i++)
  {
    if (Tabuleiro::isInside({_pos.get_x(), _pos.get_y() + i}))
    {
      Position pos(_pos.get_x(), _pos.get_y() + i);
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }

      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }

      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor)
      {
        break;
      }
    }
  }

  //Movimentos para a cima
  for (int i = 1; i < 8; i++)
  {
    if (Tabuleiro::isInside({_pos.get_x(), _pos.get_y() - i}))
    {
      Position pos(_pos.get_x(), _pos.get_y() - i);
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }

      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }

      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor)
      {
        break;
      }
    }
  }

  //Movimentos para direita
  for (int i = 1; i < 8; i++)
  {
    if (Tabuleiro::isInside({_pos.get_x() + i, _pos.get_y()}))
    {
      Position pos(_pos.get_x() + i, _pos.get_y());
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }
      
      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }

      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor)
      {
        break;
      }
    }
  }

  //Movimentos para esquerda
  for (int i = 1; i < 8; i++)
  {
    if (Tabuleiro::isInside({_pos.get_x() - i, _pos.get_y()}))
    {
      Position pos(_pos.get_x() - i, _pos.get_y());
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }

      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }

      else if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor)
      {
        break;
      }
    }
  }

  return movimentos;
}

bool
Torre::validarMovimento(Position pos) const
{
  int pos_aux_x = pos.get_x();
  int pos_aux_y = pos.get_y() - _pos.get_y();
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação da Torre
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() + 1 || pos.get_x() == _pos.get_x() - 1 ||
        pos.get_y() == _pos.get_y() + 1 || pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() + pos_aux_x ||
             pos.get_x() == _pos.get_x() - pos_aux_x || pos.get_y() == _pos.get_y() + pos_aux_y ||
             pos.get_y() == _pos.get_y() - pos_aux_y)
    {
      return true;
    }
    else
      return false;
  }
}
