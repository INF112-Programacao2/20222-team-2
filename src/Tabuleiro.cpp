#include "Tabuleiro.h"

#include <iostream>

#include "Pecas/Bispo.h"
#include "Pecas/Cavalo.h"
#include "Pecas/Peao.h"
#include "Pecas/Rainha.h"
#include "Pecas/Rei.h"
#include "Pecas/Torre.h"
#include "constants.h"
#include "globals.h"

Tabuleiro::Tabuleiro()
  : _pecaSelecionada(nullptr)
{
}

void
Tabuleiro::onRender() const
{
  ALLEGRO_COLOR c = al_map_rgb(255, 255, 255);
  bool isWhiteSquare = false;

  // desenha o quadriculado do tabuleiro, utilizando offsets para não haver interseção com os
  // elementos de UI
  for (int i = OFFSET_Y; i <= BOARD_SIZE - BOARD_STEP + OFFSET_Y; i += BOARD_STEP)
  {
    isWhiteSquare = !isWhiteSquare;
    for (int j = OFFSET_X; j <= BOARD_SIZE - BOARD_STEP + OFFSET_X; j += BOARD_STEP)
    {
      if (isWhiteSquare)
      {
        c = al_map_rgb(0, 80, 180);
        isWhiteSquare = !isWhiteSquare;
      }
      else
      {
        c = al_map_rgb(200, 200, 220);
        isWhiteSquare = !isWhiteSquare;
      }
      al_draw_filled_rectangle(j, i, j + BOARD_STEP, i + BOARD_STEP, c);
    }
  }

  if (_pecaSelecionada)
  {
    std::vector<Movimento> movPecaSelecionada;
    // procura os movimentos da peça selecionada na lista de movimentos
    for (int i = 0; i < _movimentos.size(); ++i)
    {
      if (_movimentos[i].size() > 0 &&
          _movimentos[i][0].get_origem().get_x() == _pecaSelecionada->getPos().get_x() &&
          _movimentos[i][0].get_origem().get_y() == _pecaSelecionada->getPos().get_y())
      {
        movPecaSelecionada = _movimentos[i];
        break;
      }
    }

    // TODO: desenhar por cima da peça, se for captura, desenhar um círculo vermelho
    if (movPecaSelecionada.size() > 0)
    {
      c = al_map_rgba(0, 0, 0, 65);
      for (const Movimento& m : movPecaSelecionada)
      {
        float x = m.get_destino().get_x() * BOARD_STEP + OFFSET_X;
        float y = m.get_destino().get_y() * BOARD_STEP + OFFSET_Y;
        al_draw_filled_circle(
          (x + x + BOARD_STEP) / 2, (y + y + BOARD_STEP) / 2, BOARD_STEP / 6, c);
      }
    }
  }

  // desenha as peças
  for (int x = 0; x < 8; ++x)
  {
    for (int y = 0; y < 8; ++y)
    {
      if (_tabuleiro[x][y])
      {
        _tabuleiro[x][y]->onRender();
      }
    }
  }
}

