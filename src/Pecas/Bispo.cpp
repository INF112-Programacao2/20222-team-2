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
  
  for (int i=0; i<8; i++){
    if (Tabuleiro::isInside({_pos.get_x() + i, _pos.get_y() - i}))
    {
      Position pos({_pos.get_x() + i, _pos.get_y() - i});
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr ||
          tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor){
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor){
        break;
      }
    }
  
  //Movimento +1 para direita e +2 para baixo

    if (Tabuleiro::isInside({_pos.get_x() - i, _pos.get_y() - i}))
    {
      Position pos({_pos.get_x() + i, _pos.get_y() - i});
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr ||
          tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor){
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor){
        break;
      }
    }
  
  //Movimento -1 para esquerda e +2 para baixo

    if (Tabuleiro::isInside({_pos.get_x() - i, _pos.get_y() + i}))
    {
      Position pos({_pos.get_x() + i, _pos.get_y() - i});
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr ||
          tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor){
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor){
        break;
      }
    }
  
  //Movimento -2 para esquerda e +1 para baixo
    if (Tabuleiro::isInside({_pos.get_x() + i, _pos.get_y() + i}))
    {
      Position pos({_pos.get_x() + i, _pos.get_y() - i});
      if (tabuleiro[pos.get_x()][pos.get_y()] == nullptr ||
          tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor)
      {
        movimentos.push_back(Movimento(_pos, pos, false, false));
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() != _cor){
        movimentos.push_back(Movimento(_pos, pos, true, false));
        break;
      }
      if (tabuleiro[pos.get_x()][pos.get_y()]->getCor() == _cor){
        break;
      }
    }
  }

  return movimentos;
}
  

bool
Bispo::validarMovimento(Position pos) const
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }
  else
  {
    // Movimentação do Bispo
    if (pos.get_x() == _pos.get_x() + 1 && pos.get_y() == _pos.get_y() + 1 ||
        pos.get_x() == _pos.get_x() - 1 && pos.get_y() == _pos.get_y() - 1 ||
        pos.get_x() == _pos.get_x() - 1 && pos.get_y() == _pos.get_y() + 1 ||
        pos.get_x() == _pos.get_x() + 1 && pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }
    else
      return false;
  }
}