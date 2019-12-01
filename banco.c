#include"banco.h"
#include"gerenciaClientes.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


numeroConta=0;


TData dataHoje()
{
    TData dataT;
    time_t dataTime;
    time(&dataTime);
    struct tm*data=localtime(&dataTime);
    dataT.dia= data->tm_mday;
    dataT.mes = data->tm_mon +1;
    dataT.ano = data->tm_year+1900;
    return dataT;
}

void adicionarConta(TConta conta)
{
    if(totalClientes==0)
    {
        printf("\nNAO EXISTEM CLIENTES CADASTRADOS \nCADASTRE UM CLIENTE PRIMEIRO\n\n");
    }

    else
    {
        printf("Digite seu cpf cadastrado\n");
        char cpfCad[12];
        fflush(stdin);
        scanf("%[^\n]",cpfCad);
        if(existeCPF(cpfCad)==1)
        {
            if(existeCPFconta(cpfCad)==0)
            {
                conta.numero=numeroConta;
                printf("\nCONTA %i CRIADA \n\n",conta.numero);
                conta.cliente=getClienteCPF(cpfCad);
                printf("CLIENTE: %s \nNUMERO DA CONTA: %i \n",conta.cliente.nome,numeroConta);
                conta.saldo=10;
                printf("SALDO DA CONTA: R$ %.2f \n",conta.saldo);
                conta.ativa=1;
                conta.dataAbertura.dia=dataHoje().dia;
                conta.dataAbertura.ano=dataHoje().ano;
                conta.dataAbertura.mes=dataHoje().mes;
                printf("DATA DE ABERTURA: %i/%i/%i \n\n",conta.dataAbertura.dia,conta.dataAbertura.mes,conta.dataAbertura.ano);
                contas[numeroConta]=conta;
                numeroConta++;
            }
        }
        else
        {
            printf("NAO EXISTEM CLIENTES COM ESSE CPF CADASTRADO\n");
        }
    }
}


void listarContas()
{

    for (int i=0; i<numeroConta; i++)
    {
        imprimirConta(contas[i]);
    }


}
void pesquisarConta(int numero)
{


    for(int i=0; i<numeroConta; i++)
    {
        if(contas[numero].numero==contas[i].numero)
        {
            if(contas[numero].ativa==1)
            {

                imprimirConta(contas[numero]);
                imprimirCliente(contas[numero].cliente);


            }
            else
            {
                printf("CONTA %i ESTA DESATIVADA\n", numero);
                i=numeroConta;
            }

        }
    }

}

int existeConta(int num)
{

    int controle=0;
    for(int i=0; i<numeroConta; i++)
    {
        if(contas[i].numero==num)
        {

            return 1;
        }
        else
        {
            controle ++;
        }

    }
    if(controle==numeroConta)
    {
        printf("NAO EXISTE NENHUMA CONTA COM ESSE NUMERO\n");
        return 0;
    }


}
int existeCPFconta(char cpfs[12])
{
    int controle=0;
    for(int i=0; i<numeroConta; i++)
    {
        if(strcmp(contas[i].cliente.cpf,cpfs)==0)
        {
            printf("JA EXISTE UMA CONTA COM ESSE CPF NO REGISTRO\n");
            return 1;
        }
        else
        {
            controle++;
        }

    }
    if(controle==numeroConta)
    {

        return 0;
    }
}

TConta getConta1()
{

    return contas[numeroConta];
}

int removerConta(int numero)
{


    int controle =0;


    for(int i=0; i<numeroConta; i++)
    {
        if(numero==contas[i].numero)
        {
            if(contas[i].ativa==0)
            {


                printf("A CONTA JÁ FOI DESATIVADA ANTERIORMENTE\n");
                return 0;
            }
            else
            {
                if(contas[i].saldo==0.00)
                {

                    printf("CONTA REMOVIDA\n");
                    contas[i].ativa=0;
                    return 1;
                }
                else
                {
                    printf("O SALDO PRECISA SER IGUAL A 0\n");
                    contas[i].ativa=1;
                    return 0;
                }
            }

        }

    }
}
