#include <iostream>

#include "Game.h"

#include <allegro5/allegro.h>
// é necessário incluir a allegro onde está definida a função main, mesmo sem
// utilizar nada aqui

int
main()
{
  Game g;

  g.mainLoop();

  return 0;
}
