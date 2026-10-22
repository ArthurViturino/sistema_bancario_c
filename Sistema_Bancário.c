// Sistema básico de caixa eletrônico em C
#include <stdio.h>
#include <locale.h>

int main () {
    setlocale(LC_ALL, "");

// Declaração de variáveis
    int opcao = 0;
    float saldo = 0.0;
    float valor = 0.0;

// Apresentação do sistema
    printf("=====================================================\n");
    printf("             BEM-VINDO AO BANCO VITURINO            \n");
    printf("=====================================================\n");
    printf("Proposito: Sistema interativo para gestao financeira\n");
    printf("           e consultas bancarias em tempo real.\n");
    printf("----------------------------------------------------\n");
    printf("Ola! Estamos felizes em ter voce por aqui.\n");
    printf("\n\n");

do {
    printf("=====================================\n");
    printf("           MENU PRINCIPAL            \n");
    printf("=====================================\n");
    printf("1. Consultar saldo\n");
    printf("2. Realizar saque\n");
    printf("3. Realizar deposito\n");
    printf("4. Sair\n");
    printf("-------------------------------------\n");
    printf("Escolha uma opcao: ");

if  (scanf("%d", &opcao) != 1) {
    printf("\n[ERRO] Entrada invalida! Por favor, digite apenas as opcoes validas.\n\n");
    while (getchar() != '\n'); 
    opcao = 0;
    continue;
}

// Processamento das opcoes do menu
switch (opcao) {
    case 1:
    printf("\n-------------------------------------\n");
    printf("  SALDO ATUAL: R$ %.2f\n", saldo);
    printf("-------------------------------------\n\n");
break;

    case 2:
    printf("\n-------------------------------------\n");
    printf("          REALIZAR SAQUE             \n");
    printf("-------------------------------------\n");
    printf("Digite o valor do saque: R$ ");

if (scanf("%f", &valor) != 1) {
    printf("\n[ERRO] Valor invalido! Digite apenas numeros.\n");
        while (getchar() != '\n');
        } else if (valor <= 0) {
    printf("\n[ERRO] O valor do saque deve ser maior que zero!\n");
        } else if (valor > saldo) {
    printf("\n[ERRO] OPERACAO CANCELADA!\n");
    printf("Saldo insuficiente. Seu saldo atual e de R$ %.2f\n", saldo);
        } else {
    saldo -= valor;
    printf("\n[SUCESSO] Saque de R$ %.2f realizado com sucesso!\n", valor);
    printf("Novo saldo disponivel: R$ %.2f\n", saldo);
        }
    printf("-------------------------------------\n\n");
break;

    case 3:
    printf("\n-------------------------------------\n");
    printf("         REALIZAR DEPOSITO           \n");
    printf("-------------------------------------\n");
    printf("Digite o valor do deposito: R$ ");
if (scanf("%f", &valor) != 1) {
    printf("\n[ERRO] Valor invalido! Digite apenas numeros.\n");
        while (getchar() != '\n');
        } else if (valor <= 0) {
    printf("\n[ERRO] O valor do deposito deve ser maior que zero!\n");
        } else {
    saldo += valor;
    printf("\n[SUCESSO] Deposito de R$ %.2f realizado com sucesso!\n", valor);
    printf("Novo saldo disponivel: R$ %.2f\n", saldo);
        }
    printf("-------------------------------------\n\n");
break;

    case 4:
    printf("\n=========================================\n");
    printf(" Obrigado por utilizar o BANCO VITURINO!\n");
    printf("      Tenha um excelente dia.        \n");
    printf("=========================================\n\n");
break;

    default:
if (opcao != 0) {
    printf("\n[ERRO] Opcao invalida! Escolha um numero entre 1 e 4.\n\n");
        }
break;
        }

} while (opcao != 4);

return 0;
}