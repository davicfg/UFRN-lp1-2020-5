#if !defined(CLIENTE_H)
#define CLIENTE_H

class Cliente
{
private:
  float saldo;

public:
  static int idCliente;
  Cliente();
  Cliente(const float depositoInicial);

  void adicionarSaldo(const float deposito);
  float getSaldo();
};

#endif // CLIENTE_H