# Makefile para o projeto Jogo de War
# Compila o projeto de forma modularizada

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
LDFLAGS =

# Diretórios
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = .

# Arquivos
TARGET = $(BIN_DIR)/war
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Cores para output (opcional)
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m # No Color

# Regra padrão
all: $(BUILD_DIR) $(TARGET)
	@echo "$(GREEN)Compilacao concluida com sucesso!$(NC)"
	@echo "Execute com: ./war"

# Cria o diretório build se não existir
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Regra para criar o executável
$(TARGET): $(OBJECTS)
	@echo "Linkando objetos..."
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Regra para compilar arquivos .c em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Limpa arquivos compilados
clean:
	@echo "Limpando arquivos compilados..."
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "$(GREEN)Limpeza concluida!$(NC)"

# Reconstrói o projeto do zero
rebuild: clean all

# Executa o programa
run: all
	@echo "$(GREEN)Executando o programa...$(NC)"
	@./war

# Exibe ajuda
help:
	@echo "Comandos disponiveis:"
	@echo "  make        - Compila o projeto"
	@echo "  make clean  - Remove arquivos compilados"
	@echo "  make rebuild- Recompila o projeto do zero"
	@echo "  make run    - Compila e executa o programa"
	@echo "  make help   - Exibe esta mensagem"

# Declara alvos que não são arquivos
.PHONY: all clean rebuild run help