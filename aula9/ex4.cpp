#include <cmath>
#include <iostream>

const float pi = 3.14;

class FormaGeometrica {
protected:
  virtual float CalcularArea() = 0;
  virtual float CalcularPerimetro() = 0;
};

class Circulo : public FormaGeometrica {
private:
  float _raio;
  float _diametro;

public:
  Circulo(float raio, float diametro) : _raio(raio), _diametro(diametro) {}

  float CalcularArea() override { return pow((pi * this->_raio), 2); }

  float CalcularPerimetro() override { return 2 * pi * this->_raio; }
};

class Quadrado : public FormaGeometrica {
private:
  float _lado;

public:
  Quadrado(float lado) : _lado(lado) {}

  float CalcularArea() override { return pow(this->_lado, 2); }

  float CalcularPerimetro() override { return this->_lado * 4; }
};

class Triangulo : public FormaGeometrica {
private:
  float _base;
  float _altura;

public:
  Triangulo(float base, float altura) : _base(base), _altura(altura) {}

  float CalcularArea() override { return (this->_base * this->_altura) / 2; }

  float CalcularPerimetro() override { return 1 + 2 + 3; }
};