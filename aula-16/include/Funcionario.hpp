#if !defined(FUNCIONARIO_H)
#define FUNCIONARIO_H
#include <string>

class Funcionario
{
private:
  std::string nome;
  std::string empresa;
  std::string departamento;
  double salario;
  std::string data_admissao;

public:
  Funcionario();

  std::string getNome();
  void setNome(std::string nome);
  std::string getEmpresa();
  void setEmpresa(std::string empresa);
  std::string getDepartamento();
  void setDepartamento(std::string departamento);
  double getSalario();
  void setSalario(double salario);
  std::string getData_admissao();
  void setData_admissao(std::string data_admissao);
};

#endif // FUNCIONARIO_H
