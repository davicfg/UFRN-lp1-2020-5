#include "ClientePJ.hpp"

ClientePJ::ClientePJ() {}

std::string ClientePJ::getRazaoSocial()
{
  return this->razaoSocial;
}
void ClientePJ::setRazaoSocial(std::string rs)
{
  this->razaoSocial = rs;
}
std::string ClientePJ::getCnpj()
{
  return this->cnpj;
}
void ClientePJ::setCnpj(std::string c)
{
  this->cnpj = c;
}