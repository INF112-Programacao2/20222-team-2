#include "Tabuleiro.h"

#include "constants.h"

Tabuleiro::Tabuleiro() {
}

void Tabuleiro::onRender() {
  ALLEGRO_COLOR c = al_map_rgb(255, 255, 255);
  bool isWhiteSquare = false;
  for (int i = 0; i <= BOARD_SIZE - BOARD_STEP; i += BOARD_STEP) {
    isWhiteSquare = !isWhiteSquare;
    for (int j = 0; j <= BOARD_SIZE - BOARD_STEP; j += BOARD_STEP) {
      if (isWhiteSquare) {
        c = al_map_rgb(0, 80, 180);
        isWhiteSquare = !isWhiteSquare;
      } else {
        c = al_map_rgb(200, 200, 220);
        isWhiteSquare = !isWhiteSquare;
      }
      al_draw_filled_rectangle(j, i, j + BOARD_STEP, i + BOARD_STEP, c);
    }
  }
}
