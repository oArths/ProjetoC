# ProjetoC

Projeto desenvolvido para a disciplina de **Algoritmos e Lógica de Programação**.  
O objetivo é aplicar conceitos fundamentais de programação em C, com uso de **banco de dados SQLite**, organização modular de código e compilação multiplataforma com **Makefile** e **recursos gráficos** no Windows.

## Compilação

### Compilação simples

1 - Para compilar o projeto manualmente:

```bash
gcc src/main.c src/sqlite3.c -Iincludes -o build/main.exe
```

2 - Executar projeto manualmente:

```bash
build/main.exe
```

### Compilação com ícone (Windows)

1 - Crie o arquivo .res a partir do .rc com o seguinte comando:

```bash
windres resources/resource.rc -O coff -o resources/resource.res
```

2 - Compile o projeto incluindo o recurso:

```bash
gcc src/main.c resources/resource.res src/sqlite3.c -Iincludes -o build/main.exe
```

### Compilação com Makefile
- Você pode simplificar tudo com o comando:

```bash
mingw32-make  
```
Requer Makefile configurado corretamente e o mingw32-make.exe instalado no sistema.

## Estrutura do Projeto

```bash
ProjetoC
├─ .clang-format
├─ build
│  └─ main.exe
├─ db
│  └─ banco.db
├─ includes
│  ├─ booting.h
│  ├─ db.h
│  ├─ helps.h
│  ├─ modelos.h
│  └─ sqlite3.h
├─ lib
│  └─ sqlite3.c
├─ Makefile
├─ README.md
├─ resources
│  ├─ icon.ico
│  ├─ resource.rc
│  └─ resource.res
└─ src
   ├─ booting.c
   ├─ db.c
   ├─ helps.c
   └─ main.c
```

## Banco de Dados

O projeto utiliza SQLite como banco de dados local, com as seguintes tabelas criadas:

- User
- Notas
- UserNotas
- Tags
- NotaTags

O banco é salvo no arquivo ./db/banco.db.