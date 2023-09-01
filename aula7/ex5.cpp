#include <iostream>

using namespace std;

class Calculadora {
public:
  static float Potenciacao(int base, int expoente) {
    if (expoente == 0)
      return 1;

    return base * Potenciacao(base, expoente - 1);
  }
};

int main() { std::cout << "2^3 = " << Calculadora::Potenciacao(2, 3); }