#include "Partida.h"

Partida::Partida()
  : _turnoAtual(1)
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
}

void
Partida::onClick(const ALLEGRO_EVENT& e)
{
  _tabuleiro.onClick(e, _turnoAtual);
}