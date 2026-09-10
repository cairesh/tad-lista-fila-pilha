# Trabalho 1 - Laboratório de Programação II

Professor: Vanderson Hafemann Fragal

Implementação de Tipos Abstratos de Dados utilizando linguagem C.
Repositório: tad-lista-fila-pilha. Biblioteca estática de Lista, Fila e Pilha.

Divisão da equipe:
- Lista: [Henrique]
- Fila: [NOME]
- Pilha: [Arthur]

A Lista está implementada com vetor de capacidade 5, sem valores repetidos.
A busca sequencial retorna o índice (a partir de zero) ou -1. A inserção
adiciona ao final; a remoção por valor desloca os sucessores para a esquerda.
Não há ordenação automática. As structs são recebidas e retornadas por valor,
sem declaração de ponteiros ou alocação dinâmica. Crie a lista com
`criarLista()` e guarde alterações com `lista = inserirLista(lista, valor)`
e `lista = removerLista(lista, valor)`.

A Pilha está implementada com capacidade 5 e operações LIFO.
A Fila recebeu uma implementação inicial e ainda precisa de correções e testes.

Arquivos:
- `lista.c` / `lista.h`: registro, criação, busca, inserção, remoção,
  exibição e verificações de lista vazia/cheia.
- `fila.c` / `fila.h`: implementação inicial da fila circular FIFO, capacidade 6, pendente de correções.
- `pilha.c` / `pilha.h`: pilha LIFO, capacidade 5, com consulta ao topo.
- `TADs.h`: cabeçalho agregador dos três módulos.
- `main.c`: testes da Lista e Pilha e espaço para testes de Fila.
- `Makefile`: compilação atual e alvo para integração final.
- `TADs.a`: biblioteca gerada com os três objetos; não é versionada.

Compilar e executar com GCC e GNU Make (Linux):

```sh
make
make test
make final
./programa-final
```

No PowerShell com MinGW:

```powershell
mingw32-make
.\programa.exe
mingw32-make final
.\programa-final.exe
```

Nesta máquina, a criação dos objetos na pasta do workspace falhou com
`can't create main.o: No such file or directory`. A validação dos mesmos
fontes foi concluída sem warnings e com zero falhas nos dois modos em
`%TEMP%\tad-lista-validacao-20260905`. Se ocorrer o mesmo erro, execute:

```powershell
$buildTad = Join-Path $env:TEMP 'tad-lista-validacao-20260905'
New-Item -ItemType Directory -Path $buildTad -Force | Out-Null
Copy-Item -Path *.c,*.h,Makefile -Destination $buildTad
Push-Location $buildTad
mingw32-make
.\programa.exe
mingw32-make final
.\programa-final.exe
Pop-Location
```

O modo atual compila `main.c`, `lista.c` e `pilha.c`. O alvo `final` gera
`TADs.a` com `lista.o`, `fila.o` e `pilha.o`, e liga o cliente à biblioteca.
O alvo `final` está bloqueado por erros na implementação atual da Fila: uso de `NULL` como inteiro, contador não inicializado, parâmetro não utilizado e funções sem retorno em todos os caminhos. Os testes de Lista e Pilha passam no modo padrão.

Alternativa sem Make (no Windows, acrescente `.exe` ao nome do programa):

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c lista.c pilha.c -o programa
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror -c lista.c fila.c pilha.c
ar rcs TADs.a lista.o fila.o pilha.o
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c TADs.a -o programa-final
```

Os testes da Lista têm 10 chamadas explícitas de inserção e 9 de remoção,
intercaladas com buscas. Conferem conteúdo, índices, quantidade, duplicatas,
capacidade, remoções no início/meio/final, valor inexistente, reinserção,
zero como dado e lista vazia. O programa retorna 1 se houver falha e 0
se todas as verificações da Lista e da Pilha passarem. Os testes da Pilha
conferem conteúdo, topo, ordem LIFO, capacidade, overflow, underflow,
reutilização, zero e valores negativos repetidos, com 10 chamadas de
inserção e 10 de remoção.

Antes da entrega, corrigir a implementação e completar os testes da Fila
(ao menos 6 inserções e 6 remoções por estrutura), preencher os nomes e
executar o modo final com todos os testes.
