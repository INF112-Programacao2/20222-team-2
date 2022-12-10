#pragma once

#include "GameObject.h"
#include "Tabuleiro.h"
#include "Timer.h"
#include "common.h"

class Partida : public GameObject
{
private:
  unsigned int _turnoAtual;
  Tabuleiro _tabuleiro;
  Timer _timer;

public:
  Partida();
  ~Partida();

  virtual void onRender() const override;
  bool onClick(const ALLEGRO_EVENT& e);
};