#pragma once

#include "common.h"
#include "Tabuleiro.h"
#include "Timer.h"

class Partida
{
private:
  Cor _jogadorAtual;
  unsigned int _turnoAtual;
  Tabuleiro _tabuleiro;
  Timer _timer;

public:
  Partida();
  ~Partida();
};