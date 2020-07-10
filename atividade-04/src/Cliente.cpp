#include "Cliente.hpp"

int Cliente::idCliente;

Cliente::Cliente()
{
}

Cliente::Cliente(const float depositoInicial) : saldo(depositoInicial)
{
  this->idCliente++;
}

void Cliente::adicionarSaldo(const float deposito)
{
  if (deposito > 0)
  {
    saldo += deposito;
  }
}

float Cliente::getSaldo()
{
  return saldo;
}
