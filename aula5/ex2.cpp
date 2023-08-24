// Exercício 1
#include <iostream>
#include <regex>

using namespace std;

class VetorDinamico {
private:
  int _tamanho = 0;
  int *_elementos;

public:
  VetorDinamico(int tamanho) { this->_elementos = new int[tamanho]; }
  ~VetorDinamico() { delete this->_elementos; }

  void push(int elemento) {
    this->_elementos[_tamanho] = elemento;
    _tamanho++;
  }

  void imprimir() {
    std::cout << "Imprimindo: ";

    for (int i = 0; i < _tamanho; i++) {
      std::cout << _elementos[i] << " ";
    }

    std::cout << "\n";
  }
};

// Exercício 2
class Matriz {
private:
  int **_elementos;

  int _linhas;
  int _colunas;

public:
  Matriz(int linhas, int colunas) {
    this->_linhas = linhas;
    this->_colunas = colunas;

    this->_elementos = new int *[linhas];

    for (int linha = 0; linha < linhas; linha++) {
      this->_elementos[linha] = new int[linhas];
    }
  }

  ~Matriz() {
    for (int linha = 0; linha < this->_linhas; linha++) {
      delete[] this->_elementos[linha];
    }
  }

  void imprimir() {
    for (int linha = 0; linha < this->_linhas; linha++) {
      for (int coluna = 0; coluna < this->_colunas; coluna++) {
        std::cout << this->_elementos[linha][coluna] << " ";
      }

      std::cout << "\n";
    }
  }
};

// Exercício 3
class Aluno {
private:
  string _nome;
  string *_obs;
  string _matricula;
  int _idade;

public:
  Aluno(int tamanhoObs) { this->_obs = new string[tamanhoObs]; }

  ~Aluno() { delete[] this->_obs; }

  string getNome() { return this->_nome; }
  void setNome(string novoNome) { this->_nome = novoNome; }

  string *getObs() { return this->_obs; }
  void pushObs(string novaObs, int index) { this->_obs[index] = novaObs; }

  int getIdade() { return this->_idade; }
  void setIdade(int novaIdade) { this->_idade = novaIdade; }

  string getMatricula() { return this->_matricula; }
  void setMatricula(string novaMatricula) {
    std::regex _regex = regex("^[A-Za-z]{2}-\\d{4}-\\d{2}$");

    if (!regex_match(novaMatricula, _regex)) {
      std::cout << "Matricula invalida!";
      return;
    }

    this->_matricula = novaMatricula;
  }
};

int main() {
  VetorDinamico *vetor = new VetorDinamico(3);
  Matriz *matriz = new Matriz(5, 5);
  Aluno *aluno = new Aluno(2);

  vetor->push(2);
  vetor->push(3);
  vetor->imprimir();

  aluno->setNome("KowalskiJr");
  aluno->setIdade(19);
  aluno->setMatricula("JJ-3186-24");

  std::cout << "\n"
            << aluno->getNome() << " | " << aluno->getIdade() << " | "
            << aluno->getMatricula() << "\n";

  aluno->setMatricula("234,23-1");

  delete matriz;
  delete vetor;
  delete aluno;

  return 0;
}