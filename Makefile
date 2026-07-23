CC = clang

CFLAGS = -I./quickjs -Wall -O2 -fPIC
LDFLAGS = -shared

SRC = src/js_bridge.c
OBJ = build/js_bridge.o
LIB = build/libkoreader-js.so

all: $(LIB)

$(OBJ): $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

$(LIB): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(LIB)

clean:
	rm -rf build/*
