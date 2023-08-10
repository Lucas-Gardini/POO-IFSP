#include <iostream>

int main() {

  int var = 10;
  int *meuPrimeiroPonteiro = &var;
  std::cout << "Valor de var: " << var << "\n";
  std::cout << "Endereco de memoria de var: " << &var << "\n";
  std::cout << "Valor apontado por meuPrimeiroPonteiro: "
            << *meuPrimeiroPonteiro << "\n";
  std::cout << "Endereco de memoria armazenado em meuPrimeiroPonteiro: "
            << meuPrimeiroPonteiro << "\n";

  *meuPrimeiroPonteiro = 20;
  std::cout << "Novo valor de var: " << var << "\n";

  return 0;
}