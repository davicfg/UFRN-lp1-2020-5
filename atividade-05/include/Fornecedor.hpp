#if !defined(FORNECEDOR_H)
#define FORNECEDOR_H

#include "Item.hpp"
#include "vector_supermercado.hpp"

#include <vector>
#include <string>
class Fornecedor
{
private:
  std::string nomeArquivo;
  std::string cabecalhoArquivo = "PRODUTO,QUANTIDADE";
  std::vector<std::string> estoqueNome;
  vector_supermercado<int> estoque;
public:
  Fornecedor();
  int carregarEstoque();
  vector_supermercado<int> & getEstoque();
  int repassarProdutos(int quantidade, int codigo);
  void registrarEstoque();
};
#endif // FORNECEDOR_H
