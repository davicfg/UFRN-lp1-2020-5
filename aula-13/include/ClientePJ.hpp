#if !defined(CLIENTEPJ_H)
#define CLIENTEPJ_H

#include <string>

class ClientePJ
{
public:
  std::string razaoSocial;
  std::string cnpj;

  ClientePJ();
  std::string getRazaoSocial();
  void setRazaoSocial(std::string rs);
  std::string getCnpj();
  void setCnpj(std::string c);

};
#endif // CLIENTEPJ_H