#ifndef CLIENTE_H
#define CLIENTE_H
typedef struct Cliente
{
    char nome[50];
    char* cpf[12];
    char telefone[10];
} TCliente;
void imprimirCliente(TCliente cliente);
#endif
