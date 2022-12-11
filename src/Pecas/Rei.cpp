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

//Função que retorna se o rei pode roque com a torre
//Se o rei já tiver se movido, não pode roque
//Se a torre já tiver se movido, não pode roque
//Se houver peças entre o rei e a torre, não pode roque
/*bool
Rei::roque(Peca* tabuleiro[8][8])
{
  if (getMovimentos() > 0)
  {
    return false;
  }

  Position torreBranca_1 = Position(0, 7);
  Position torreBranca_2 = Position(7, 7);
  Position torrePreta_1 = Position(0, 0);
  Position torrePreta_2 = Position(7, 0);

  //Verificar na posição das torres se elas já se moveram
  if (tabuleiro[torreBranca_1.get_x()][torreBranca_1.get_y()]->getMovimentos() > 0)
  {
    return false;
  }

  if (tabuleiro[torreBranca_2.get_x()][torreBranca_2.get_y()]->getMovimentos() > 0)
  {
    return false;
  }

  if (tabuleiro[torrePreta_1.get_x()][torrePreta_1.get_y()]->getMovimentos() > 0)
  {
    return false;
  }

  if (tabuleiro[torrePreta_2.get_x()][torrePreta_2.get_y()]->getMovimentos() > 0)
  {
    return false;
  }

  //Verificar se há peças entre o rei e a torre
  if (tabuleiro[torreBranca_1.get_x() + 1][torreBranca_1.get_y()]->getTipo() != Tipo::VAZIO)
  {
    return false;
  }

  if (tabuleiro[torreBranca_1.get_x() + 2][torreBranca_1.get_y()]->getTipo() != Tipo::VAZIO)
  {
    return false;
  }

  if (tabuleiro[torreBranca_2.get_x() - 1][torreBranca_2.get_y()]->getTipo() != Tipo::VAZIO)
  {
    return false;
  }

  if (tabuleiro[torrePreta_1.get_x() + 1][torrePreta_1.get_y()]->getTipo() != Tipo::VAZIO)
  {
    return false;
  }

  if (tabuleiro[torrePreta_1.get_x() + 2][torrePreta_1.get_y()]->getTipo() != Tipo::VAZIO)
  {
    return false;
  }

  if (tabuleiro[torrePreta_2.get_x() - 1][torrePreta_2.get_y()]->getTipo() != Tipo::VAZIO)
  {
    return false;
  }

  //Verificar se o rei está em xeque
  
}*/