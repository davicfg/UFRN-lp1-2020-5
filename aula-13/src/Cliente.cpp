#include "Cliente.hpp"

Cliente::Cliente(int cep){
  this->cep = cep;
}

int Cliente::getCep(){
  return this->cep;
}

void Cliente::setCep(int novoCep){
  this->cep = novoCep;
}