CC = gcc
AR = ar
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

ifeq ($(OS),Windows_NT)
EXT = .exe
else
EXT =
endif

.PHONY: all lista final test
all: final

# Ligacao direta dos tres modulos; alias lista mantido por compatibilidade.
lista: programa$(EXT)
programa$(EXT): main.o lista.o fila.o pilha.o
	$(CC) $(CFLAGS) main.o lista.o fila.o pilha.o -o $@

# Cliente ligado a biblioteca estatica completa.
final: programa-final$(EXT)
TADs.a: lista.o fila.o pilha.o
	$(AR) rcs $@ lista.o fila.o pilha.o
programa-final$(EXT): main.o TADs.a
	$(CC) $(CFLAGS) main.o TADs.a -o $@

main.o: main.c TADs.h lista.h fila.h pilha.h
lista.o: lista.c lista.h
fila.o: fila.c fila.h
pilha.o: pilha.c pilha.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: programa$(EXT) programa-final$(EXT)
	./programa$(EXT)
	./programa-final$(EXT)
