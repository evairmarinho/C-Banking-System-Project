#include "cliente.h"
#include<stdio.h>
#include<stdlib.h>
void imprimirCliente(TCliente cliente)
{

    printf("CLIENTE: %s\n",cliente.nome);
    printf("CPF: %s \n",cliente.cpf);
    printf("TELEFONE: %s \n",cliente.telefone);
    printf("-------------------------\n\n");
}
