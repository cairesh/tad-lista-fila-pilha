# Trabalho 1 — Laboratório de Programação II

Implementação de Lista, Fila e Pilha em C, organizada em módulos e biblioteca estática.

Professor: Vanderson Hafemann Fragal.

## Estado do projeto

- Lista: implementada, com testes no programa principal.
- Fila e Pilha: aguardando implementação e testes.

## Compilar e executar

Requisitos: GCC e GNU Make (MinGW no Windows).

No Linux:

```sh
make
make test
```

No Windows (PowerShell):

```powershell
mingw32-make
.\programa.exe
```

O comando padrão compila a Lista e seus testes. O alvo `final` gera a biblioteca `TADs.a` e o executável `programa-final` (`programa-final.exe` no Windows) para integrar os três módulos.
