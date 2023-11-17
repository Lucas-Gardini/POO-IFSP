#include <iostream>
using namespace std;

class Ponto2D {
private:
  double X, Y;

public:
  Ponto2D() {}
  Ponto2D(double x, double y) : X(x), Y(y) {}

  Ponto2D operator+(const Ponto2D &outro) {
    return Ponto2D(X + outro.X, Y + outro.Y);
  }

  Ponto2D operator-(const Ponto2D &outro) {
    return Ponto2D(X - outro.X, Y - outro.Y);
  }

  bool operator==(const Ponto2D &outro) {
    return (X == outro.X) && (Y == outro.Y);
  }

  bool operator!=(const Ponto2D &outro) { return !(*this == outro); }

  Ponto2D &operator=(const Ponto2D &outro) {
    X = outro.X;
    Y = outro.Y;
    return *this;
  }

  Ponto2D &operator++() {
    X += 1;
    Y += 1;
    return *this;
  }

  Ponto2D operator++(int) {
    Ponto2D temp = *this;
    X += 1;
    Y += 1;
    return temp;
  }

  void ExibirCoordenadas() {
    cout << "Coordenadas: (" << X << ", " << Y << ")" << endl;
  }
};

int main() {
  Ponto2D pontoA(7.0, 3.0);
  Ponto2D pontoC = pontoA++;

  pontoC.ExibirCoordenadas();
  pontoA.ExibirCoordenadas();

  return 0;
}