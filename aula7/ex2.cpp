#include <iostream>
#include <vector>

using namespace std;

class Livro {
private:
  string _titulo;
  string _autor;
  int _anoPubli;

public:
  Livro(string titulo, string autor, int ano) {
    this->_titulo = titulo;
    this->_autor = autor;
    this->_anoPubli = ano;
  }

  string GetTitulo() { return this->_titulo; }
  string GetAutor() { return this->_autor; }
  int GetAnoPubli() { return this->_anoPubli; }
};

class Biblioteca {
private:
  vector<Livro *> _livros;

public:
  Biblioteca() {}
  Biblioteca(Biblioteca &obj) { this->_livros = obj._livros; }
  ~Biblioteca() {
    for (int i = 0; i < this->_livros.size(); i++) {
      delete this->_livros[i];
    }

    this->_livros.clear();
  }

  void PushLivro(Livro *livro) { this->_livros.push_back(livro); }

  void MostraLivros() {
    for (int i = 0; i < this->_livros.size(); i++) {
      Livro *livro = this->_livros[i];
      std::cout << "Titulo: " << livro->GetTitulo() << endl;
      std::cout << "Autor: " << livro->GetAutor() << endl;
      std::cout << "Ano Publicacao: " << livro->GetAnoPubli() << endl;

      std::cout << "--------|--------" << endl << endl;
    }
  }
};

int main() {
  Livro *livro1 = new Livro("titulo1", "autor1", 2012);
  Livro *livro2 = new Livro("titulo2", "autor2", 2024);
  Livro *livro3 = new Livro("titulo3", "autor3", 1985);
  Livro *livro4 = new Livro("titulo4", "autor4", 2010);
  Livro *livro5 = new Livro("titulo5", "autor5", 2005);
  Livro *livro6 = new Livro("titulo6", "autor6", 2023);

  Biblioteca *biblioteca1 = new Biblioteca();
  biblioteca1->PushLivro(livro1);
  biblioteca1->PushLivro(livro2);
  biblioteca1->PushLivro(livro3);
  biblioteca1->PushLivro(livro4);

  Biblioteca *biblioteca2 = new Biblioteca(*biblioteca1);
  biblioteca2->PushLivro(livro5);
  biblioteca2->PushLivro(livro6);

  std::cout << "Biblioteca 1\n" << endl;
  biblioteca1->MostraLivros();

  std::cout << "\nBiblioteca 2\n" << endl;
  biblioteca2->MostraLivros();
}