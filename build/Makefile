_INC = ../include
_OBJ = ../obj/
_SRC = ../src/
_BIN = ../bin/

CC = g++
CFLAGS = -std=c++17 -g -c -I$(_INC)
OBJ = primitive.o main.o
BINARY = primitive

OBJFULL = $(patsubst %,$(_OBJ)%,$(OBJ))

all: clean $(BINARY) run

$(BINARY): $(OBJ)
	$(CC) -o $(_BIN)$(BINARY) $(OBJFULL)

%.o: $(_SRC)%.cpp
	$(CC) $(CFLAGS) $< -o $(_OBJ)$@

run: $(_BIN)$(BINARY)
	@clear
	@./$(_BIN)$(BINARY)

.PHONY: clean # Por si alguna vez existe un fichero clean en esta carpeta
clean: 
	@clear
	rm -rf $(_BIN)$(BINARY)
	rm -rf $(_OBJ)*.o *.o