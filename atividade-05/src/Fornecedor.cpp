#include "Fornecedor.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>


Fornecedor::Fornecedor()
{
  nomeArquivo = "fornecedor.csv";
}

int Fornecedor::carregarEstoque()
{
  std::ifstream file;

  file.open(nomeArquivo);

  if (!file.is_open())
  {
    return 1;
  }

  std::string file_line;

  std::getline(file, file_line);

  std::string nomeProduto;
  int quantidade;

  while (!file.eof())
  {
    if (file_line.size() == 0)
    {
      continue;
    }
    std::getline(file, file_line);
    replace(file_line.begin(), file_line.end(), ',', ' ');

    std::stringstream stream(file_line);
    stream >> nomeProduto;
    stream >> quantidade;

    estoque.push(quantidade);
  }

  file.close();
  return 0;
}


vector_supermercado<int> & Fornecedor::getEstoque(){
  return estoque;
}

int Fornecedor:: repassarProdutos(int quantidade, int codigo){
  int index = codigo-1;
  if(estoque.get(index) >= quantidade){
    int novoEstoque = estoque.get(index) - quantidade;
    estoque.push(novoEstoque, index);
    return 0;
  }
  return 1;
}