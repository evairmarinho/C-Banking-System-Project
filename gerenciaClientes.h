#ifndef GERENCIACLIENTES_H
#define GERENCIACLIENTES_H
#include "cliente.h"
TCliente clientes[20];
int totalClientes;
void adicionarCliente(TCliente cliente);//TCliente clientes[totalClientes]
TCliente getCliente();
TCliente getClienteCPF(char cpf[12]);
int existeCPF(char cpf[12]);
char* listarClientes();
TCliente getClienteConta();

#endif

