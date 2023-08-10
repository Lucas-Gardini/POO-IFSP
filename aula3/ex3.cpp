#include <iostream>

int main() {
  // Exercício 1
  int size = 0;

  std::cout << "Qual o tamanho do vetor: ";
  std::cin >> size;

  int *vetor = new int[size];

  for (int i = 0; i < size; i++) {
    std::cout << "Digite o valor da " << i + 1 << " posicao: ";
    std::cin >> vetor[i];
  }

  std::cout << "\nVetor: ";
  for (int i = 0; i < size; i++) {
    std::cout << vetor[i] << " ";
  }

  // Exercício 2
  float *notas = new float[0];

  while (true) {
    float nota = 0;

    std::cout << "Digite a nota: ";
    std::cin >> nota;

    if (nota < 0)
      break;
  }

  return 0;
}