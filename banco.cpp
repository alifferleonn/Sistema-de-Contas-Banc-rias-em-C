#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de conta bancária
typedef struct {
    int numero_conta;
    char nome_cliente[50];
    double saldo;
} ContaBancaria;

// Função para cadastrar uma conta
void cadastrarConta(ContaBancaria* contas, int* num_contas) {
    if (*num_contas >= 10) {
        printf("Limite de contas atingido.\n");
        return;
    }

    ContaBancaria novaConta;
    
    printf("Digite o número da conta: ");
    scanf("%d", &novaConta.numero_conta);
    
    printf("Digite o nome do cliente: ");
    scanf("%s", novaConta.nome_cliente);

    novaConta.saldo = 0.0;

    contas[*num_contas] = novaConta;
    (*num_contas)++;

    printf("Conta cadastrada com sucesso!\n");
}

// Função para fazer um depósito
void realizarDeposito(ContaBancaria* contas, int num_contas, int numero_conta, double valor) {
    for (int i = 0; i < num_contas; i++) {
        if (contas[i].numero_conta == numero_conta) {
            contas[i].saldo += valor;
            printf("Depósito realizado com sucesso.\n");
            printf("Saldo atualizado: %.2lf\n", contas[i].saldo);
            return;
        }
    }
    printf("Conta não encontrada.\n");
}

// Função para fazer uma retirada
void realizarRetirada(ContaBancaria* contas, int num_contas, int numero_conta, double valor) {
    for (int i = 0; i < num_contas; i++) {
        if (contas[i].numero_conta == numero_conta) {
            if (contas[i].saldo >= valor) {
                contas[i].saldo -= valor;
                printf("Retirada realizada com sucesso.\n");
                printf("Saldo atualizado: %.2lf\n", contas[i].saldo);
            } else {
                printf("Saldo insuficiente para realizar a retirada.\n");
            }
            return;
        }
    }
    printf("Conta não encontrada.\n");
}

int main() {
    ContaBancaria* contas = (ContaBancaria*)malloc(10 * sizeof(ContaBancaria));
    int num_contas = 0;
    
    int opcao;
    
    do {
        printf("\nOpções:\n");
        printf("1. Cadastrar conta\n");
        printf("2. Realizar depósito\n");
        printf("3. Realizar retirada\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarConta(contas, &num_contas);
                break;
            case 2:
                int numero_conta_dep;
                double valor_dep;
                printf("Digite o número da conta para depósito: ");
                scanf("%d", &numero_conta_dep);
                printf("Digite o valor do depósito: ");
                scanf("%lf", &valor_dep);
                realizarDeposito(contas, num_contas, numero_conta_dep, valor_dep);
                break;
            case 3:
                int numero_conta_ret;
                double valor_ret;
                printf("Digite o número da conta para retirada: ");
                scanf("%d", &numero_conta_ret);
                printf("Digite o valor da retirada: ");
                scanf("%lf", &valor_ret);
                realizarRetirada(contas, num_contas, numero_conta_ret, valor_ret);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    free(contas);

    return 0;
}
