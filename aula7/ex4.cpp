#include <iostream>

using namespace std;

class Contador {
private:
  static int contadorDeObjetos;

public:
  Contador() { Contador::contadorDeObjetos++; }
  ~Contador() { Contador::contadorDeObjetos--; }

  void static PrintQuantidade() {
    std::cout << "Quantidade: " << Contador::contadorDeObjetos << endl;
  }
};

int Contador::contadorDeObjetos = 0;

int main() {
  Contador c1;
  Contador c2;
  Contador *c3 = new Contador();

  Contador::PrintQuantidade();

  delete c3;

  Contador::PrintQuantidade();
}