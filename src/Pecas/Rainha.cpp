#include "Pecas/Rainha.h"
#include <string>

Rainha::Rainha(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
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


bool
Rainha::validarMovimento(Position pos) const
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação da rainha
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() + 1 ||
        pos.get_x() == _pos.get_x() - 1 && pos.get_y() == _pos.get_y() + 1 ||
        pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() - 1 ||
             pos.get_x() == _pos.get_x() + 1 && pos.get_y() == _pos.get_y() - 1 ||
             pos.get_y() == _pos.get_y() + 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
