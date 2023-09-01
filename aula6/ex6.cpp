#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Data {
private:
  string data;

public:
  Data(string dia, string mes, string ano) {
    this->data = dia + "/" + mes + "/" + ano;
  }

  Data(string data) {
    regex ISO = regex("^[0-9]{4}/[0-9]{2}/[0-9]{2}$");
    regex NORMAL = regex("^[0-9]{2}/[0-9]{2}/[0-9]{4}$");

    if (regex_match(data, ISO) || regex_match(data, NORMAL)) {
      this->data = data;

      return;
    }

    std::cout << "Formato de data invalido!" << endl;
  }

  string GetData() { return this->data; }
};

int main() {
  Data *data1 = new Data("30", "8", "2023");
  Data *data2 = new Data("30/08/2023");
  Data *data3 = new Data("2023/08/30");

  std::cout << data1->GetData() << endl;
  std::cout << data2->GetData() << endl;
  std::cout << data3->GetData() << endl;

  return 0;
}