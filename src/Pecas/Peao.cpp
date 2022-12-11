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

  // Detecta movimentos a esquerda da peça

  if (Tabuleiro::isInside({ _pos.get_x() - 1, _pos.get_y() + 1 * sinal }) &&
      tabuleiro[_pos.get_x() - 1][_pos.get_y() + 1 * sinal] != nullptr &&
      tabuleiro[_pos.get_x() - 1][_pos.get_y() + 1 * sinal]->getCor() != _cor)
  {
    movimentos.push_back(Movimento(_pos, { _pos.get_x() - 1, _pos.get_y() + 1 * sinal }, true, false));
  }

  // Detecta movimentos a frente da peça
  if (Tabuleiro::isInside({ _pos.get_x(), _pos.get_y() + 1 * sinal }))
  {
    movimentos.push_back(Movimento(_pos, { _pos.get_x(), _pos.get_y() + 1 * sinal }, false, false));
  }

  // Detecta movimentos a direita da peça
  if (Tabuleiro::isInside({ _pos.get_x() + 1, _pos.get_y() + 1 * sinal }) && 
      tabuleiro[_pos.get_x() + 1][_pos.get_y() + 1 * sinal] != nullptr && 
      tabuleiro[_pos.get_x() + 1][_pos.get_y() + 1 * sinal]->getCor() != _cor)
  {
    movimentos.push_back(Movimento(_pos, { _pos.get_x() + 1, _pos.get_y() + 1 * sinal }, true, false));
  }

  // Caso a peça ainda não tenha se movido, ela pode se mover duas casas
  //TODO: para o primeiro movimento ainda é necessário verificar se é possivel capturar peça tanto a esquerda quanto a direita
  if (!_movimentos)
  {
    movimentos.push_back(Movimento(_pos, { _pos.get_x(), _pos.get_y() + 2 * sinal }, false, false));
  }

  return movimentos;
}