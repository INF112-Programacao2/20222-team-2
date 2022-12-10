#include "Movimento.h"

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

// A saída está configurada de forma que o número da peça seja contado de Y para X dentro da matriz tabuleiro
std::ostream&
operator<<(std::ostream& os, const Movimento& m)
{
  os << m.get_origem() << ' ' << m.get_destino() << " captura: " << m.get_captura() << " ataca rei: " << m.get_atacaRei();
  return os;
}