// Limpa o tabuleiro e coloca as peças como num jogo padrão de xadrez, alocando novas peças
void
Tabuleiro::inicializarJogo() // TODO: trocar o nome para algo que faça mais sentido
{
  // zerar todas as posições do tabuleiro
  // TODO: copiar esse loop para o construtor, e verificar se existem peças nesse loop. Se
  // existirem, deletar antes de setar para nullptr
  for (int x = 0; x < 8; ++x)
  {
    for (int y = 0; y < 8; ++y)
    {
      _tabuleiro[x][y] = nullptr;
    }
  }

  // // colocar as peças como num jogo padrão de xadrez
  // deletar todas as peças que já existem
  for (int x = 0; x < 8; ++x)
  {
    for (int y = 0; y < 8; ++y)
    {
      if (_tabuleiro[x][y])
      {
        delete _tabuleiro[x][y];
      }
      _tabuleiro[x][y] = nullptr;
    }
  }

  // colocar as peças como num jogo comum de xadrez
  // pretas, fileira de trás
  _tabuleiro[0][0] = new Torre(Cor::PRETO, { 0, 0 });
  _tabuleiro[1][0] = new Cavalo(Cor::PRETO, { 1, 0 });
  _tabuleiro[2][0] = new Bispo(Cor::PRETO, { 2, 0 });
  _tabuleiro[3][0] = new Rainha(Cor::PRETO, { 3, 0 });
  _tabuleiro[4][0] = new Rei(Cor::PRETO, { 4, 0 });
  _reiPreto = _tabuleiro[4][0];
  _tabuleiro[5][0] = new Bispo(Cor::PRETO, { 5, 0 });
  _tabuleiro[6][0] = new Cavalo(Cor::PRETO, { 6, 0 });
  _tabuleiro[7][0] = new Torre(Cor::PRETO, { 7, 0 });
  // pretas, peões
  for (int x = 0; x < 8; ++x)
  {
    _tabuleiro[x][1] = new Peao(Cor::PRETO, { x, 1 });
  }

  // brancas, fileira de trás
  _tabuleiro[0][7] = new Torre(Cor::BRANCO, { 0, 7 });
  _tabuleiro[1][7] = new Cavalo(Cor::BRANCO, { 1, 7 });
  _tabuleiro[2][7] = new Bispo(Cor::BRANCO, { 2, 7 });
  _tabuleiro[3][7] = new Rainha(Cor::BRANCO, { 3, 7 });
  _tabuleiro[4][7] = new Rei(Cor::BRANCO, { 4, 7 });
  _reiBranco = _tabuleiro[4][7];
  _tabuleiro[5][7] = new Bispo(Cor::BRANCO, { 5, 7 });
  _tabuleiro[6][7] = new Cavalo(Cor::BRANCO, { 6, 7 });
  _tabuleiro[7][7] = new Torre(Cor::BRANCO, { 7, 7 });
  // brancas, peões
  for (int x = 0; x < 8; ++x)
  {
    _tabuleiro[x][6] = new Peao(Cor::BRANCO, { x, 6 });
  }

  _movimentos = _gerarMovimentos();
  // DEBUG: imprimir todos os movimentos
  for (int i = 0; i < _movimentos.size(); ++i)
  {
    std::cout << i << std::endl;
    if (_movimentos[i].size() > 0)
    {
      _debugarPeca(
        _tabuleiro[_movimentos[i][0].get_origem().get_x()][_movimentos[i][0].get_origem().get_y()]);
    }
    for (Movimento& movimento : _movimentos[i])
    {
      std::cout << movimento << std::endl;
    }
  }
}

// Gerencia o que ocorre quando o jogador clicka na tela
void
Tabuleiro::onClick(const ALLEGRO_EVENT& e, unsigned int& turno)
{
  Position pos = _screenToBoard(e);
  if (!isInside(pos))
  {
    return;
  }

  if (_pecaSelecionada != nullptr)
  {
    Peca* dest = _tabuleiro[pos.get_x()][pos.get_y()];
    if (dest && (dest->getCor() == (turno % 2 ? Cor::BRANCO : Cor::PRETO)))
    {
      _pecaSelecionada = dest;
      return;
    }
    if (moverPeca(pos.get_x(), pos.get_y()))
    {
      ++turno;

      Peca* peca = _tabuleiro[pos.get_x()][pos.get_y()];
      Peao* peao = dynamic_cast<Peao*>(peca);
      if (peao)
      {
        pawnPromotion(_tabuleiro[pos.get_x()][pos.get_y()]);
      }

      _pecaSelecionada = nullptr;
      _movimentos.clear();
      _movimentos = _gerarMovimentos();

      // TODO: passar essa verificação para a peça?
      // Após gerar os movimentos, verificar se o rei está em xeque com a função isCheck
      bool check_Branco = isCheck(_reiBranco);
      std::cout << "Rei branco em xeque: " << check_Branco << std::endl;
      bool check_Preto = isCheck(_reiPreto);
      std::cout << "Rei preto em xeque: " << check_Preto << std::endl;

      // DEBUG: imprimir todos os movimentos
      for (int i = 0; i < _movimentos.size(); ++i)
      {
        std::cout << i << std::endl;
        if (_movimentos[i].size() > 0)
        {
          _debugarPeca(_tabuleiro[_movimentos[i][0].get_origem().get_x()]
                                 [_movimentos[i][0].get_origem().get_y()]);
        }
        for (Movimento& movimento : _movimentos[i])
        {
          std::cout << movimento << std::endl;
        }
      }
    }
  }
  else
  {
    // Seleciona a peça clickada
    Peca* sel = _tabuleiro[pos.get_x()][pos.get_y()];
    if (sel && (sel->getCor() == (turno % 2 ? Cor::BRANCO : Cor::PRETO)))
    {
      _pecaSelecionada = _tabuleiro[pos.get_x()][pos.get_y()];
    }
  }
}

