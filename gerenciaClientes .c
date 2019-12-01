#include"gerenciaClientes.h"
#include"validações.h"
#include<stdio.h>
#include<stdlib.h>
totalClientes=0;
int i=0;
void adicionarCliente(TCliente cliente)
{
    printf("Digite seu nome \n");
    fflush(stdin);
    gets(cliente.nome);
    if(validaString(cliente.nome)==1)
    {
        printf("Digite seu CPF:\n");
        fflush(stdin);
        gets(cliente.cpf);
        if(validaNumeros(cliente.cpf)==1)
        {
            if(existeCPF(cliente.cpf)==0)
            {
                printf("Digite seu telefone (apenas os numeros e com o ddd)\n");
                fflush(stdin);
                scanf("%[^\n]",cliente.telefone);
                if(validaNumeros(cliente.telefone)==1)
                {
                    clientes[totalClientes]=cliente;
                    totalClientes++;
                }
            }
            else if(existeCPF(cliente.cpf)==1)
            {
                printf("\nCPF JA CONSTA NO REGISTRO DE CLIENTES\n\n");
            }
        }
    }
}


TCliente getCliente()
{
    return clientes[totalClientes];

}

TCliente getClienteCPF(char cpfs[12])
{

    for(int i=0; i<totalClientes; i++)
    {


        if(strcmp(cpfs,clientes[i].cpf)==0)
        {
            return clientes[i];
        }
    }
}

int existeCPF(char cpf[12])
{

    int controle=0;
    for(int i=0; i<totalClientes; i++)
    {
        if(strcmp(clientes[i].cpf,cpf)==0)
        {

            return 1;
        }
        else
        {
            //cada vez que o cpf digitado pelo usuário não correponde ao vetor n de clientes, é incrementado 0
            controle ++;
        }

    }
    if(controle==totalClientes)
    {
        //ainda não existem clientes com esse cpf
        return 0;
    }


}


char* listarClientes()
{
    for( i=0; i<totalClientes; i++)
    {
        imprimirCliente(clientes[i]);
    }
}
