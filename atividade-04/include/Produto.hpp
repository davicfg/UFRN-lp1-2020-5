#if !defined(PRODUTO_H)
#define PRODUTO_H

#include <string>
class Produto
{
private:
  int codigo;
  std::string nome;
  std::string unidadeMedida;
  float precoUnidade;

public:
  Produto(const int codigo, const std::string &nome, const std::string &unidadeMedida, const float precoUnidade);
  int getCodigo();
  std::string getNome();
  std::string getUnidadeMedida();
  float getPrecoUnidade();
};

#endif // PRODUTO_H
