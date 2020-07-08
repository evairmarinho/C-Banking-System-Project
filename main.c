#include<time.h>
#include"gerenciaClientes.h"
#include"banco.h"
#include"cliente.h"
#include"conta.h"
#include <stdio.h>
#include <stdlib.h>

//ATUALIZADO DESDE 07/07/2020
void menu() // função para interface de menu
{

    printf("--------MENU--------\n\n");
    printf("1 - CADASTRAR CLIENTE\n");
    printf("2 - CADASTRAR CONTA\n");
    printf("3 - LISTAR CONTA\n");
    printf("4 - PESQUISAR CONTA\n");
    printf("5 - DEPOSITAR\n");
    printf("6 - DEBITAR(SACAR)\n");
    printf("7 - TRANSFERIR\n");
    printf("8 - REMOVER CONTA\n");
    printf("9 - SAIR\n");
    printf("Digite a opcao: \n");


}

int main()
{

    char opcao;
    do
    {

        menu();
        scanf(" %c",&opcao);//leitura da opção escolhida pelo usuário
        switch(opcao)
        {
        case '1':
            adicionarCliente(getCliente());
            break;
        case '2':
            adicionarConta(getConta1());
            break;
        case '3':
            if(numeroConta > 0)
            {
                listarContas();
            }
            else
            {
                printf("CADASTRE UMA CONTA PRIMEIRO!!!\n");
            }
            break;
        case '4':
            if(numeroConta > 0)
            {
                printf("Digite o numero da sua conta\n");
                int num;
                scanf("%i",&num);
                if(existeConta(num) == 1)
                {
                    pesquisarConta(num);
                }
            }
            else
            {
                printf("CADASTRE UMA CONTA PRIMEIRO!!!\n");
            }
            break;
        case '5':

            if(numeroConta > 0)
            {
                printf("Digite o numero da sua conta\n");
                int num3;
                scanf("%i",&num3);

                if(existeConta(num3) == 1)
                {
                    TConta conta;
                    conta.numero = num3;
                    printf("Digite o valor de deposito\n");
                    float quantia;
                    scanf("%f",&quantia);
                    depositar(conta,quantia);
                }
            }
            else
            {
                printf("CADASTRE UMA CONTA PRIMEIRO!!!\n");
            }
            break;
        case '6':
            if(numeroConta > 0)
            {
                printf("Digite o numero da sua conta\n");
                int num;
                scanf("%i",&num);
                if(existeConta(num) == 1)
                {
                    printf("Digite o valor de saque\n");
                    float valor;
                    scanf("%f",&valor);
                    TConta conta;
                    conta.numero = num;
                    debitar(conta,valor);
                }
            }
            else
            {
                printf("CADASTRE UMA CONTA PRIMEIRO!!!\n");
            }
            break;
        case '7':
            if(numeroConta > 0)
            {
                if(numeroConta > 1)
                {
                    printf("Digite o numero da sua conta\n");
                    int num;
                    scanf("%i",&num);
                    if(existeConta(num) == 1)
                    {
                        TConta conta1;
                        conta1.numero = num;
                        printf("Digite o numero da conta que terá o valor transferido\n");
                        int num2;
                        scanf("%i",&num2);
                        if(existeConta(num2) == 1)
                        {
                            if(num2 != num)
                            {
                                TConta conta2;
                                conta2.numero = num2;
                                float valor;
                                printf("Digite a quantia que você quer transferir\n");
                                scanf("%f",&valor);
                                transferir(conta1,conta2,valor);
                            }
                            else
                            {
                                printf("VOCE NAO PODE TRANSFERIR PARA SUA PROPRIA CONTA!!!\n");
                            }
                        }
                    }

                }
                else
                {
                    printf("CADASTRE NO MINIMO DUAS CONTAS!!!\n");
                }
            }
            else
            {
                printf("CADASTRE UMA CONTA PRIMEIRO!!!\n");
            }
            break;
        case '8':
            if(numeroConta > 0)
            {
                printf("Digite o numero da conta que deseja remover\n");
                int remover;
                scanf("%i",&remover);
                if(existeConta(remover) == 1)
                {

                    removerConta(remover);
                }

            }
            else
            {
                printf("CADASTRE UMA CONTA PRIMEIRO!!!\n");
            }
            break;
        case '9':
            printf("\nFIM DO PROGRAMA...\n");

            break;
        default:
            printf("\nOPCAO INVALIDA!!!\n\n"); //mensagemn de erro
            printf("Digite numeros de 1 a 9\n\n"); //recomendação para o usuário


        }
    }
    while (opcao != '9'); // o loop rodará enquanto a opção não for igual a de número 9 - (Saída do Programa)
    return 0;
}






