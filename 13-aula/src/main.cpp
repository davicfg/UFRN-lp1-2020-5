#include "Conta.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
  Conta c1("12345", "Junior", 0.0), c2("54321", "Matheus", 50320.12);

  c1.cliente.nome = "Jonesbelson";

	c1.depositar(162.0);
	c2.sacar(25.90);

	std::cout << c1.saldo << " | " << c2.saldo << "\n";

	c1.transferir(50.0, c2);

	std::cout << c1.saldo << " | " << c2.saldo << "\n";

  std::cout << c1.cliente.nome << std::endl;
	return 0;
}
