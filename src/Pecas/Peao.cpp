#include "Peao.h"

#include <string>

#include "../Tabuleiro.h"
#include "../globals.h"

Peao::Peao(Cor cor, Position pos)
  : Peca(cor, pos, (cor == Cor::BRANCO ? _pawnWhiteBmp : _pawnBlackBmp))
{
}

std::vector<Movimento>
Peao::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  // o sinal é usado para mover o peão apenas para cima ou apenas para baixo, dependendo de sua cor
  int sinal = (_cor == Cor::BRANCO ? -1 : 1); // Operador ternario

  Position posFrente = { _pos.get_x(), _pos.get_y() + 1 * sinal };
  Position posFrente2 = { _pos.get_x(), _pos.get_y() + 2 * sinal };
  Position diagEsq = { _pos.get_x() - 1, _pos.get_y() + 1 * sinal };
  Position diagDir = { _pos.get_x() + 1, _pos.get_y() + 1 * sinal };

  // se não houver peça na frente do peão
  if (!tabuleiro[posFrente.get_x()][posFrente.get_y()])
  {
    Movimento::geraMovimento(_pos, posFrente, tabuleiro, movimentos);
    if (!_seMovimentou)
    {
      if (!tabuleiro[posFrente2.get_x()][posFrente2.get_y()])
      {
        Movimento::geraMovimento(_pos, posFrente2, tabuleiro, movimentos);
      }
    }
  }

  // Detecta movimentos a esquerda da peça
  if (Tabuleiro::isInside(diagEsq))
  {
    Peca* pecaEsquerda = tabuleiro[diagEsq.get_x()][diagEsq.get_y()];
    if (pecaEsquerda && pecaEsquerda->getCor() != _cor)
    {
      Movimento::geraMovimento(_pos, diagEsq, tabuleiro, movimentos);
    }
  }

  // Detecta movimentos a direita da peça
  if (Tabuleiro::isInside(diagDir) && tabuleiro[diagDir.get_x()][diagDir.get_y()])
  {
    Movimento::geraMovimento(_pos, diagDir, tabuleiro, movimentos);
  }

  return movimentos;
}