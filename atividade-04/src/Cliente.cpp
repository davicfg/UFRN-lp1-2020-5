#include "Cliente.hpp"
#include <iostream>
int Cliente::idCliente = 0;

Cliente::Cliente()
{
}

Cliente::Cliente(float depositoInicial) : saldo(depositoInicial)
{
  idCliente++;
}

void Cliente::adicionarSaldo(float deposito)
{
  if (deposito > 0.0)
  {
    this->saldo += deposito;
  }
}

float Cliente::getSaldo()
{
  return this->saldo;
}
