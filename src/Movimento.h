#pragma once

#include <iostream>
#include <vector>

#include "Peca.h"
#include "Position.h"
#include "common.h"

class Peca;

class Movimento
{
private:
  Position _origem;
  Position _destino;
  bool _eCaptura;
  bool _atacaRei;
  bool _eRoque;

public:
  Movimento(Position origem, Position destino, bool eCaptura, bool atacaRei, bool eRoque = false);
  ~Movimento() {}

  Position get_origem() const;
  Position get_destino() const;
  bool get_captura() const;
  bool get_atacaRei() const;
  bool get_roque() const;

  static bool geraMovimento(Position origem,
                            Position destino,
                            Peca* tabuleiro[8][8],
                            std::vector<Movimento>& movimentos);

  friend std::ostream& operator<<(std::ostream& os, const Movimento& m);
};