#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Pessoa {
private:
  string _nome;
  int _idade;
  vector<Pessoa *> _filhos;

public:
  Pessoa(string nome, int idade) {
    this->_nome = nome;
    this->_idade = idade;
  }
  ~Pessoa() {
    for (int i = 0; i < this->_filhos.size(); i++) {
      delete this->_filhos[i];
    }

    this->_filhos.clear();
  }

  void PushFilho(Pessoa *filho) { this->_filhos.push_back(filho); }
  vector<Pessoa *> *GetFilhos() { return &this->_filhos; }

  string GetNome() { return this->_nome; }
  int GetIdade() { return this->_idade; }
};

int main() {
  Pessoa *pai = new Pessoa("Pai", 42);

  pai->PushFilho(new Pessoa("Filho1", 12));
  pai->PushFilho(new Pessoa("Filho2", 22));
  pai->PushFilho(new Pessoa("Filho3", 10));
  pai->PushFilho(new Pessoa("Filho4", 5));

  vector<Pessoa *> *filhos = pai->GetFilhos();

  for (int i = 0; i < filhos->size(); i++) {
    Pessoa *filho = (*filhos)[i];

    std::cout << "Nome: " << filho->GetNome()
              << "\nIdade: " << filho->GetIdade() << endl
              << endl;
  }

  delete pai;

  return 0;
}