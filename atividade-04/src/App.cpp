#include "App.hpp"
#include "Estabelecimento.hpp"

#include <iostream>
#include <string>

App::App()
{
  Estabelecimento e;
  estabelecimento = e;
}

void App::run()
{
  int option = -1;

  do
  {
    std::cout << std::endl
              << "Bem vindo ao mercado itp" << std::endl;
    std::cout << std::endl;
    std::cout << "Selecione uma opção:" << std::endl;
    std::cout << "1) Adicionar saldo" << std::endl;
    std::cout << "2) Listar produtos" << std::endl;
    std::cout << "3) Ver minha sacola" << std::endl;
    std::cout << "4) Adicionar um produto a sacola" << std::endl;
    std::cout << "10) Finalizar compra " << std::endl;
    std::cout << "0) Sair do Programa" << std::endl;

    std::cin >> option;

    switch (option)
    {
    case 1:
      adicionarSaldo();
      break;
    case 2:
      listarProdutos();
      break;
    case 3:
      verSacolaCliente();
      break;
    case 4:
        adicionarProdutoSacola();
      break;
    case 10:
      std::cout << "Finalizar compra" << std::endl;
      break;
    case 0:
      std::cout << "Até a próxima compra. xD" << std::endl;
      break;
    default:
      std::cout << std::endl
                << "##### Opção inválida #####" << std::endl;
      break;
    }
  } while (option != 0);
}

void App::setEstabelecimento(const Estabelecimento novoEstabelecimento)
{
  estabelecimento = novoEstabelecimento;
}

Estabelecimento &App::getEstabelecimento()
{
  return this->estabelecimento;
}

void App::adicionarSaldo()
{
  float deposito;
  std::cout << "Quanto dinheiro vai depositar? ";
  std::cin >> deposito;
  //TODO alterar para ter um método em estabelecimento, app não precisa saber tudo de cliente.
  getEstabelecimento().getCliente().adicionarSaldo(deposito);
  std::cout << "Seu novo saldo: R$" << getEstabelecimento().getCliente().getSaldo() << std::endl;
}

void App::listarProdutos()
{
  std::vector<Produto> produtos = estabelecimento.getProdutos();
  
  int codigoProduto = -1;
  for (size_t i = 0; i < produtos.size(); i++)
  {
    codigoProduto = produtos[i].getCodigo();
    std::cout << "Código: " << codigoProduto << " ";
    std::cout << "Nome: " << produtos[i].getNome() << " ";
    std::cout << "Preço: R$ " << produtos[i].getPrecoUnidade() << " ";
    std::cout << "Unds. disponível: " << estabelecimento.getEstoqueDisponivelProduto(codigoProduto) << std::endl;
  }
}

void App::adicionarProdutoSacola(){
  listarProdutos();
  int codigoProduto;
  std::cout << "Escolhar o seu produto pelo código do produto" << std::endl;
  std::cin >> codigoProduto;

  std::vector<Produto> produtos = estabelecimento.getProdutos();
  if(estabelecimento.getEstoqueDisponivelProduto(codigoProduto) > 0){
    float precoProduto = produtos[codigoProduto-1].getPrecoUnidade();
    int result = estabelecimento.getCliente().adicionarProduto(precoProduto, codigoProduto);

    if(result == 0){
      std::cout << "Produto adicionado a sacola" << std::endl;
    }else{
      std::cout << "Você não tem saldo suficiente para comprar." << std::endl;
    }
    estabelecimento.getEstoque()[codigoProduto]-=1;
  }else{
    std::cout << "Produto fora de estoque" << std::endl;
  }
}

void App::verSacolaCliente(){
  std::unordered_map<int, int> sacolaCliente = estabelecimento.verSacolaCliente();
  std::vector<Produto> listarProdutos = estabelecimento.getProdutos();
  if(sacolaCliente.empty()){
    std::cout << "Sacola vazia" << std::endl;
  }
  for (auto item : sacolaCliente)
  {
    std::cout << "Quantidade: " << item.second << " ";
    std::cout << "Produto:  " << listarProdutos[item.first-1].getNome() << std::endl;
  }
  
  
}