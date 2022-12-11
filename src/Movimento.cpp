#include "Movimento.h"

#include "Rei.h"

Movimento::Movimento(Position origem, Position destino, bool eCaptura, bool atacaRei)
  : _origem(origem)
  , _destino(destino)
  , _eCaptura(eCaptura)
  , _atacaRei(atacaRei)
{
}

Position
Movimento::get_origem() const
{
  return _origem;
}

Position
Movimento::get_destino() const
{
  return _destino;
}

bool
Movimento::get_captura() const
{
  return _eCaptura;
}

bool
Movimento::get_atacaRei() const
{
  return _atacaRei;
}

// Gera um movimento baseado em uma posição
//
// Retorna true se o movimento for em cima de outra peça, senão retorna falso.
// Isso serve para parar de percorrer o tabuleiro quando "bater" em outra peça, como por exemplo no
// caso da torre.
//
// Não verifica se x e y estão dentro do tabuleiro, isso deve ser feito na função que a chama.
bool
Movimento::geraMovimento(Position posOrigem,
                         Position posDestino,
                         Peca* tabuleiro[8][8],
                         std::vector<Movimento>& movimentos)
{
  Peca* pecaOrigem = tabuleiro[posOrigem.get_x()][posOrigem.get_y()];
  Peca* pecaDestino = tabuleiro[posDestino.get_x()][posDestino.get_y()];
  if (pecaDestino)
  {
    if (pecaDestino->getCor() != pecaOrigem->getCor())
    {
      Rei* rei = dynamic_cast<Rei*>(pecaDestino);
      if (rei)
      {
        movimentos.push_back(Movimento(posOrigem, posDestino, true, true));
      }
      else
      {
        movimentos.push_back(Movimento(posOrigem, posDestino, true, false));
      }
    }
    return true;
  }
  else
  {
    movimentos.push_back(Movimento(posOrigem, posDestino, false, false));
    return false;
  }
}

// A saída está configurada de forma que o número da peça seja contado de Y para X dentro da matriz
// tabuleiro
std::ostream&
operator<<(std::ostream& os, const Movimento& m)
{
  os << m.get_origem() << ' ' << m.get_destino() << " captura: " << m.get_captura()
     << " ataca rei: " << m.get_atacaRei();
  return os;
}
