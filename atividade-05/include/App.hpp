#if !defined(APP_H)
#define APP_H

#include "Estabelecimento.hpp"
#include "Fornecedor.hpp"
class App
{
private:
  Estabelecimento estabelecimento;

  Fornecedor fornecedor;
public:
  App();
  ~App();
  void run();
  Estabelecimento & getEstabelecimento();
  void setEstabelecimento(const Estabelecimento);
  void adicionarSaldo();
  void listarProdutos();
  void adicionarProdutoSacola();
  void verSacolaCliente();
  void verCaixa();
  void finalizarCompra();
  void listarProdutosFornecedor();
  void reabastercerEstabelecimento();
};

#endif // APP_H