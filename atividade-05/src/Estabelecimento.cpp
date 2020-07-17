#include "Estabelecimento.hpp"
#include "Produto.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>

Estabelecimento::Estabelecimento()
{
  Cliente c(30.0);
  this->cliente = c;
  nomeArquivoEstoque = "estoque.csv";
  carregarEstoque();
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

int Estabelecimento::carregarEstoque()
{
  std::ifstream file;

  file.open(nomeArquivoEstoque);

  if (!file.is_open())
  {
    return 0;
  }

  std::string file_line;

  int codigo;
  std::string nome;
  std::string unidadeMedida;
  float preco;
  int quantidade;

  std::getline(file, file_line);
  while (!file.eof())
  {
    if (file_line.size() == 0)
    {
      continue;
    }

    std::getline(file, file_line);
    replace(file_line.begin(), file_line.end(), ',', ' ');
    file_line.erase(std::remove(file_line.begin(), file_line.end(), '"'), file_line.end());
    file_line.erase(std::remove(file_line.begin(), file_line.end(), '$'), file_line.end());

    std::stringstream stream(file_line);
    char discard;

    stream >> codigo;
    stream >> nome;
    stream >> unidadeMedida;
    stream >> discard;
    stream >> preco;
    stream >> quantidade;

    Produto p(codigo, nome, unidadeMedida, preco);

    estoque[codigo] = quantidade;
    produtos.push_back(p);
  }

  file.close();
  return 0;
}

std::vector<Produto> &Estabelecimento::getProdutos()
{
  return produtos;
}

std::unordered_map<int, int> &Estabelecimento::getEstoque()
{
  return estoque;
}

int Estabelecimento::getEstoqueDisponivelProduto(int codigo)
{
  std::unordered_map<int, int>::const_iterator got = estoque.find(codigo);
  if (got != estoque.end())
  {
    return got->second;
  }
  return -1;
}

std::unordered_map<int, int> Estabelecimento::verSacolaCliente()
{
  return cliente.getSacola();
}

void Estabelecimento::adicionarProdutoCaixa(int codigoProduto)
{
  if (getEstoqueDisponivelProduto(codigoProduto) != -1)
  {
    vendas[codigoProduto] += 1;
  }
}

void Estabelecimento::saidaProdutoEstoque(int codigoProduto)
{
  if (getEstoqueDisponivelProduto(codigoProduto) != -1)
  {
    estoque[codigoProduto] -= 1;
  }
}

std::unordered_map<int, int> Estabelecimento::caixa()
{
  return vendas;
}

void Estabelecimento::registrarCliente()
{
  cliente.registrarCompra(produtos);
}

void Estabelecimento::registrarEstoque()
{
  std::ofstream output(nomeArquivoEstoque);
  output << cabecalhoEstoque << std::endl;
  output.close();

  std::ofstream estoqueEstream(nomeArquivoEstoque, std::ios::app);

  for (size_t i = 0; i < produtos.size(); i++)
  {
    estoqueEstream << produtos[i].getCodigo() << ",";
    estoqueEstream << produtos[i].getNome() << ",";
    estoqueEstream << produtos[i].getUnidadeMedida() << ",";
    estoqueEstream << "\"R$ " << produtos[i].getPrecoUnidade() << "\"" << ",";

    int qtd = getEstoqueDisponivelProduto(produtos[i].getCodigo());
    if(qtd != -1){
      estoqueEstream << qtd << std::endl;
    }
  }

  estoqueEstream.close();
}

void Estabelecimento::registrarVendas()
{
  std::ofstream output("caixa.csv");

  float totalVendido = 0;
  for (auto item : vendas)
  {
    // arquivo caixa.csv deve conter o código do produto, nome, preço,
    //a quantidade vendida de cada produto e o total de vendas
    std::ofstream venda("caixa.csv", std::ios::app);
    venda << item.first << ",";
    venda << produtos[item.first - 1].getNome() << ",";
    venda << produtos[item.first - 1].getPrecoUnidade() << ",";
    venda << item.second << std::endl;

    totalVendido += item.second * produtos[item.first - 1].getPrecoUnidade();
  }
  std::ofstream venda("caixa.csv", std::ios::app);
  venda << "total, " << totalVendido;
}

void Estabelecimento::reabasterEstoque(int quantidade, int codigo){
  estoque[codigo]+=quantidade;
}