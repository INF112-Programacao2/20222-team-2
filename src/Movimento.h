#pragma once

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
  Movimento(Position origem, Position destino);
  ~Movimento() {}
};