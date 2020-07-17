#if !defined(FORNECEDOR_H)
#define FORNECEDOR_H

#include "Item.hpp"
#include "vector_supermercado.hpp"

#include <string>
class Fornecedor
{
private:
  std::string nomeArquivo;
  vector_supermercado<int> estoque;
public:
  Fornecedor();
  int carregarEstoque();
  vector_supermercado<int> & getEstoque();
  int repassarProdutos(int quantidade, int codigo);
};
#endif // FORNECEDOR_H
