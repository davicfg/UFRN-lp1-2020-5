#include "App.hpp"
#include "Estabelecimento.hpp"

#include <iostream>
#include <string>

App::App()
{
  Estabelecimento e(0);
  this->estabelecimento = e;
}

void App::run(){
  int option = -1;

  do
  {
    std::cout << std::endl << "Bem vindo ao mercado itp" << std::endl;
    std::cout << std::endl;
    std::cout << "Selecione uma opção:" << std::endl;
    std::cout << "1) Adicionar saldo" << std::endl;
    std::cout << "2) listar produtos" << std::endl;
    std::cout << "3) Ver minha sacola" << std::endl;
    std::cout << "4) Finalizar compra" << std::endl;
    std::cout << "0) Finalizar compra" << std::endl;
    
    std::cin >> option;

    switch (option)
    {
    case 1:
      std::cout << "Adicionar saldo" << std::endl;
      break;
    case 2:
      std::cout << " listar produtos" << std::endl;
      break;
    case 3:
      std::cout << "Ver minha sacola" << std::endl;
      break;
    case 4:
      std::cout << "Finalizar compra" << std::endl;
      break;
    case 0:
      std::cout << "Até a próxima compra. xD" << std::endl;
      break;
    default:
     std::cout << std::endl << "##### Opção inválida #####" << std::endl;
     break;
    }
  } while(option != 0);
}

void App::setEstabelecimento(const Estabelecimento estabelecimento){
  this->estabelecimento = estabelecimento;
}

Estabelecimento App::getEstabelecimento(){
  return this->estabelecimento;
}