#include "Partida.h"

Partida::Partida()
  : _turnoAtual(1), _isMate(false)
{
  _timer.reset();
  _tabuleiro.inicializarJogo();
}

Partida::~Partida() {}

void
Partida::onRender() const
{
  _tabuleiro.onRender();
  _timer.onRender();
  if (!_isMate)
  {
    
  }
}

void
Partida::onClick(const ALLEGRO_EVENT& e)
{
  if (_isMate)
  {
    return;
  }
  unsigned int turno = _turnoAtual;
  _tabuleiro.onClick(e, _turnoAtual);
  if (turno < _turnoAtual)
  {
    if (_tabuleiro.isCheck())
    {
      if (_tabuleiro.isMate())
      {
        std::cout << "XEQUE MATE!!!!" << std::endl;
        _isMate = true;
        _timer.stop();
      }
    }
  }
}