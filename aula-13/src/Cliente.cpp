#include "Cliente.hpp"

Cliente::Cliente (){

}

  std::string Cliente::getNome()
  {
    return this->nome;
  }

  void Cliente::setNome(std::string nome)
  {
    this->nome = nome;
  }

  std::string Cliente::getCpf()
  {
    return this->cpf;
  }

  void Cliente::setCpf(std::string cpf)
  {
    this->cpf = cpf;
  }