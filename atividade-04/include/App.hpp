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
  Estabelecimento getEstabelecimento();
  void setEstabelecimento(const Estabelecimento);
};

#endif // APP_H