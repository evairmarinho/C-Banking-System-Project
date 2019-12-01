#ifndef CONTA_H
#define CONTA_H
#include "cliente.h"
typedef struct Data
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct Conta
{
    int numero;
    TCliente cliente;
    TData dataAbertura;
    float saldo;
    int ativa;
} TConta;
void depositar(TConta conta,float valor);
int debitar(TConta conta, float quantia);
int transferir(TConta origem, TConta destino,float quantia);
void imprimirConta(TConta conta);
#endif

