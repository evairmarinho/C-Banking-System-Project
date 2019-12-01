#include"conta.h"
#include "banco.h"
#include<stdio.h>
#include<stdlib.h>

void depositar(TConta conta,float valor)
{
    if(valor<=0)
    {

        printf("NAO EH POSSIVEL DEPOSITAR UM VALOR MENOR OU IGUAL A 0\n");
    }
    else
    {

        for(int i=0; i<numeroConta; i++)
        {
            if(contas[i].numero==conta.numero)
            {
                if(contas[i].ativa==1)
                {
                    for(int i=0; i<numeroConta; i++)
                    {
                        if(contas[i].numero==conta.numero)

                        {
                            contas[i].saldo+=valor;
                            printf("Atualizacao do saldo: R$ %.2f\n",contas[i].saldo);
                            i=numeroConta;
                        }
                    }
                }
                else
                {
                    printf("CONTA %i DESATIVADA\n",conta.numero);
                    i=numeroConta;
                }

            }

        }
    }
}


int debitar(TConta conta, float quantia)
{

    for(int i=0; i<numeroConta; i++)
    {
        if(conta.numero==contas[i].numero)
        {

            if(contas[i].ativa==1)
            {
                if(quantia>0&&(quantia<=contas[i].saldo))
                {
                    contas[i].saldo-=quantia;
                    printf("SALDO ATUAL: R$ %.2f \n",contas[i].saldo);
                    return 1;
                }


                if(quantia==0)
                {
                    printf("NAO EH POSSIVEL SACAR R$ 0\n");
                    return 0;

                }
                if(quantia<0)
                {
                    printf("NAO EH POSSIVEL SACAR UM VALOR NEGATIVO\n");
                    return 0;
                }
                if(quantia>contas[i].saldo)
                {
                    printf("QUANTIA SOLICITADA DE SAQUE EH MAIOR QUE O SALDO\n");
                    return 0;
                }

            }
            else
            {
                printf("CONTA %i DESATIVADA\n",contas[i].numero);
                return 0;
            }
        }
    }
}




int transferir(TConta origem, TConta destino,float quantia)
{


    for(int i=0; i<numeroConta; i++)
    {

        if(contas[i].numero==origem.numero)
        {
            if(contas[i].ativa==0)
            {

                printf("A CONTA %i ESTA DESATIVADA\n",contas[i].numero);
            }
            else
            {
                for(int i=0; i<numeroConta; i++)
                {
                    if(contas[i].numero==destino.numero)
                    {


                        if(contas[i].ativa==0)

                        {
                            printf("A CONTA %i ESTA DESATIVADA\n",contas[i].numero);

                        }
                        if(quantia>0)
                        {
                            if(contas[origem.numero].saldo>=quantia)
                            {


                                contas[origem.numero].saldo-=quantia;
                                contas[destino.numero].saldo+=quantia;
                                printf("SALDO ATUAL DA SUA CONTA: R$ %.2f \n",contas[origem.numero].saldo);
                            }
                            else
                            {


                                printf("SALDO INSUFICIENTE PARA TRANSFERÊNCIA\n");

                            }
                        }
                        else if(quantia<0)
                        {
                            printf("NAO EH POSSIVEL TRANSFERIR UM VALOR NEGATIVO DE R$ %.2f\n",quantia);

                        }
                        if(quantia==0)
                        {
                            printf("NAO EH POSSIVEL TRANSFERIR R$ 0.00\n");

                        }



                    }
                }
            }
        }

    }
}




void imprimirConta(TConta conta)
{
    printf("\n-------- CONTA: %i-------- \n",conta.numero);
    if(conta.ativa==0)
    {
        printf("STATUS DA CONTA: DESATIVADA \n");
    }
    else if(conta.ativa==1)
    {
        printf("STATUS  DA CONTA: ATIVA \n");
    }
    printf("SALDO DA CONTA: R$ %.2f\n",conta.saldo);
    printf("DATA DE ABERTURA DA CONTA: %i/%i/%i \n",conta.dataAbertura.dia,conta.dataAbertura.mes,conta.dataAbertura.ano);

}
