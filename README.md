# Trabalho 1 - Laboratório de Programação II

Professor: Vanderson Hafemann Fragal

Implementação de Tipos Abstratos de Dados utilizando linguagem C.
Repositório: tad-lista-fila-pilha. Biblioteca estática de Lista, Fila e Pilha.

Equipe: Henrique, Arthur e Samuel.

Divisão inicial: Lista com Henrique e Pilha com Arthur. A Fila foi
implementada por Samuel, concluída na integração final do projeto.

A Lista está implementada com vetor de capacidade 5, sem valores repetidos.
A busca sequencial retorna o índice (a partir de zero) ou -1. A inserção
adiciona ao final; a remoção por valor desloca os sucessores para a esquerda.
Não há ordenação automática. As structs são recebidas e retornadas por valor,
sem declaração de ponteiros ou alocação dinâmica. Crie a lista com
`criarLista()` e guarde alterações com `lista = inserirLista(lista, valor)`
e `lista = removerLista(lista, valor)`.

A Pilha está implementada com capacidade 5 e operações LIFO.
A Fila está implementada como vetor circular de capacidade 5, em ordem
FIFO, permitindo valores repetidos. `inicio` indica o primeiro elemento,
`fim` indica a próxima posição de inserção e `quantidade` distingue cheia
de vazia quando os índices coincidem. As operações não deslocam elementos.
Crie com `criarFila()` e guarde as alterações com
`fila = enqueue(fila, valor)` e `fila = dequeue(fila)`.
Consulte o primeiro elemento com `frenteFila(fila)` antes de remover.
Inserções em estruturas cheias e remoções em estruturas vazias preservam
o estado e exibem uma mensagem. `frenteFila` e `topoPilha` retornam -1
quando vazias; como -1 também é um dado válido, consulte `filaVazia` ou
`pilhaVazia` antes de ler. Todas as estruturas devem ser inicializadas
pelas respectivas funções de criação.

Arquivos:
- `lista.c` / `lista.h`: registro, criação, busca, inserção, remoção,
  exibição e verificações de lista vazia/cheia.
- `fila.c` / `fila.h`: fila circular FIFO, com consulta à frente.
- `pilha.c` / `pilha.h`: pilha LIFO, capacidade 5, com consulta ao topo.
- `TADs.h`: cabeçalho agregador dos três módulos.
- `main.c`: testes automáticos de Lista, Fila e Pilha.
- `Makefile`: compilação direta e com biblioteca estática, e testes.
- `TADs.a`: biblioteca estática incluída na entrega, com os três objetos.

A biblioteca incluída foi compilada no Windows com MinGW. Para executar
em outro ambiente, recompile a partir dos fontes com `make -B test`
(ou `mingw32-make -B test` no PowerShell). Isso recria a biblioteca para
o ambiente do professor e executa os testes dos três módulos.

Compilar e executar com GCC e GNU Make (Linux):

```sh
make
make test
```

No PowerShell com MinGW:

```powershell
mingw32-make
mingw32-make test
```

Nesta máquina, a criação dos objetos na pasta do OneDrive falhou com
`can't create main.o: No such file or directory`. Em 10/09/2026, os mesmos
fontes foram compilados com GCC, sem warnings e com zero falhas nos dois
modos, em uma pasta temporária. Se ocorrer o mesmo erro, execute a partir
da raiz do projeto:

```powershell
$buildTad = Join-Path $env:TEMP ('tad-validacao-' + [guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $buildTad -Force | Out-Null
Copy-Item -Path *.c,*.h,Makefile -Destination $buildTad
Push-Location $buildTad
try {
    mingw32-make test
    if ($LASTEXITCODE -ne 0) { throw 'Falha na compilação ou nos testes' }
} finally {
    Pop-Location
}
```

O alvo padrão (`all`, equivalente a `final`) gera `TADs.a` com `lista.o`,
`fila.o` e `pilha.o`, e liga o cliente à biblioteca em `programa-final`.
O alvo `lista`, mantido por compatibilidade, gera `programa` com ligação
direta dos três módulos. `test` compila e executa os dois programas e
interrompe com erro se algum teste falhar.

Alternativa sem Make (no Windows, acrescente `.exe` ao nome do programa):

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c lista.c fila.c pilha.c -o programa
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror -c lista.c fila.c pilha.c
ar rcs TADs.a lista.o fila.o pilha.o
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c TADs.a -o programa-final
```

Os testes da Lista têm 10 chamadas explícitas de inserção e 9 de remoção,
intercaladas com buscas. Conferem conteúdo, índices, quantidade, duplicatas,
capacidade, remoções no início/meio/final, valor inexistente, reinserção,
zero como dado e lista vazia. O programa retorna 1 se houver falha e 0
se todas as verificações das três estruturas passarem. Os testes da Pilha
conferem conteúdo, topo, ordem LIFO, capacidade, overflow, underflow,
reutilização, zero e valores negativos repetidos, com 10 chamadas de
inserção e 10 de remoção.

Os testes da Fila conferem a ordem FIFO após cada operação, consulta à
frente, quantidade, índices circulares, estados vazia/cheia, overflow,
underflow e reutilização. Há 8 chamadas de inserção e 9 de remoção antes
de mais 10 ciclos com três inserções e três remoções por ciclo, usando
zero e negativos repetidos. Cada estrutura atende ao mínimo de 6
inserções e 6 remoções.
