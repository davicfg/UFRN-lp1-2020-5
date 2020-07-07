#include "Conta.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
  Conta c1("12345", "Seu Joao", 0.0), c2("54321", "Seu Jorge", 50320.12);

	c1.depositar(50.0);
	c2.sacar(20.12);

	std::cout << c1.saldo << " | " << c2.saldo << "\n";

	c1.transferir(50.0, c2);

	std::cout << c1.saldo << " | " << c2.saldo << "\n";

	return 0;
}
