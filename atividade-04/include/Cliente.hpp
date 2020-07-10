#if !defined(CLIENTE_H)
#define CLIENTE_H

class Cliente
{
private:
  float saldo;
public:
  static int idCliente;
  Cliente();
  Cliente(float depositoInicial);
  void adicionarSaldo(float deposito);
  float getSaldo();
};

#endif // CLIENTE_H