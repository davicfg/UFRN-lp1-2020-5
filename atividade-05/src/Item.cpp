#include "Item.hpp"

Item::Item(int codigo, int quantidade)
{
}

void Item::removerUnidade()
{
  if(this->quantidade >0){
    this->quantidade--;
  }
  

}
void Item::adicionarUnidade()
{
  this->quantidade++;
}

int Item::getCodigo(){
  return this->codigo;
}

int Item::getQuatidade(){
  return this->quantidade;
}