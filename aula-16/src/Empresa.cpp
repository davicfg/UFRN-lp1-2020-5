#include "Empresa.hpp"

Empresa::Empresa(std::string nome, std::string cnpj) : nome(nome), cnpj(cnpj)
{
}

std::string Empresa::getNome()
{
  return this->nome;
}

void Empresa::setNome(std::string nome)
{
  this->nome = nome;
}

std::string Empresa::getCnpj()
{
  return this->cnpj;
}

void Empresa::setCnpj(std::string cnpj)
{
  this->cnpj = cnpj;
}