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

int Cliente::adicionarProduto(float preco, int codigo){
  if(preco <= saldo){
    sacola[codigo] +=1;
    saldo -=preco;
    return 0;
  }
  return 1;
}

std::unordered_map<int, int> Cliente::getSacola(){
  return sacola;
}