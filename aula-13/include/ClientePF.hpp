#if !defined(CLIENTEPF_H)
#define CLIENTEPF_H

#include "Cliente.hpp"

#include <string>

class ClientePF: public Cliente
{
public:
  std::string nome;
  std::string cpf;

  ClientePF(int cep);

  std::string getNome();
  void setNome(std::string nome);
  std::string getCpf();
  void setCpf(std::string cpf);
};
#endif // CLIENTEPF_H