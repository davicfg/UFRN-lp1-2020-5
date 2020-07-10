#include "Estabelecimento.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

Estabelecimento::Estabelecimento()
{
  Cliente c(30.0);
  this->cliente = c;
  nomeArquivoEstoque = "estoque.csv";
}

Estabelecimento::~Estabelecimento()
{
}

Cliente &Estabelecimento::getCliente()
{
  return this->cliente;
}

void Estabelecimento::setCliente(Cliente novoCliente)
{
  this->cliente = novoCliente;
}

// int Estabelecimento::carregarEstoque()
// {
//   std::ifstream file;

//   file.open(nomeArquivoEstoque);

//   if (!file.is_open())
//   {
//     return 0;
//   }

//   std::string file_line;

//   int line_number = 1;

//   std::string current_date = "";
//   while (!file.eof())
//   {
//     ++line_number;
//     std::getline(file, file_line);

//     if (file_line.size() == 0)
//     {
//       continue;
//     }
//     std::cout << file_line << std::endl;
//   }

//   file.close();
//   return 0;
// }
