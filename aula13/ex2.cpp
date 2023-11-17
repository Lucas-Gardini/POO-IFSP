#include <iostream>
using namespace std;

class minhaData {
private:
  int ano, mes, dia;

public:
  minhaData() {}
  minhaData(int ano, int mes, int dia) {
    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
  }

  operator int() { return ((ano * 10000) + (mes * 100) + dia); }

  minhaData operator+(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    int timestampSoma = timestamp + timestampOutra;

    int ano = timestampSoma / 10000;
    int mes = (timestampSoma % 10000) / 100;
    int dia = (timestampSoma % 10000) % 100;

    return minhaData(ano, mes, dia);
  }

  minhaData operator-(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    int timestampSub = timestamp - timestampOutra;

    int ano = timestampSub / 10000;
    int mes = (timestampSub % 10000) / 100;
    int dia = (timestampSub % 10000) % 100;

    return minhaData(ano, mes, dia);
  }

  bool operator==(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    return timestamp == timestampOutra;
  }

  bool operator!=(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    return timestamp != timestampOutra;
  }

  minhaData operator++() {
    int timestamp = *this;
    int ano = timestamp / 10000;
    int mes = (timestamp % 10000) / 100;
    int dia = (timestamp % 10000) % 100;

    if (dia == 30) {
      dia = 1;
      if (mes == 12) {
        mes = 1;
        ano++;
      } else {
        mes++;
      }
    } else {
      dia++;
    }

    return minhaData(ano, mes, dia);
  }

  minhaData operator++(int) {
    minhaData temp = *this;
    int timestamp = *this;
    int ano = timestamp / 10000;
    int mes = (timestamp % 10000) / 100;
    int dia = (timestamp % 10000) % 100;

    if (dia == 30) {
      dia = 1;
      if (mes == 12) {
        mes = 1;
        ano++;
      } else {
        mes++;
      }
    } else {
      dia++;
    }

    return temp;
  }

  minhaData operator--() {
    int timestamp = *this;
    int ano = timestamp / 10000;
    int mes = (timestamp % 10000) / 100;
    int dia = (timestamp % 10000) % 100;

    if (dia == 1) {
      dia = 30;
      if (mes == 1) {
        mes = 12;
        ano--;
      } else {
        mes--;
      }
    } else {
      dia--;
    }

    return minhaData(ano, mes, dia);
  }

  minhaData operator--(int) {
    minhaData temp = *this;
    int timestamp = *this;
    int ano = timestamp / 10000;
    int mes = (timestamp % 10000) / 100;
    int dia = (timestamp % 10000) % 100;

    if (dia == 1) {
      dia = 30;
      if (mes == 1) {
        mes = 12;
        ano--;
      } else {
        mes--;
      }
    } else {
      dia--;
    }

    return temp;
  }

  bool operator<(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    return timestamp < timestampOutra;
  }

  bool operator>(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    return timestamp > timestampOutra;
  }

  bool operator<=(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    return timestamp <= timestampOutra;
  }

  bool operator>=(minhaData &outra) {
    int timestamp = *this;
    int timestampOutra = outra;

    return timestamp >= timestampOutra;
  }
};

int main() {
  minhaData objdata(2023, 11, 30);
  int dataInt =
      objdata; // O cast não é necessário, já estamos retornando um int.
  cout << dataInt << endl; // 20231130
  return 0;
}