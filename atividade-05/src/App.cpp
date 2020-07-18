#include "App.hpp"
#include "Estabelecimento.hpp"
#include "Produto.hpp"
#include "Fornecedor.hpp"
#include "vector_supermercado.hpp"

#include <iostream>
#include <string>

App::App()
{
  Estabelecimento e;
  estabelecimento = e;
  estabelecimento.carregarEstoque();

  Fornecedor f;
  fornecedor = f;
  fornecedor.carregarEstoque();
}

App::~App()
{
  estabelecimento.registrarEstoque();
  estabelecimento.registrarVendas();
  fornecedor.registrarEstoque();
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
    std::cout << "5) Ver Caixa" << std::endl;
    std::cout << "6) Listar Produtos fornecedor" << std::endl;
    std::cout << "7) Repassar produto: Fornecedor --> Estavelecimento" << std::endl;
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
    case 5:
      verCaixa();
      break;
    case 6:
      listarProdutosFornecedor();
      break;
    case 7:
      reabastercerEstabelecimento();
      break;
    case 10:
      finalizarCompra();
      break;
    case 0:
      std::cout << "Até a próxima compra. xD" << std::endl;
      break;
    default:
      std::cout << std::endl
                << "##### Opção inválida #####" << std::endl;
      break;
    }
  } while (option != 0 and option != 10);

  if(option == 10){
    std::string novaCompra;
    std::cout << "Deseja fazer uma nova compra (S/N)?" << std::endl;
    std::cin >> novaCompra;
    if (novaCompra == "S")
    {
      Cliente x(50.0);
      Cliente c(50.0);
      estabelecimento.setCliente(c);
      run();
    }
  }
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

//FIX mover lógica para a classe de esbelecimento
void App::adicionarProdutoSacola()
{
  listarProdutos();
  int codigoProduto;
  std::cout << "Escolhar o seu produto pelo código do produto" << std::endl;
  std::cin >> codigoProduto;

  std::vector<Produto> produtos = estabelecimento.getProdutos();
  if (estabelecimento.getEstoqueDisponivelProduto(codigoProduto) > 0)
  {
    float precoProduto = produtos[codigoProduto - 1].getPrecoUnidade();
    int result = estabelecimento.getCliente().adicionarProduto(precoProduto, codigoProduto);

    if (result == 0)
    {
      std::cout << "Produto adicionado a sacola" << std::endl;
    }
    else
    {
      std::cout << "Você não tem saldo suficiente para comprar." << std::endl;
    }
    estabelecimento.saidaProdutoEstoque(codigoProduto);
    estabelecimento.adicionarProdutoCaixa(codigoProduto);
  }
  else
  {
    std::cout << "Produto fora de estoque" << std::endl;
  }
}

void App::verSacolaCliente()
{
  std::unordered_map<int, int> sacolaCliente = estabelecimento.verSacolaCliente();
  std::vector<Produto> listarProdutos = estabelecimento.getProdutos();
  if (sacolaCliente.empty())
  {
    std::cout << "Sacola vazia" << std::endl;
  }
  for (auto item : sacolaCliente)
  {
    std::cout << "Quantidade: " << item.second << " ";
    std::cout << "Produto:  " << listarProdutos[item.first - 1].getNome() << std::endl;
  }
}

void App::verCaixa()
{
  std::unordered_map<int, int> caixa = estabelecimento.caixa();
  std::vector<Produto> listarProdutos = estabelecimento.getProdutos();
  float totalVendido = 0.0;

  if (caixa.empty())
  {
    std::cout << "Sacola vazia" << std::endl;
  }

  for (auto item : caixa)
  {
    Produto p(listarProdutos[item.first - 1]);

    std::cout << "Quantidade: " << item.second << " ";
    std::cout << "Produto:  " << p.getNome() << std::endl;
    totalVendido += p.getPrecoUnidade() * item.second;
  }
  std::cout << "Total: R$ " << totalVendido << std::endl;
}

void App::finalizarCompra()
{
  estabelecimento.registrarCliente();
  //estabelecimento.registrarCaixa();
}

void App::listarProdutosFornecedor(){
  vector_supermercado<int> estoqueFornecedor = fornecedor.getEstoque();
  std::vector<Produto> produtos = estabelecimento.getProdutos();
  std::cout << "##### Lista de produtos do fornecedor #####" << std::endl;
  for (int i = 0; i < estoqueFornecedor.vectorSize(); i++)
  {
    std::cout << "Codigo: " << produtos[i].getCodigo();
    std::cout << " Nome Produto: " << produtos[i].getNome();
    std::cout << " Quantidade:" << estoqueFornecedor.get(i) << std::endl;
  }
  
}

void App::reabastercerEstabelecimento(){
  int codigoProduto;
  int quantidade;
  
  std::cout << "Qual produto?" << std::endl;
  std::cin >> codigoProduto;

  std::cout << "Qual a qantidade?" << std::endl;
  std::cin >> quantidade;

  if(fornecedor.repassarProdutos(quantidade, codigoProduto) == 0){
    std::cout << "Reabastecimento feito!" << std::endl;
    estabelecimento.reabasterEstoque(quantidade, codigoProduto);

  }
}
