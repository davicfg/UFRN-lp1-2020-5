#if !defined(ESTABELECIMENTO_H)
#define ESTABELECIMENTO_H

#include "Cliente.hpp"
#include "Produto.hpp"

#include <unordered_map>
#include <vector>
#include <map>
#include <string>
class Estabelecimento
{
private:
  Cliente cliente;
  std::vector<Produto> produtos;
  std::unordered_map<int,int> estoque;
  std::string nomeArquivoEstoque;

public:
  Estabelecimento();
  ~Estabelecimento();
  Cliente &getCliente();
  std::vector<Produto> & getProdutos();
  std::unordered_map<int,int> & getEstoque();
  void setCliente(Cliente novoCliente);
  int carregarEstoque();
  int getEstoqueDisponivelProduto(int codigo);

};

#endif // ESTABELECIMENTO_H