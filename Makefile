TARGET = build/main
SRC = src/main.c lib/sqlite3.c src/db.c src/helps.c src/booting.c
INCLUDES = -Iincludes
CC = clang

# Detecta se é Windows (cmd) ou Unix (Linux/Termux)
ifeq ($(OS),Windows_NT)
    I = windres
    RC = resources/resource.rc
    RES = resources/resource.res
    RES_CMD = $(I) $(RC) -O coff -o $(RES)
    EXE_CMD = cmd /c $(TARGET)
else
    RES =
    RES_CMD =
    EXE_CMD = ./$(TARGET)
endif

all:
	$(RES_CMD)
	$(CC) $(SRC) $(RES) $(INCLUDES) -o $(TARGET)
	chmod +x $(TARGET)
	$(EXE_CMD)
