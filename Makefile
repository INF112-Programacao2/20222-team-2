# Especifica alvos que não geram arquivos e portanto sempre devem ser executados
.PHONY: run clean all

# Especifica o alvo padrão
.DEFAULT_GOAL := all

# Definir o compilador
CXX := g++

# Flags adicionais
ADDITIONAL_FLAGS := -DIMGUI_USER_CONFIG=\"/home/zig/personal/INF112/20222-team-2/lib/imgui-master/examples/example_allegro5/imconfig_allegro5.h\"

# Definir flags de compilação
CXXFLAGS := -O2 $(ADDITIONAL_FLAGS)

# Define alvo de debug
debug: CXXFLAGS := $(filter-out -O2,$(CXXFLAGS))
debug: CXXFLAGS += -g -Wall -Wextra -O0
debug: all
debug-run: debug
	gdb $(BUILD_DIR)/$(TARGET_EXE)

memory-check-run:
	valgrind --track-origins=yes --leak-check=full $(BUILD_DIR)/$(TARGET_EXE)

# Definir flags do linker
LDFLAGS := -lallegro -lallegro_main -lallegro_font -lallegro_primitives -lallegro_image $(ADDITIONAL_FLAGS)

# Definir variáveis do projeto
TARGET_EXE := xadrez

BUILD_DIR := bin
SRC_DIR := src
LIB_DIR := lib

# Encontrar todos os arquivos .cpp para compilar
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Gerar os nomes dos arquivos de saída
# Exemplo: src/Peca.cpp vira bin/Peca.o
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Adicionar subdiretórios ao caminho de include para o compilador encontrar todos os
# header files
INC_DIRS := $(shell find $(SRC_DIR) -type d)

# Compila ImGui
IMGUI_DIR := $(LIB_DIR)/imgui-master
IMGUI_SRCS := $(shell find $(IMGUI_DIR) -maxdepth 1 -name '*.cpp')
IMGUI_OBJS := $(IMGUI_SRCS:$(IMGUI_DIR)/%.cpp=$(BUILD_DIR)/imgui/%.o)
INC_DIRS += $(IMGUI_DIR)


# Gera as flags de inclusão. Ex: src/gui vira -Isrc/gui
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Linkar o executável final
all: $(OBJS) $(IMGUI_OBJS)
	$(CXX) $(OBJS) $(IMGUI_OBJS) -o $(BUILD_DIR)/$(TARGET_EXE) $(LDFLAGS)
	cp -r assets bin/

# Receita para arquivos .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

# Receita para arquivos ImGui
$(BUILD_DIR)/imgui/%.o: $(IMGUI_DIR)/%.cpp
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

run:
	@./bin/xadrez

clean:
	rm -r bin/*

# Converter imagens para um formato legível pelo jogo
SVG_DIR := svg
SVGS := $(shell find $(SVG_DIR) -name '*.svg')

ASSET_DIR := assets

SPRITES := $(SVGS:$(SVG_DIR)/%.svg=$(ASSET_DIR)/%.png)

convert: $(SPRITES)

$(ASSET_DIR)/%.png: $(SVG_DIR)/%.svg
	inkscape -w 80 -h 80 $< -o $@
