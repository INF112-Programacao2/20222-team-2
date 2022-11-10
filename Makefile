# Especifica alvos que não geram arquivos e portanto sempre devem ser executados
.PHONY: run clean

# Especifica o alvo padrão
.DEFAULT_GOAL := all

# Definir o compilador
CXX := g++

# Definir flags de compilação
CXXFLAGS := -O2

# Define alvo de debug
debug: CXXFLAGS += -g -Wall -Wextra
debug: CXXFLAGS := $(filter-out -O2,$(CXXFLAGS))
debug: all
debug-run: debug
	gdb $(BUILD_DIR)/$(TARGET_EXE)

memory-check-run:
	valgrind --track-origins=yes --leak-check=full $(BUILD_DIR)/$(TARGET_EXE)

# Definir flags do linker
LDFLAGS := -lallegro -lallegro_main -lallegro_font -lallegro_primitives

# Definir variáveis do projeto
TARGET_EXE := xadrez

BUILD_DIR := bin
SRC_DIR := src

# Encontrar todos os arquivos .cpp para compilar
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Gerar os nomes dos arquivos de saída
# Exemplo: src/Peca.cpp vira bin/Peca.o
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Adicionar subdiretórios ao caminho de include para o compilador encontrar todos os
# header files
# INC_DIRS := $(shell find $(SRC_DIR) -type d)
# Gera as flags de inclusão. Ex: src/gui vira -Isrc/gui
# INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Linkar o executável final
all: $(OBJS)
	$(CXX) $(OBJS) -o $(BUILD_DIR)/$(TARGET_EXE) $(LDFLAGS)

# Compilar arquivos .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

run:
	@./bin/xadrez

clean:
	rm -r bin/*
