#if !defined(APP_H)
#define APP_H

#include "Estabelecimento.hpp"

class App
{
private:
  Estabelecimento estabelecimento;

public:
  App();
  void run();
  Estabelecimento & getEstabelecimento();
  void setEstabelecimento(const Estabelecimento);
  void adicionarSaldo();
  void listarProdutos();
  void adicionarProdutoSacola();
  void verSacolaCliente();
};

#endif // APP_H