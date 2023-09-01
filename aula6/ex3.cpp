#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Exercício 3
class Ponto {
private:
  float _coordenadas[2];

public:
  Ponto(float x, float y) {
    this->_coordenadas[0] = x;
    this->_coordenadas[1] = y;
  }

  float *GetCoordenadas() { return this->_coordenadas; }
};

class Retangulo {
private:
  vector<Ponto> _coordenadas;

public:
  Retangulo(vector<Ponto> coordenadas) {
    for (int i = 0; i < coordenadas.size(); i++) {
      this->_coordenadas.push_back(coordenadas[i]);
    }
  }

  vector<Ponto> GetCoordendas() { return this->_coordenadas; }
};

int main() {
  vector<Ponto> coordenadas;

  coordenadas.push_back(*new Ponto(0, 0));
  coordenadas.push_back(*new Ponto(0, 10));
  coordenadas.push_back(*new Ponto(5, 0));
  coordenadas.push_back(*new Ponto(5, 10));

  Retangulo *retangulo = new Retangulo(coordenadas);

  vector<Ponto> coordenadasRetangulo = retangulo->GetCoordendas();

  std::cout << "( ";
  for (int i = 0; i < coordenadasRetangulo.size(); i++) {
    std::cout << "(" << coordenadasRetangulo[i].GetCoordenadas()[0] << ", "
              << coordenadasRetangulo[i].GetCoordenadas()[1] << "), ";
  }
  std::cout << ")";

  return 0;
}