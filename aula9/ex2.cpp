#include <iostream>

class InstrumentoMusical {
public:
  virtual void Tocar() = 0; // método virtual puro
};

class Violino : public InstrumentoMusical {
  void Tocar() override { std::cout << "Tocando o violino!\n"; }
};

class Piano : public InstrumentoMusical {
  void Tocar() override { std::cout << "Tocando o piano!\n"; }
};

int main() {
  Violino *violino = new Violino();
  Piano *piano = new Piano();

  InstrumentoMusical *instrumentos[2]{violino, piano};

  instrumentos[0]->Tocar();
  instrumentos[1]->Tocar();

  return 0;
}