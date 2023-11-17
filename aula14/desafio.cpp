#include <iostream>
#include <string>
using namespace std;

// Classe geral
template <typename Tipo, int largura, int altura> class Matriz {
public:
  Tipo _matriz[altura][largura];
  int _altura = altura, _largura = largura;

  Matriz() {
	
  }

  void somar(Matriz *matrizASomar) {
    if (this->_largura != matrizASomar->_largura || this->_altura != matrizASomar->_altura) {
      cout << "Matrizes de tamanhos diferentes!" << endl;
      return;
    }

    for (int i = 0; i < altura; i++)
      for (int j = 0; j < largura; j++)
        this->_matriz[i][j] += matrizASomar->_matriz[i][j];
  }

  void multiplicar(Tipo escalar) {
    for (int i = 0; i < altura; i++)
      for (int j = 0; j < largura; j++)
        this->_matriz[i][j] *= escalar;
  }

  void multiplicar(Matriz matrizAMultiplicar) {
	if (this->_largura != matrizAMultiplicar->_largura || this->_altura != matrizAMultiplicar->_altura) {
      cout << "Matrizes de tamanhos diferentes!" << endl;
      return;
    }

    for (int i = 0; i < altura; i++)
      for (int j = 0; j < largura; j++)
        this->_matriz[i][j] *= matrizAMultiplicar[i][j];
  }

  void imprimir() {
    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++)
        cout << this->_matriz[i][j] << " ";
      cout << endl;
    }
  }

  void preencher(Tipo valor) {
    for (int i = 0; i < altura; i++)
      for (int j = 0; j < largura; j++)
        this->_matriz[i][j] = valor;
  }
};

int main() {
Matriz<int, 3, 3> matrizA;
  matrizA.preencher(1);
  matrizA.imprimir();

  Matriz<int, 3, 3> matrizB;
  matrizB.preencher(2);
  matrizB.imprimir();

  matrizA.somar(&matrizB);
  matrizA.imprimir();

  matrizA.multiplicar(2);
  matrizA.imprimir();

  return 0;
}