// Converte uma posição do mouse na tela para uma posição no tabuleiro
Position
Tabuleiro::_screenToBoard(const ALLEGRO_EVENT& e) const
{
  Position p = { ((int)e.mouse.x - OFFSET_X) / BOARD_STEP,
                 ((int)e.mouse.y - OFFSET_Y) / BOARD_STEP };
  return p;
}

// Move a peça selecionada para a posição x, y (coluna / linha), começando na (0, 0)
// O turno começa em 1 (branco), então para saber se o jogador atual é o preto ou o branco, basta
// saber se o turno é par ou ímpar.
//
// Retorna 1 se o movimento ocorrer, 0 se o movimento for inválido.
//
// Essa função retorna um unsigned int para ser somado (incrementar) ao número de turnos, por isso
// não pode ser bool
unsigned int
Tabuleiro::moverPeca(int destX, int destY)
{
  Peca* pecaDestino = _tabuleiro[destX][destY];
  std::vector<Movimento> movPecaSelecionada;

  if (pecaDestino && pecaDestino->getCor() == _pecaSelecionada->getCor())
  {
    // clique em peças de mesma cor, selecionar a outra peça
    _pecaSelecionada = pecaDestino;
    return 0;
  }

  // procura os movimentos da peça selecionada na lista de movimentos
  for (int i = 0; i < _movimentos.size(); ++i)
  {
    if (_movimentos[i].size() > 0 &&
        _movimentos[i][0].get_origem().get_x() == _pecaSelecionada->getPos().get_x() &&
        _movimentos[i][0].get_origem().get_y() == _pecaSelecionada->getPos().get_y())
    {
      movPecaSelecionada = _movimentos[i];
      break;
    }
  }

  // verifica se há um movimento com o destino selecionado
  for (const Movimento& movimento : movPecaSelecionada)
  {
    Position posDestino = movimento.get_destino();
    if (destX == posDestino.get_x() && destY == posDestino.get_y())
    {
      if (movimento.get_roque())
      {
        // mover o rei
        _moverPeca(destX, destY);
        // calcular posição da torre para o roque baseado na posição do rei
        Position origTorre = { (destX == 6 ? 7 : 0), destY };
        Position destTorre = { (destX == 6 ? 5 : 3), destY };
        _pecaSelecionada = _tabuleiro[origTorre.get_x()][origTorre.get_y()];
        // mover a torre
        _moverPeca(destTorre.get_x(), destTorre.get_y());
        _pecaSelecionada = nullptr;
        return 1;
      }
      _moverPeca(destX, destY);
      if (movimento.get_captura())
      {
        delete pecaDestino;
      }
      return 1;
    }
  }

  return 0;
}

// Gera os movimentos possíveis para todas as peças do tabuleiro, validando-os parcialmente. O resto
// da validação (xeque, mate) será feito na simulação
std::vector<std::vector<Movimento>>
Tabuleiro::_gerarMovimentos()
{
  std::vector<std::vector<Movimento>> movimentos;
  for (int y = 0; y < 8; ++y)
  {
    for (int x = 0; x < 8; ++x)
    {
      if (_tabuleiro[x][y])
      {
        movimentos.push_back(_tabuleiro[x][y]->gerarMovimentos(_tabuleiro));
      }
    }
  }
  return movimentos;
}

