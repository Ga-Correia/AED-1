# AED-1
 Códigos em C que fiz ao longo da disciplina de Algoritmos e Estruturas de Dados 1
 
 Descrição dos exercícios:
 
 ### lista_sequencial_estatica_livros.c
 
Desenvolva um algoritmo em linguagem C - utilizando lista estática sequencial -
que reproduza as atividades executadas pelo sistema de gerenciamento de reservas
da biblioteca. Nessa tarefa, vamos assumir que o seu programa será utilizado para
gerenciar as reservas de apenas um usuário. Além disso, são permitidas no máximo
10 reservas por usuário.

O programa deverá imprimir uma mensagem sempre que uma nova reserva for soli-
citada ou um livro for retirado. Se uma nova reserva for solicitada e a lista de reservas
estiver cheia, o programa deverá imprimir esta informação. Quando a reserva for
concluída, o programa deverá imprimir quantas reservas aquele usuário já realizou.

Quando um livro for retirado, a mensagem deverá incluir quantos livros aquele usuário
já retirou. Note que as inclusões de novas reservas ocorrem sempre ao final da lista.

A primeira entrada representa a quantidade de operações (reservas e retiradas) serão realizadas.
As entradas seguintes representam qual operação será realizada (1-reservar, 2-retirar), seguida de um espaço e numeração do livro.

### lista_encadeada_estatica_ra.c

Desenvolva um algoritmo em linguagem C - utilizando lista estática encadeada -
que forneça uma lista com os números de RA’s ordenados dos alunos que realizaram
a reserva de um determinado livro. Além disso, seu algoritmo também deve fornecer
quantos usuários de cada ano realizaram a reserva daquele livro.

Para obter essa informação, considere que o RA dos alunos do ICT muda de acordo
com o ano de entrada na universidade. Por exemplo, todos os alunos que entraram
em 2013 possuem um RA de 5 dígitos que inicia com 86. Os alunos que entraram em
2014, possuem um RA de 5 dígitos que inicia com 96. Os alunos que entraram em
2015 possuem RA de 6 dígitos que inicia com 106, assim por diante.

A primeira entrada representa a quantidade de operações (reservas e retiradas) serão realizadas.
As entradas seguintes representam qual operação será realizada (1-reservar, 2-retirar), seguida de um 
espaço e o número do RA de quem está realizando a movimentação, sendo: 60000 ≤ RA ≤ 140000.

### lista_dinamica_dup_encad.c

Desenvolvimento de um jogo em que o objetivo é que o usuário forme triplas de números que
juntas somem 10. Seu jogo funcionará assim:
- Inicialmente, uma sequência de 10 números inteiros entre 0 e 9 é fornecida ao
jogador. Por exemplo: 1 3 2 8 7 6 4 9 5 0
- Em seguida, o jogador terá 5 jogadas. Em cada jogada, o jogador fornece um
número para ser inserido na lista e a posição da lista na qual o número deverá
ser inserido. Por exemplo: 5 2
- Após a inserção, a lista é atualizada com o novo valor. Observe que os elemen-
tos da lista são deslocados para a direita para que a inserção ocorra na posição
desejada: 1 3 5 2 8 7 6 4 9 5 3
- Observe que agora existe uma tripla que soma 10: 1 3 5 2 8 7 6 4 9 5 3
- Agora, todos os elementos que formam a tripla de soma 10 são removidos da
lista: 1 8 7 6 4 9 5 3
- O objetivo do jogador é remover todos os elementos da lista.

Utilizando lista dinâmica duplamente encadeada, o algoritmo deve fornecer uma lista com a 
sequência inicial do jogo. Após cada jogada, seu algoritmo deverá imprimir a lista atualizada após 
as verificações de triplas e as remoções necessárias. Ao final da execução, seu algoritmo 
deve informar se o jogador ganhou ou perdeu o jogo. Note que o jogador ganha o jogo somente se esvaziar a lista.

O algoritmo deve ser capaz de realizar as seguintes operações:
- Inserção: Seu algoritmo deve permitir a inserção de números de acordo com
a posição informada pelo jogador. Note que a posição é calculada a partir
do primeiro elemento da lista. Esse primeiro elemento representa o primeiro
número da sequência inicial.
- Remoção: Seu algoritmo deve permitir a remoção de elementos em qualquer
posição.
- Análise: Após cada jogada, seu algoritmo deverá buscar por triplas de soma 10
e realizar as devidas remoções. Note que uma jogada não implica necessaria-
mente em remoção.

A primeira entrada contém uma sequência de 10 números iniciais. As próximas 5 entradas representam um número
inteiro N, 1 ≤ N ≤ 9 que é o valor a ser inserido, seguido de um espaço e a posição desejada de inserção.

### fila_estat_circular_aed.c

Desenvolva um algoritmo em linguagem C - utilizando uma fila estática circular -
para implementar uma fila com as tarefas. Ao final da execução, seu algoritmo deverá
imprimir a fila de tarefas.

Seu algoritmo deve ser capaz de realizar as seguintes operações:
- Inserção: Seu algoritmo deve permitir a inserção de tarefas. Note que a única
informação inserida na fila é o ID da tarefa. Como a estrutura utilizada é fila, a
inserção ocorre sempre no final da fila.
- Remoção: Seu algoritmo deve permitir a remoção de tarefas. Como a estrutura
utilizada é fila, a remoção ocorre sempre no inicio da fila.
- Conclusão: Seu algoritmo deve permitir a conclusão de tarefas. Nesse caso, o
elemento do início da fila deverá ser deslocado para o final da fila.

A primeira entrada contém o número de operações que serão realizadas As próximas entradas correspondem
aos 3 tipos de operações que podem ser realizadas:
- Inserção de Tarefas (1): Nesse caso, a linha é composta por 2 inteiros
separados por um espaço. O primeiro valor OP identifica a operação, no
caso 1. O segundo valor V, 1 ≤ V ≤ 100, indica o ID da tarefa. Ou seja, o
valor que será inserido na fila.
- Remoção de Tarefas (2): Nesse caso, a linha é composta por 1 inteiro OP
que identifica a operação, no caso 2.
- Conclusão de Tarefas (3): Nesse caso, a linha é composta por 1 inteiro OP
que identifica a operação, no caso 3.

Como saída padrão, seu programa deverá imprimir a fila ao final da execução. Além
disso, caso a fila esteja vazia e ocorra alguma tentativa de remoção ou conclusão de
tarefas, seu programa deverá imprimir a mensagem: "vazia".

### pilha_dinamica_binaria.c

Desenvolva um algoritmo em linguagem C - utilizando pilhas - que seja capaz de
transformar números decimais em binários e números binários em decimais. Assim,
dado um número N, seu algoritmo deverá efetuar as seguintes operações:
- Encontrar a representação binária Nbin do número N.
- Encontrar o número N_transfbin, que é o oposto do número Nbin. Ou seja, as
posições preenchidas por 1 em Nbin serão preenchidas com 0 em N_transfbin e
as posições preenchidas com 0 em Nbin serão preenchidas com 1 em N_transfbin.
- Encontrar a representação decimal N_transfdec do número N_transfbin.

Ao final da execução, seu algoritmo deverá imprimir o número original na repres-
entação decimal e binária, e o número resultante na representação binária e decimal.

A primeira entrada contém a quantidade de números que serão transformados. As próximas entradas
são os números em decimal que o usuário deseja converter para binário.


