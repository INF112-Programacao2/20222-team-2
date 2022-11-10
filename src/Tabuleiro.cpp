#include "Tabuleiro.h"

Tabuleiro::Tabuleiro() {
}

void Tabuleiro::onRender() {
  int iterations = 0;
  bool summed = false;
  // TODO: make the magic values below constants
  for (int i = 0; i <= 560; i += 80) {
    for (int j = 0; j <= 560; j += 160) {
      if ((iterations % 2 != 0) && !summed) {
        j += 80;
        summed = true;
      }
      al_draw_filled_rectangle(j, i, j + 80, i + 80, al_map_rgb(255, 255, 255));
    }
    ++iterations;
    summed = false;
  }
}
