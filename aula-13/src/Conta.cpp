#include "Conta.hpp"
#include <iostream>
Conta::Conta(const std::string & _numero, const std::string & _titular, const double _saldo): numero(_numero), titular(_titular), saldo(_saldo) {}

void Conta::sacar(const double & _valor) {
	saldo -= _valor;
}

void Conta::depositar(const double & _valor) {
	saldo += _valor;
}

void Conta::transferir(const double & _valor, Conta & _conta) {
	_conta.depositar(_valor);
	sacar(_valor);
}