// Função auxiliar
// Move a peca selecionada para a posição de destino, independente do que estiver lá.
// NOTA: essa função NÃO deleta a peça de destino, isso deve ser feito na função que está chamando
// esta.
void
Tabuleiro::_moverPeca(int destX, int destY)
{
  _tabuleiro[destX][destY] = _pecaSelecionada;
  Position posOrigem = _pecaSelecionada->getPos();
  _tabuleiro[posOrigem.get_x()][posOrigem.get_y()] = nullptr;
  _pecaSelecionada->setPos({ destX, destY });
  _pecaSelecionada->incrementarMovimentos();
}

// Função auxiliar
// Verifica se uma posição está ou não dentro do tabuleiro
bool
Tabuleiro::isInside(const Position& pos)
{
  int x = pos.get_x();
  int y = pos.get_y();
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void
Tabuleiro::pawnPromotion(Peca* p)
{
  if (p->getPos().get_y() == 0 || p->getPos().get_y() == 7)
  {
    Position pos = p->getPos();
    _tabuleiro[pos.get_x()][pos.get_y()] = new Rainha(p->getCor(), { pos.get_x(), pos.get_y() });
    delete p;
  }
}

bool
Tabuleiro::isCheck(Peca* rei) const
{
  Position posRei = rei->getPos();
  for (int y = 0; y < 8; ++y)
  {
    for (int x = 0; x < 8; ++x)
    {
      if (_tabuleiro[x][y] && _tabuleiro[x][y]->getCor() != rei->getCor())
      {
        for (int i = 0; i < _movimentos.size(); ++i)
        {
          for (const Movimento& movimento : _movimentos[i])
          {
            if (movimento.get_atacaRei())
            {
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}


// Funções para simulação
// code review
/*
void
Tabuleiro::_simularMoverPeca(Peca* origem, Peca* destino)
{
  _tabuleiro[destino->getPos().get_x()][destino->getPos().get_y()] = origem;
  _tabuleiro[origem->getPos().get_x()][origem->getPos().get_y()] = nullptr;
  origem->setPos(destino->getPos());
}
*/

/*
void
Tabuleiro::_simularMovimentos()
{
  for (const std::vector<Movimento>& movimentos : _movimentos)
  {
    for (const Movimento& m : movimentos)
    {
      _simularMovimento(m);
    }
  }
}
*/

/*void
Tabuleiro::_simularMovimento(const Movimento& m)
{
  // TODO: checkar o roque
  Position posOrigem = m.get_origem();
  Position posDestino = m.get_destino();
  Peca* pecaOrigem = _tabuleiro[posOrigem.get_x()][posOrigem.get_y()];
  Peca* pecaDestino = _tabuleiro[posDestino.get_x()][posDestino.get_y()];

  pecaOrigem->decrementarMovimentos();
}
*/

/*void _simularMoverPeca(const Movimento& m)
{
  
}
*/

// Imprime o tipo, cor e posição da peça no console.
void
Tabuleiro::_debugarPeca(Peca* p)
{
  if (!p)
  {
    std::cout << "Vazio" << '\n' << std::endl;
    return;
  }
  Torre* t1 = dynamic_cast<Torre*>(p);
  Cavalo* t2 = dynamic_cast<Cavalo*>(p);
  Bispo* t3 = dynamic_cast<Bispo*>(p);
  Rainha* t4 = dynamic_cast<Rainha*>(p);
  Rei* t5 = dynamic_cast<Rei*>(p);
  Peao* t6 = dynamic_cast<Peao*>(p);
  if (t1)
  {
    std::cout << "TORRE";
  }
  else if (t2)
  {
    std::cout << "CAVALO";
  }
  else if (t3)
  {
    std::cout << "BISPO";
  }
  else if (t4)
  {
    std::cout << "RAINHA";
  }
  else if (t5)
  {
    std::cout << "REI";
  }
  else if (t6)
  {
    std::cout << "PEAO";
  }
  std::cout << ' ' << (p->getCor() == Cor::BRANCO ? "BRANCO" : "PRETO");
  std::cout << ' ' << p->getPos() << std::endl;
}