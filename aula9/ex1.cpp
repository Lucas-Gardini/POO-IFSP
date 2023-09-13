#include <iostream>
#include <string>

using namespace std;

class Veiculo {
protected:
  string _modelo;
  int _ano;
  float _preco;

  virtual void imprimirInfo() {
    std::cout << "Informacoes do veiculo: "
              << "\n"
              << "Modelo: " << this->_modelo << "\nAno: " << this->_ano
              << "\nPreco: " << this->_preco << "\n\n";
  };
};

class Carro : private Veiculo {
public:
  Carro(string modelo, int ano, float preco) {
    this->_modelo = modelo;
    this->_ano = ano;
    this->_preco = preco;
  }

  void imprimirInfo() override {
    std::cout << "Informacoes do carro: "
              << "\n"
              << "Modelo: " << this->_modelo << "\nAno: " << this->_ano
              << "\nPreco: " << this->_preco << "\n\n";
  }
};

class Moto : private Veiculo {
public:
  Moto(string modelo, int ano, float preco) {
    this->_modelo = modelo;
    this->_ano = ano;
    this->_preco = preco;
  }

  void imprimirInfo() override {
    std::cout << "Informacoes da moto: "
              << "\n"
              << "Modelo: " << this->_modelo << "\nAno: " << this->_ano
              << "\nPreco: " << this->_preco << "\n\n";
  }
};

int main() {
  Carro *carro = new Carro("Crossfox", 2006, 29900);
  Moto *moto = new Moto("Biz", 1999, 2500);

  carro->imprimirInfo();
  moto->imprimirInfo();
  return 0;
}