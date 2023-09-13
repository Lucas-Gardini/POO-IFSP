#include <iostream>
#include <string>

using namespace std;

class Endereco {
private:
  string _cidade;
  string _rua;
  string _CEP;

public:
  Endereco() {}
  Endereco(string cidade, string rua, string CEP) {
    this->_cidade = cidade;
    this->_rua = rua;
    this->_CEP = CEP;
  }

  string GetCidade() { return this->_cidade; }
  string GetRua() { return this->_rua; }
  string GetCEP() { return this->_CEP; }
};

class Pessoa {
private:
  string _nome;
  Endereco _endereco;

public:
  Pessoa(string nome) { this->_nome = nome; }
  Pessoa(string nome, Pessoa &pessoa) { this->_endereco = pessoa._endereco; }

  string GetNome() { return this->_nome; }

  void SetEndereco(Endereco endereco) { this->_endereco = endereco; }
  Endereco GetEndereco() { return this->_endereco; }
};

int main() {
  Endereco endereco("Catanduva", "Av. Pastor Jose Dutra de Moraes",
                    "15808-305");

  Pessoa *pessoa1 = new Pessoa("Lucas");
  pessoa1->SetEndereco(endereco);

  Pessoa *pessoa2 = new Pessoa("Gustavo", *pessoa1);

  std::cout << "Pessoa: " << pessoa1->GetNome() << endl;

  std::cout << "Cidade: " << pessoa1->GetEndereco().GetCidade() << endl;
  std::cout << "Rua: " << pessoa1->GetEndereco().GetRua() << endl;
  std::cout << "Cep: " << pessoa1->GetEndereco().GetCEP() << endl << endl;

  std::cout << "Pessoa: " << pessoa2->GetNome() << endl;
  std::cout << "Cidade: " << pessoa2->GetEndereco().GetCidade() << endl;
  std::cout << "Rua: " << pessoa2->GetEndereco().GetRua() << endl;
  std::cout << "Cep: " << pessoa2->GetEndereco().GetCEP() << endl;
}