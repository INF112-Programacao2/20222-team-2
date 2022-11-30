#include "Tabuleiro.h"

#include "constants.h"
#include "globals.h"

Tabuleiro::Tabuleiro() {
}

void Tabuleiro::onRender() {
  ALLEGRO_COLOR c = al_map_rgb(255, 255, 255);
  bool isWhiteSquare = false;

  // desenha o quadriculado do tabuleiro
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

  // desenha as peças
  for (int x = 0; x < 8; ++x) {
    for (int y = 0; y < 8; ++y) {
      if (_tabuleiro[x][y]) {
        _tabuleiro[x][y]->onRender();
      }
    }
  }
}

void Tabuleiro::inicializarJogo() {
  // zerar todas as posições do tabuleiro
  for (int x = 0; x < 8; ++x) {
    for (int y = 0; y < 8; ++y) {
      _tabuleiro[x][y] = nullptr;
    }
  }

  // colocar as peças como num jogo padrão de xadrez
  // pretas, fileira de trás
  _tabuleiro[0][0] = new Torre(Cor::PRETO, { 0, 0 }, _rookBlackBmp);
  _tabuleiro[1][0] = new Cavalo(Cor::PRETO, { 1, 0 }, _knightBlackBmp);
  _tabuleiro[2][0] = new Bispo(Cor::PRETO, { 2, 0 }, _bishopBlackBmp);
  _tabuleiro[3][0] = new Rainha(Cor::PRETO, { 3, 0 }, _queenBlackBmp);
  _tabuleiro[4][0] = new Rei(Cor::PRETO, { 4, 0 }, _kingBlackBmp);
  _tabuleiro[5][0] = new Bispo(Cor::PRETO, { 5, 0 }, _bishopBlackBmp);
  _tabuleiro[6][0] = new Cavalo(Cor::PRETO, { 6, 0 }, _knightBlackBmp);
  _tabuleiro[7][0] = new Torre(Cor::PRETO, { 7, 0 }, _rookBlackBmp);
  // pretas, peões
  for (int x = 0; x < 8; ++x) {
    _tabuleiro[x][1] = new Peao(Cor::PRETO, { (float)x, 1 }, _pawnBlackBmp);
  }

  // brancas, fileira de trás
  _tabuleiro[0][7] = new Torre(Cor::BRANCO,  { 0, 7 }, _rookWhiteBmp);
  _tabuleiro[1][7] = new Cavalo(Cor::BRANCO, { 1, 7 }, _knightWhiteBmp);
  _tabuleiro[2][7] = new Bispo(Cor::BRANCO,  { 2, 7 }, _bishopWhiteBmp);
  _tabuleiro[3][7] = new Rainha(Cor::BRANCO, { 3, 7 }, _queenWhiteBmp);
  _tabuleiro[4][7] = new Rei(Cor::BRANCO,    { 4, 7 }, _kingWhiteBmp);
  _tabuleiro[5][7] = new Bispo(Cor::BRANCO,  { 5, 7 }, _bishopWhiteBmp);
  _tabuleiro[6][7] = new Cavalo(Cor::BRANCO, { 6, 7 }, _knightWhiteBmp);
  _tabuleiro[7][7] = new Torre(Cor::BRANCO,  { 7, 7 }, _rookWhiteBmp);
  // brancas, peões
  for (int x = 0; x < 8; ++x) {
    _tabuleiro[x][6] = new Peao(Cor::BRANCO, { (float)x, 6 }, _pawnWhiteBmp);
  }
}

