# ProjetoC
Projeto para a aula de Algoritimo e Logica de Programação

```
ProjetoC
├─ .clang-format
├─ build
│  └─ main.exe
├─ db
├─ includes
│  ├─ helps.h
│  ├─ includes.h
│  └─ sqlite3.h
├─ README.md
└─ src
   ├─ main.c
   └─ sqlite3.c

```

gcc src/main.c src/sqlite3.c -Iincludes -o build/main.exe

build/main


pra adicionar um icon vc cria um arquivo .rc como o resoucer.rc e adiciona o caminho pro arquico de imagem .ico e dps compila o .rc com "windres resource/resource.rc -O coff -o resource/resource.res" para ele virar .res e dps voce compila ele com o projeto, no caso gcc src/main.c resource.res src/sqlite3.c -Iincludes -o build/main.exe

ou execute mingw32-make.exe
```
ProjetoC
├─ .clang-format
├─ banco.db
├─ build
│  └─ main.exe
├─ db
│  └─ banco.db
├─ includes
│  ├─ db.h
│  ├─ helps.h
│  ├─ includes.h
│  └─ sqlite3.h
├─ Makefile
├─ README.md
├─ resources
│  ├─ icon.ico
│  ├─ resource.rc
│  └─ resource.res
└─ src
   ├─ main.c
   └─ sqlite3.c

```