#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

#include "GameObject.h"
#include "Peca.h"
#include "Rei.h"
#include "Rainha.h"
#include "Bispo.h"
#include "Cavalo.h"
#include "Torre.h"
#include "Peao.h"

class Tabuleiro : public GameObject {
private:
  Peca* _tabuleiro[8][8];

public:
  Tabuleiro();
  ~Tabuleiro() {}

  // void posicionarPeca();
  // void removerPeca();
  void inicializarJogo();

  virtual void onRender();
};
