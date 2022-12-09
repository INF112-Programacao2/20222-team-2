#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

#include "Bispo.h"
#include "Cavalo.h"
#include "GameObject.h"
#include "Peao.h"
#include "Peca.h"
#include "Rainha.h"
#include "Rei.h"
#include "Torre.h"
// #include "Turno.h"

class Tabuleiro : public GameObject
{
private:
  Peca* _tabuleiro[8][8];
  Peca* _pecaSelecionada;

public:
  Tabuleiro();
  ~Tabuleiro() {}

  void moverPeca(int x, int y, int x2, int y2);
  void inicializarJogo();
  virtual void onRender() const override;
  void onClick();
};