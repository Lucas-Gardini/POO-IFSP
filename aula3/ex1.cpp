#include <iostream>

#define SIZE 10

int main() {
  int valores[SIZE] = {0};

  // Exercício 1
  for (int i = 0; i < SIZE; i++) {
    std::cout << "Insira o " << i + 1 << " valor: ";
    std::cin >> valores[i];

    std::cout << "\033[2J\033[1;1H";
  }

  for (int i = 0; i < SIZE; i++) {
    std::cout << "Valor " << i << ": " << valores[i] << std::endl;
  }

  // Exercício 2
  int soma = 0;

  for (int i = 0; i < SIZE; i++) {
    soma += valores[i];
  }

  std::cout << "\nA soma de todos os elementos resulta em: " << soma;

  // Exercício 3
  int maior = valores[0], menor = valores[0];

  for (int i = 0; i < SIZE; i++) {
    if (valores[i] > maior)
      maior = valores[i];

    if (valores[i] < menor)
      menor = valores[i];
  }

  std::cout << "\nO maior elemento do vetor: " << maior << std::endl;
  std::cout << "O menor elemento do vetor: " << menor;

  // Exercício 4
  int inteiros[SIZE] = {1, 4, 7, 9, 2, 3, 5, 6, 7, 10};
  float med = 0;
  int qtd = 0;

  for (int i = 0; i < SIZE; i++) {
    if (inteiros[i] % 2 != 0) {
      med += inteiros[i];
      qtd++;
    }
  }

  if (qtd == 0) {
    std::cout << "\nNao existem valores impares no vetor!";
    return 0;
  }

  med = med / qtd;

  std::cout << "\nA media dos valores impares resulta em: " << med;

  return 0;
}