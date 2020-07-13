#include <iostream>
#include <string>
#include <list>

#include "Empresa.hpp"
#include "Funcionario.hpp"

void criar_funcionarios(size_t quantidade, Empresa empresa, std::list<Funcionario> & funcionarios){
  Funcionario novo_funcionario;

  for (size_t i = 0; i < quantidade; i++)
  {
    
    novo_funcionario.setEmpresa(empresa.getNome());

    std::cout << "Funcionario:   " << i+1 << std::endl;

    std::string nome;
    std::cout << "nome:" << std::endl;
    std::cin >> nome;
    novo_funcionario.setNome(nome);


    std::string departamento;
    std::cout << "departamento:" << std::endl;
    std::cin >> departamento;
    novo_funcionario.setDepartamento(departamento);

    double salario;
    std::cout << "salario:" << std::endl;
    std::cin >> salario;
    novo_funcionario.setSalario(salario);

    std::string data_admissao;
    std::cout << "data admissao:" << std::endl;
    std::cin >> data_admissao;
    novo_funcionario.setData_admissao(departamento);

    funcionarios.push_back(novo_funcionario);
  }
}

void aumento_salario(std::string departamento, std::list<Funcionario> & funcionarios){
  for(auto funcionario : funcionarios)
  {
    if(funcionario.getDepartamento() == departamento){
      funcionario.setSalario(funcionario.getSalario() * 1.1);

    }
  }
}


int main(int argc, char const *argv[])
{
  Empresa nova_empresa("locaweb", "00.00.2323");

  size_t quantidade = 0;
  std::cout << "Quantos funcionarios?" << std::endl;
  std::cin >> quantidade;
  std::list<Funcionario> funcionarios;
  criar_funcionarios(quantidade, nova_empresa, funcionarios);

  return 0;
}
