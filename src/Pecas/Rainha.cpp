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
  if(_cor == Cor::PRETO)
  {
    // Movimentos para direita cima diagonal
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_x() + i < 8 && _pos.get_y() + i < 8)
      {
        if(tabuleiro[_pos.get_x() + i][_pos.get_y() + i] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + i, _pos.get_y() + i), false, false));
        }
        else if(tabuleiro[_pos.get_x() + i][_pos.get_y() + i]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + i, _pos.get_y() + i), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }
    
    // Movimentos para esquerda baixo diagonal
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_x() - i >= 0 && _pos.get_y() - i >= 0)
      {
        if(tabuleiro[_pos.get_x() - i][_pos.get_y() - i] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - i, _pos.get_y() - i), false, false));
        }
        else if(tabuleiro[_pos.get_x() - i][_pos.get_y() - i]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - i, _pos.get_y() - i), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }

    // Movimentos para direita baixo diagonal
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_x() + i < 8 && _pos.get_y() - i >= 0)
      {
        if(tabuleiro[_pos.get_x() + i][_pos.get_y() - i] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + i, _pos.get_y() - i), false, false));
        }
        else if(tabuleiro[_pos.get_x() + i][_pos.get_y() - i]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + i, _pos.get_y() - i), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }

    // Movimentos para esquerda cima diagonal
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_x() - i >= 0 && _pos.get_y() + i < 8)
      {
        if(tabuleiro[_pos.get_x() - i][_pos.get_y() + i] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - i, _pos.get_y() + i), false, false));
        }
        else if(tabuleiro[_pos.get_x() - i][_pos.get_y() + i]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - i, _pos.get_y() + i), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }

    // Movimentos direita
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_x() + i < 8)
      {
        if(tabuleiro[_pos.get_x() + i][_pos.get_y()] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + i, _pos.get_y()), false, false));
        }
        else if(tabuleiro[_pos.get_x() + i][_pos.get_y()]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() + i, _pos.get_y()), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }

    // Movimentos esquerda
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_x() - i >= 0)
      {
        if(tabuleiro[_pos.get_x() - i][_pos.get_y()] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - i, _pos.get_y()), false, false));
        }
        else if(tabuleiro[_pos.get_x() - i][_pos.get_y()]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x() - i, _pos.get_y()), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }

    // Movimentos para cima
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_y() + i < 8)
      {
        if(tabuleiro[_pos.get_x()][_pos.get_y() + i] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() + i), false, false));
        }
        else if(tabuleiro[_pos.get_x()][_pos.get_y() + i]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() + i), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }

    // Movimentos para baixo
    for(int i = 1; i < 8; i++)
    {
      if(_pos.get_y() - i >= 0)
      {
        if(tabuleiro[_pos.get_x()][_pos.get_y() - i] == nullptr)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() - i), false, false ));
        }
        else if(tabuleiro[_pos.get_x()][_pos.get_y() - i]->getCor() == Cor::BRANCO)
        {
          movimentos.push_back(Movimento(_pos, Position(_pos.get_x(), _pos.get_y() - i), false, false));
          break;
        }
        else
        {
          break;
        }
      }
    }

  return movimentos;
}
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
