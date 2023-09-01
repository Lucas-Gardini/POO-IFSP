#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Exercício 4
class No {
private:
  int _valor;
  No *_proximo;

public:
  No(int valor) {
    this->_valor = valor;
    this->_proximo = nullptr;
  }
  ~No() { delete this->_proximo; }

  No *GetProx() { return this->_proximo; }
  void SetProx(No *proximo) { this->_proximo = proximo; }

  int GetValor() { return this->_valor; }
};

class Lista {
private:
  No *_primeiro;

public:
  Lista() { this->_primeiro = nullptr; }
  ~Lista() {
    std::cout << "Liberando memoria da lista!" << endl;

    while (this->_primeiro != nullptr) {
      std::cout << endl << "Obtendo ultimo item" << endl;

      No *atual = this->_primeiro;
      No *anterior = nullptr;

      while (atual->GetProx() != nullptr) {
        if (atual->GetProx()->GetProx() == nullptr)
          anterior = atual;

        atual = atual->GetProx();
      }

      std::cout << "Liberando memoria do no: " << atual->GetValor() << endl;

      delete atual;
      anterior->SetProx(nullptr);
    }
  }

  void pushNo(int valor) {
    if (this->_primeiro == nullptr) {
      this->_primeiro = new No(valor);
      return;
    }

    No *atual = this->_primeiro;

    while (atual->GetProx() != nullptr) {
      atual = atual->GetProx();
    }

    atual->SetProx(new No(valor));
  }

  void printLista() {
    No *atual = this->_primeiro;

    while (atual->GetProx() != nullptr) {
      std::cout << atual->GetValor() << " | ";

      atual = atual->GetProx();
    }
    std::cout << atual->GetValor() << endl;
  }
};

int main() {
  Lista *lista = new Lista();

  for (int i = 1; i <= 10; i++) {
    lista->pushNo(i);
  }

  lista->printLista();

  delete lista;

  return 0;
}