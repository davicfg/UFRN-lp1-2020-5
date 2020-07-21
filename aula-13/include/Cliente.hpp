#if !defined(CLIENTE_H)
#define CLIENTE_H

class Cliente
{
private:
  int cep;
public:
  Cliente(int cep);
  int getCep();
  void setCep(int novoCep);
};

#endif // CLIENTE_H
