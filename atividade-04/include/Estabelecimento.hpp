#if !defined(ESTABELECIMENTO_H)
#define ESTABELECIMENTO_H

#include "Cliente.hpp"

// #include "Produto.hpp"
#include <vector>
#include <string>
class Estabelecimento
{
private:
  Cliente cliente;
  // std::vector<Produto> produtos;
  std::string nomeArquivoEstoque;

public:
  Estabelecimento();
  ~Estabelecimento();
  Cliente &getCliente();
  void setCliente(Cliente novoCliente);
  // int carregarEstoque();

};

#endif // ESTABELECIMENTO_H