#if !defined(CLIENTE_H)
#define CLIENTE_H

#include "Produto.hpp"
#include "vector_supermercado.hpp"
#include "Item.hpp"
#include<vector>
#include<unordered_map>

class Cliente
{
private:
  float saldo;
  std::unordered_map<int, int> sacola;
public:
  static int idCliente;
  Cliente();
  Cliente(float depositoInicial);
  void adicionarSaldo(float deposito);
  float getSaldo();
  int adicionarProduto(float preco, int codigo);
  std::unordered_map<int, int> getSacola();
  int localizerProduto(int codigo);
  void registrarCompra(std::vector<Produto> produtos);
  
};

#endif // CLIENTE_H