TARGET = build/main.exe
EXE = build\\main.exe
SRC = src/main.c lib/sqlite3.c src/db.c src/helps.c src/booting.c
INCLUDES = -Iincludes
CC = gcc

I = windres 
RC = resources/resource.rc 
RES = resources/resource.res

all:
	$(I) $(RC) -O coff -o $(RES)

	$(CC) $(SRC) $(RES) $(INCLUDES) -o $(TARGET)

	cmd /c $(EXE)