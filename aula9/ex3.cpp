#include <iostream>
#include <string>

using namespace std;

class Funcionario {
protected:
  int _id;
  string _nome;
  float _salario;

  virtual float CalcularSalario() { return this->_salario; }

public:
  Funcionario(int id, string nome, float salario)
      : _id(id), _nome(nome), _salario(salario) {}
};

class Gerente : Funcionario {
private:
  float _bonusGerente = 15;

public:
  Gerente(int id, string nome, float salario)
      : Funcionario(id, nome, salario) {}

  float CalcularSalario() override {
    return this->_salario + (this->_salario * (this->_bonusGerente / 100));
  }
};

class Programador : Funcionario {
private:
  float _bonusProgramador = 5;

public:
  Programador(int id, string nome, float salario)
      : Funcionario(id, nome, salario) {}

  float CalcularSalario() override {
    return this->_salario + (this->_salario * (this->_bonusProgramador / 100));
  }
};

int main() {
  Gerente *gerente = new Gerente(1, "Gaules", 2500);
  Programador *programador = new Programador(2, "Kovinski", 2500);

  std::cout << "Salario do gerente: " << gerente->CalcularSalario() << "\n";
  std::cout << "Salario do programador: " << programador->CalcularSalario()
            << "\n";

  return 0;
}