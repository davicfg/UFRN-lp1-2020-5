#if !defined(CLIENTE_H)
#define CLIENTE_H

#include <string>

class Cliente
{
public:
  std::string nome;
  std::string cpf;

  Cliente();

  std::string getNome();
  void setNome(std::string nome);
  std::string getCpf();
  void setCpf(std::string cpf);
};
#endif // CLIENTE_H