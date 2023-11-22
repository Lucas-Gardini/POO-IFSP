// Implemente uma classe ou função template variádica que concatene várias
// strings passadas como argumentos.

#include <iostream>
#include <string>

// Caso base: apenas uma string, então retorne ela mesma
template <typename T> T concatena(const T &t) { return t; }

// Caso recursivo: concatene a primeira string com o resultado da concatenação
// do restante
template <typename T, typename... Args>
std::string concatena(const T &primeiro, const Args &...args) {
  return primeiro + concatena(args...);
}

int main() {
  std::string s1 = "Ola, ";
  std::string s2 = "mundo";
  std::string s3 = "!";
  std::string resultado = concatena(s1, s2, s3); // resultado é "Olá, mundo!"

  std::cout << resultado << std::endl;
  return 0;
}
