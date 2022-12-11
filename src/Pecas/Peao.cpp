#include "Pecas/Peao.h"

#include <string>

#include "Tabuleiro.h"

Peao::Peao(Cor cor, Position pos, ALLEGRO_BITMAP* sprite)
  : Peca(cor, pos, sprite)
{
}

std::vector<Movimento>
Peao::gerarMovimentos(Peca* tabuleiro[8][8]) const
{
  std::vector<Movimento> movimentos;

  // o sinal é usado para mover o peão apenas para cima ou apenas para baixo, dependendo de sua cor
  int sinal = (_cor == Cor::BRANCO ? -1 : 1); // Operador ternario

  // Detecta movimentos a esquerda da peça
  if (Tabuleiro::isInside({ _pos.get_x(), _pos.get_y() + 1 * sinal }))
  {
    if (tabuleiro[_pos.get_x() - 1][_pos.get_y() + 1 * sinal] != nullptr)
    {
      if (tabuleiro[_pos.get_x() - 1][_pos.get_y() + 1 * sinal]->getCor() != _cor)
      {
        movimentos.push_back(
          Movimento(_pos, { _pos.get_x() - 1, _pos.get_y() + 1 * sinal }, true, false));
      }
    }
  }

  // Detecta movimentos a frente da peça
  if (Tabuleiro::isInside({ _pos.get_x(), _pos.get_y() + 1 * sinal }))
  {
    movimentos.push_back(Movimento(_pos, { _pos.get_x(), _pos.get_y() + 1 * sinal }, false, false));
  }

  // Detecta movimentos a direita da peça
  if (Tabuleiro::isInside({ _pos.get_x() + 1, _pos.get_y() + 1 * sinal }))
  {
    if (tabuleiro[_pos.get_x() + 1][_pos.get_y() + 1 * sinal] != nullptr)
    {
      if (tabuleiro[_pos.get_x() + 1][_pos.get_y() + 1 * sinal]->getCor() != _cor)
      {
        movimentos.push_back(
          Movimento(_pos, { _pos.get_x() + 1, _pos.get_y() + 1 * sinal }, true, false));
      }
    }
  }

  // Caso a peça ainda não tenha se movido, ela pode se mover duas casas
  if (!_movimentos)
  {
    movimentos.push_back(Movimento(_pos, { _pos.get_x(), _pos.get_y() + 2 * sinal }, false, false));
  }

  return movimentos;
}

// TO DO: configurar restrições conforme a função gerarMovimento
bool
Peao::validarMovimento(Position pos) const
{
  if (pos.get_x() < 0 || pos.get_x() > 7 || pos.get_y() < 0 || pos.get_y() > 7)
  {
    throw "Movimento inválido";
    return false;
  }

  if (_movimentos > 0)
  {
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() && pos.get_y() == _pos.get_y() + 1)
    {
      return true; // tirar as cores, não são necessárias mais
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() && pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() && pos.get_y() <= _pos.get_y() + 2 &&
        pos.get_y() > _pos.get_y())
    {
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() && pos.get_y() >= _pos.get_y() - 2)
    {
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() + 1 &&
             pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }
    else if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() + 1 &&
             pos.get_y() == _pos.get_y() + 1)
    {
      return true;
    }
    else if (_cor == Cor::BRANCO && pos.get_x() == _pos.get_x() - 1 &&
             pos.get_y() == _pos.get_y() - 1)
    {
      return true;
    }
    else if (_cor == Cor::PRETO && pos.get_x() == _pos.get_x() - 1 &&
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