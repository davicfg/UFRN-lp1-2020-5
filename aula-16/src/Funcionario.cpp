#include <string>
#include "Funcionario.hpp"

Funcionario::Funcionario()
{
}

std::string Funcionario::getNome()
{
  return this->nome;
}

void Funcionario::setNome(std::string nome)
{
  this->nome = nome;
}

std::string Funcionario::getEmpresa()
{
  return this->empresa;
}

void Funcionario::setEmpresa(std::string empresa)
{
  this->empresa = empresa;
}

std::string Funcionario::getDepartamento()
{
  return this->departamento;
}

void Funcionario::setDepartamento(std::string departamento)
{
  this->departamento = departamento;
}

double Funcionario::getSalario()
{
  return this->salario;
}

void Funcionario::setSalario(double salario)
{
  this->salario = salario;
}

std::string Funcionario::getData_admissao()
{
  return this->data_admissao;
}

void Funcionario::setData_admissao(std::string data_admissao)
{
  this->data_admissao = data_admissao;
}
