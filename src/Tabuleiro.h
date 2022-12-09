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

  Position _screenToBoard(const ALLEGRO_EVENT& e) const;

public:
  Tabuleiro();
  ~Tabuleiro() {}
  void moverPeca(int origem_X, int origem_Y, int destino_X, int destino_Y);
  void inicializarJogo();
  virtual void onRender() const override;
  void onClick(const ALLEGRO_EVENT& e);
};