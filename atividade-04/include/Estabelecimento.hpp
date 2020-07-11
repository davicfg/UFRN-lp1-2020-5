#if !defined(ESTABELECIMENTO_H)
#define ESTABELECIMENTO_H

#include "Cliente.hpp"
#include "Produto.hpp"

#include <unordered_map>
#include <vector>
#include <string>
class Estabelecimento
{
private:
  Cliente cliente;
  std::vector<Produto> produtos;
  std::unordered_map<int,int> estoque;
  std::unordered_map<int,int> vendas;
  std::string nomeArquivoEstoque;
  std::string cabecalhoEstoque = "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE"; 
public:
  Estabelecimento();
  ~Estabelecimento();
  Cliente &getCliente();
  std::vector<Produto> & getProdutos();
  std::unordered_map<int,int> & getEstoque();
  void setCliente(Cliente novoCliente);
  int carregarEstoque();
  int getEstoqueDisponivelProduto(int codigo);
  std::unordered_map<int, int>  verSacolaCliente();
  void adicionarProdutoCaixa(int codigoProduto);
  void saidaProdutoEstoque(int codigoProduto);
  std::unordered_map<int, int> caixa();
  void registrarCliente();
  void registrarEstoque();
  void registrarVendas();

};

#endif // ESTABELECIMENTO_H