#ifndef BANCO_H
#define BANCO_H
#include "conta.h"
TConta contas[10];
int numeroConta;

void adicionarConta(TConta conta);
void listarContas();
void pesquisarConta(int numero);
TConta getConta1();
int existeConta(int numero);
int removerConta(int numero);
#endif

