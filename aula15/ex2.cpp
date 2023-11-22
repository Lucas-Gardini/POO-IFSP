// Implemente uma função template variádica que retorne o número de
// argumentos passados.

#include <iostream>
#include <string>

template <typename T, typename... Args>
int quantidadeArgumentos(const Args &...args) {
  return sizeof...(args);
}

int main() {
  std::cout << quantidadeArgumentos<int>(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  return 0;
}
