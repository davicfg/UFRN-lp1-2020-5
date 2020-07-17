#include "Cliente.hpp"
#include "Produto.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

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

int Cliente::adicionarProduto(float preco, int codigo)
{
  if (preco <= saldo)
  {
    sacola[codigo] += 1;
    saldo -= preco;
    return 0;
  }
  return 1;
}

std::unordered_map<int, int> Cliente::getSacola()
{
  return sacola;
}

void Cliente::registrarCompra(std::vector<Produto> produtos)
{
  std::stringstream nomeArquivo;
  nomeArquivo << "cliente_" << (idCliente / 2) << ".txt";
  std::ofstream output(nomeArquivo.str());

  for (auto item : sacola)
  {
    std::ofstream sacola(nomeArquivo.str(), std::ios::app);
    sacola << "Produto: " << produtos[item.first - 1].getNome() << " ";
    sacola << "Quantidade: " << item.second << std::endl;
  }
  
}