#include "ClientePF.hpp"

ClientePF::ClientePF (int cep): Cliente(cep){

}

  std::string ClientePF::getNome()
  {
    return this->nome;
  }

  void ClientePF::setNome(std::string nome)
  {
    this->nome = nome;
  }

  std::string ClientePF::getCpf()
  {
    return this->cpf;
  }

  void ClientePF::setCpf(std::string cpf)
  {
    this->cpf = cpf;
  }