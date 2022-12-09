#include "Game.h"

#include <allegro5/allegro_image.h>

#include <imgui.h>
#include <imgui_impl_allegro5.h>

#include <iostream>

#include "Partida.h"
#include "Rei.h"
#include "Tabuleiro.h"
#include "Text.h"
#include "Timer.h"

#include "constants.h"
#include "errorHandling.h"
#include "globals.h"

Game::Game()
{
  // inicializa allegro e seus sistemas
  EC_CALL(al_init());
  EC_CALL(al_install_keyboard());
  EC_CALL(al_install_mouse()); // Instalação do mouse
  EC_CALL(_display = al_create_display(SCREEN_W, SCREEN_H));
  EC_CALL(_font = al_create_builtin_font());
  EC_CALL(al_init_image_addon());
  EC_CALL(al_init_primitives_addon());

  // carregar imagens das pecas
  // pretas
  EC_CALL(_kingBlackBmp = al_load_bitmap("./assets/Chess_kdt45.png"));
  EC_CALL(_queenBlackBmp = al_load_bitmap("./assets/Chess_qdt45.png"));
  EC_CALL(_bishopBlackBmp = al_load_bitmap("./assets/Chess_bdt45.png"));
  EC_CALL(_knightBlackBmp = al_load_bitmap("./assets/Chess_ndt45.png"));
  EC_CALL(_rookBlackBmp = al_load_bitmap("./assets/Chess_rdt45.png"));
  EC_CALL(_pawnBlackBmp = al_load_bitmap("./assets/Chess_pdt45.png"));
  // brancas
  EC_CALL(_kingWhiteBmp = al_load_bitmap("./assets/Chess_klt45.png"));
  EC_CALL(_queenWhiteBmp = al_load_bitmap("./assets/Chess_qlt45.png"));
  EC_CALL(_bishopWhiteBmp = al_load_bitmap("./assets/Chess_blt45.png"));
  EC_CALL(_knightWhiteBmp = al_load_bitmap("./assets/Chess_nlt45.png"));
  EC_CALL(_rookWhiteBmp = al_load_bitmap("./assets/Chess_rlt45.png"));
  EC_CALL(_pawnWhiteBmp = al_load_bitmap("./assets/Chess_plt45.png"));

  // inicializa o timer para rodar o jogo a 30 fps
  EC_CALL(_timer = al_create_timer(1.0 / 30.0));

  // cria fila de eventos para usar com a API da allegro
  EC_CALL(_queue = al_create_event_queue());
  al_register_event_source(_queue, al_get_keyboard_event_source());
  al_register_event_source(_queue, al_get_display_event_source(_display));
  al_register_event_source(_queue, al_get_mouse_event_source()); // New evento para o mouse
  al_register_event_source(_queue, al_get_timer_event_source(_timer));

  // define o alvo padrão para renderizar na tela
  al_set_target_bitmap(al_get_backbuffer(_display));

  // Inicializar contexto da Dear ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  io.Fonts->AddFontFromFileTTF("assets/Inter-Regular.ttf", 24);
  ImGui::StyleColorsLight();
  ImGui_ImplAllegro5_Init(_display);
}

Game::~Game()
{
  // Limpa o contexto da Dear ImGui
  ImGui_ImplAllegro5_Shutdown();
  ImGui::DestroyContext();

  // desaloca todas as imagens das peças
  // pretas
  al_destroy_bitmap(_kingBlackBmp);
  al_destroy_bitmap(_queenBlackBmp);
  al_destroy_bitmap(_bishopBlackBmp);
  al_destroy_bitmap(_knightBlackBmp);
  al_destroy_bitmap(_rookBlackBmp);
  al_destroy_bitmap(_pawnBlackBmp);
  // brancas
  al_destroy_bitmap(_kingWhiteBmp);
  al_destroy_bitmap(_queenWhiteBmp);
  al_destroy_bitmap(_bishopWhiteBmp);
  al_destroy_bitmap(_knightWhiteBmp);
  al_destroy_bitmap(_rookWhiteBmp);
  al_destroy_bitmap(_pawnWhiteBmp);

  // desinicializa e destrói os sistemas da allegro
  al_shutdown_image_addon();
  al_shutdown_font_addon();
  al_shutdown_primitives_addon();
  al_destroy_timer(_timer);
  al_destroy_event_queue(_queue);
  al_destroy_font(_font);
  al_destroy_display(_display);
  al_uninstall_system();
}

void
Game::mainLoop()
{
  bool running = true;
  bool redraw = true;
  ALLEGRO_EVENT event;

  Partida partida;

  al_start_timer(_timer);
  while (running)
  {
    al_wait_for_event(_queue, &event);

    ImGui_ImplAllegro5_ProcessEvent(&event);

    switch (event.type)
    {
      case ALLEGRO_EVENT_TIMER:
        // game logic goes here.
        redraw = true;
        break;

      case ALLEGRO_EVENT_DISPLAY_CLOSE:
      {
        running = false;
        break;
      }

      case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
      {
        partida.onClick(event);
        break;
      }
    }

    if (redraw && al_is_event_queue_empty(_queue))
    {
      al_clear_to_color(al_map_rgb(0, 0, 0));

      // Começar o fram do Dear ImGui
      ImGui_ImplAllegro5_NewFrame();
      ImGui::NewFrame();

      partida.onRender();

      ImGui::Render();
      ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
      al_flip_display();

      redraw = false;
    }
  }
}