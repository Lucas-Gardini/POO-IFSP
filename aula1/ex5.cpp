#include <iostream>
#include <string>

using namespace std;

int main() {
    string linha;

    cout << "Digite uma linha: ";
    getline(cin, linha);

    cout << "A linha digitada foi: " << linha << endl;
    return 0;
}