// Modifique a classe de soma de argumentos para aceitar um valor inicial e
// retornar a soma dos argumentos mais o valor inicial.

#include <iostream>
#include <string>

template <typename T> T soma(const T &t) { return t; }

// Caso recursivo: concatene a primeira string com o resultado da concatenação
// do restante
template <typename T, typename... Args>
T soma(int vlrInicial, const T &primeiro, const Args &...args) {
  return vlrInicial + (primeiro + soma(0, args...));
}

int main() {
  int resultado = soma(5, 10, 20, 30, 40, 50);

  std::cout << resultado << std::endl;
  return 0;
}
