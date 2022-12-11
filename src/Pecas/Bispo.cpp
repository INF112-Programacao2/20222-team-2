#include "Pecas/Bispo.h"
#include <string>
#include "Tabuleiro.h"

Bispo::Bispo(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

std::vector<Movimento>
Bispo::gerarMovimentos(Peca* tabuleiro[8][8]) const
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

  return movimentos;
}

bool
Bispo::validarMovimento(Position pos) const
{
  int posauxy = _pos.get_y() - pos.get_y();
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação do Bispo
    if ((pos.get_x() == _pos.get_x() - posauxy && pos.get_y() == _pos.get_y() - posauxy) ||
        (pos.get_x() == _pos.get_x() + posauxy && pos.get_y() == _pos.get_y() + posauxy) ||
        (pos.get_x() == _pos.get_x() + posauxy && pos.get_y() == _pos.get_y() - posauxy) ||
        (pos.get_x() == _pos.get_x() - posauxy && pos.get_y() == _pos.get_y() + posauxy))
    {
      return true;
    }
    else
      return false;
  }
}