#include "Produto.hpp"

Produto::Produto(const int codigo, const std::string &nome, const std::string &unidadeMedida, const float precoUnidade) : 
codigo(codigo), nome(nome), unidadeMedida(unidadeMedida), precoUnidade(precoUnidade)
{
}

int Produto::getCodigo()
{
  return codigo;
}

std::string Produto::getNome()
{
  return nome;
}

std::string Produto::getUnidadeMedida()
{
  return unidadeMedida;
}

float Produto::getPrecoUnidade()
{
  return precoUnidade;
}