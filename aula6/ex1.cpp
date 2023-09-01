#include <iostream>
#include <vector>

using namespace std;

// Exercício 1
class Disciplina {
private:
  string _nome;
  float _nota;

public:
  Disciplina(string nome, float nota) {
    this->_nome = nome;
    this->_nota = nota;
  }

  string GetNome() { return this->_nome; }
  void SetNome(string novoNome) { this->_nome = novoNome; }

  float GetNota() { return this->_nota; }
  void SetNota(int novaNota) { this->_nota = novaNota; }
};

class Aluno {
private:
  string _nome;
  int _idade;
  vector<Disciplina> _disciplinas;

public:
  Aluno(string nome, int idade) {
    this->_nome = nome;
    this->_idade = idade;
  }
  ~Aluno() { this->_disciplinas.clear(); }

  string GetNome() { return this->_nome; }
  void SetNome(string novoNome) { this->_nome = novoNome; }

  int GetIdade() { return this->_idade; }
  void SetIdade(int novaIdade) { this->_idade = novaIdade; }

  vector<Disciplina> GetDisciplinas() { return this->_disciplinas; }
  void PushDisciplina(Disciplina *disciplina) {
    this->_disciplinas.push_back(*disciplina);
  }

  void GetMedia() {
    float total = 0;
    for (int i = 0; i < this->_disciplinas.size(); i++) {
      std::cout << "Disciplina: " << this->_disciplinas[i].GetNome()
                << "\nNota: " << this->_disciplinas[i].GetNota() << "\n\n";

      total += this->_disciplinas[i].GetNota();
    }

    std::cout << "A media do aluno eh de: " << total;
  }
};

int main() {
  Aluno *aluno = new Aluno("Lucas", 12);

  aluno->PushDisciplina(new Disciplina("Portugues", 5));
  aluno->PushDisciplina(new Disciplina("Matematica", 8.5));
  aluno->PushDisciplina(new Disciplina("Historia", 9.2));
  aluno->PushDisciplina(new Disciplina("Geografia", 2.4));

  aluno->GetMedia();

  return 0;
}