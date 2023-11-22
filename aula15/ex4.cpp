// Implemente uma classe template variádica que possui
// métodos para retornar o menor e o maior valor entre os argumentos, implemente
// métodos distintos

#include <iostream>
#include <string>

template <typename... tipos> class MaiorMenor {
private:
  int _menor, _maior;

  template <typename T> void _atualizarMaiorMenor(T valor) {
    _menor = static_cast<int>(valor);
    _maior = static_cast<int>(valor);
  }

  template <typename T> void _atualizarMaiorMenor(const T &valor) {
    if (valor < _menor) {
      _menor = valor;
    }

    if (valor > _maior) {
      _maior = valor;
    }
  }

  template <typename T, typename... Args>
  void _atualizarMaiorMenor(T valor, Args... args) {
    if (valor < _menor) {
      _menor = valor;
    }

    if (valor > _maior) {
      _maior = valor;
    }

    _atualizarMaiorMenor(args...);
  }

public:
  MaiorMenor() : _menor(0), _maior(0) {}

  template <typename... Args> void atualizarMaiorMenor(Args... args) {
    _atualizarMaiorMenor(args...);
  }

  int menor() const { return _menor; }

  int maior() const { return _maior; }
};

int main() {
  MaiorMenor<int, double, std::string> mm;
  mm.atualizarMaiorMenor(10, 3.14, 3);

  std::cout << "Menor valor: " << mm.menor() << std::endl;
  std::cout << "Maior valor: " << mm.maior() << std::endl;

  return 0;
}