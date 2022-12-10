#pragma once

#include <iostream>

#include "Position.h"
#include "common.h"

class Movimento
{
private:
  Position _origem;
  Position _destino;
  bool _eCaptura;
  bool _atacaRei;

public:
  Movimento(Position origem, Position destino, bool eCaptura, bool atacaRei);
  ~Movimento() {}

  Position get_origem() const;
  Position get_destino() const;
  bool get_captura() const;
  bool get_atacaRei() const;

  friend std::ostream& operator<<(std::ostream& os, const Movimento& m);
};