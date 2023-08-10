#include <iostream>
#include <iterator>
#include <string>

using namespace std;

// Desafio

int main() {
  string frase;

  std::cout << "Digite uma frase: ";
  getline(std::cin, frase);

  for (int i = 0; i <= size(frase); i++) {
    std::cout << frase[i] << "\n";
  }
}