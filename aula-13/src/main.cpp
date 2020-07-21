#include "Fila.hpp"
#include "ClientePF.hpp"
#include "ClientePJ.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
  ClientePJ pj1;
  ClientePJ pj2;
  ClientePJ pj3;
  ClientePJ pj4;

  pj1.setRazaoSocial("pj1");
  pj2.setRazaoSocial("pj2");
  pj3.setRazaoSocial("pj3");
  pj4.setRazaoSocial("pj4");

  Fila<ClientePJ> filaPJ(4);
  filaPJ.push(pj1);
  filaPJ.push(pj2);
  filaPJ.push(pj3);
  filaPJ.push(pj4);


  ClientePF pf1(11);
  ClientePF pf2(11);
  ClientePF pf3(11);
  ClientePF pf4(11);

  pf1.setNome("Blablau1");
  pf2.setNome("Blablau2");
  pf3.setNome("Blablau3");
  pf4.setNome("Blablau4");

  Fila<ClientePF> filaPF(4);
  filaPF.push(pf1);
  filaPF.push(pf2);
  filaPF.push(pf3);
  filaPF.push(pf4);
  
	return 0;
}

