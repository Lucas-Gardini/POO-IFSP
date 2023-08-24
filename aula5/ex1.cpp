#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// Exercício 1
class Livro {
private:
  string _titulo;
  string _autor;
  int _anoPublicacao;

public:
  Livro(string titulo, string autor, int anoPublicacao) {
    this->_titulo = titulo;
    this->_autor = autor;
    this->_anoPublicacao = anoPublicacao;
  }

  string getTitulo() { return this->_titulo; }
  string getAutor() { return this->_autor; }
  int getAnoPublicacao() { return this->_anoPublicacao; }
};

// Exercício 2
class Carro {
private:
  string _marca;
  string _modelo;
  int _ano;

public:
  Carro(string marca, string modelo, int ano) {
    this->_marca = marca;
    this->_modelo = modelo;
    this->_ano = ano;
  }

  void getDadosCarro() {
    std::cout << "Marca: " << this->_marca << "\n";
    std::cout << "Modelo: " << this->_modelo << "\n";
    std::cout << "Ano: " << this->_ano << "\n\n";
  }
};

// Exercícios 3
class Cubo {
private:
  int _largura;
  int _altura;
  int _comprimento;

public:
  Cubo(int largura, int altura, int comprimento) {
    this->_largura = largura;
    this->_altura = altura;
    this->_comprimento = comprimento;
  }

  int getLargura() { return this->_largura; }
  int getAltura() { return this->_altura; }
  int getComprimento() { return this->_comprimento; }

  int calculaVolume() {
    return this->_altura * this->_largura * this->_comprimento;
  }
};

// Exercícios 4
class JogoDeAdivinhacao {
private:
  int _adivinha;

public:
  JogoDeAdivinhacao() {
    srand(time(0));

    this->_adivinha = (rand() % 100) + 1;

    std::cout << "Bem vindo ao jogo de adivinhacao!\n"
              << "O numero gerado esta entre 1-100 (inclusive)\n";
  }

  int getAdivinha() { return this->_adivinha; }

  bool adivinhar(int teste) {
    system("cls");

    if (teste == this->_adivinha)
      return true;
    else if (teste < this->_adivinha) {
      std::cout << "Maior!"
                << "\n";
    } else {
      std::cout << "Menor!"
                << "\n";
    }

    return false;
  }
};

int main() {
  Carro *carro = new Carro("Volkswagen", "Crossfox", 2007);
  carro->getDadosCarro();

  JogoDeAdivinhacao *jogo = new JogoDeAdivinhacao();

  bool ganhou = false;
  int teste = 0;
  while (!ganhou) {
    std::cout << "Digite um numero (-1 para sair): ";
    std::cin >> teste;

    if (teste == -1)
      break;

    ganhou = jogo->adivinhar(teste);
  }

  if (ganhou)
    std::cout << "Parabens! O numero era: " << jogo->getAdivinha();
  else
    std::cout << "Que pena, o numero era: " << jogo->getAdivinha();

  return 0;
}