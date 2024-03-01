# Sistema-de-Contas-Bancarias-em-C
Este programa em C implementa um sistema simples de contas bancárias. Ele permite cadastrar contas, realizar depósitos e retiradas, mantendo o controle do saldo de cada conta.

## Estrutura do Projeto
`main.c`

O arquivo principal contém a função main que coordena o menu de opções, chama as funções correspondentes e gerencia a interação com o usuário.

`contabancaria.h`

O arquivo de cabeçalho define a estrutura ContaBancaria e as assinaturas das funções utilizadas no projeto.

`contabancaria.c`

O arquivo de implementação contém as funções responsáveis por cada operação no sistema de contas bancárias, como cadastrar conta, realizar depósito e realizar retirada.

## Funcionalidades
  - __Cadastrar Conta:__ Permite cadastrar uma nova conta bancária com um número, nome do cliente e saldo inicial zerado.

  - __Realizar Depósito:__ Permite realizar depósitos em uma conta existente, atualizando o saldo.

  - __Realizar Retirada:__ Permite realizar retiradas de uma conta existente, desde que haja saldo suficiente.

  - __Encerrar Programa:__ Encerra a execução do programa.

## Como Usar
  - Compile o programa usando um compilador C.
  - Execute o programa gerado.
  -Escolha uma opção do menu para interagir com o sistema de contas bancárias.

## Observações
  - O programa suporta até 10 contas bancárias.
  - O saldo de uma conta não pode ser negativo.

## Autor
Feito por: Aliffer Leonn
