CC := g++
ARGS := -lncurses
SRC := src
BIN := bin
INC := CTRLib
all:
	$(CC) $(SRC)/main.cxx -o $(BIN)/CTRL.out $(ARGS) -I$(INC)