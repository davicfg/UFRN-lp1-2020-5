#if !defined(ITEM_H)
#define ITEM_H

class Item
{
private:
  int codigo;
  int quantidade;
public:
  Item(int codigo, int quantidade);
  void removerUnidade();
  void adicionarUnidade();
  int getCodigo();
  int getQuatidade();
};

#endif // ITEM_H
