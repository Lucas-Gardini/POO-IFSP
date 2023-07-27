#include <math.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    // EX1
    string nome;

    cout << "Digite seu nome: ";
    getline(cin, nome);

    cout << "Ola, " << nome << "! Seja bem-vindo(a)!\n\n";

    // EX2
    float celcius, fahrenheit;

    cout << "Digite a temperatura em Celsius: ";
    cin >> celcius;

    fahrenheit = (celcius * 9 / 5) + 32;
    cout << celcius << " graus Celsius equivalem a " << fahrenheit
         << " graus Fahrenheit\n\n";

    // EX3
    float num1, num2, num3, med;

    cout << "Digite o primeiro numero: ";
    cin >> num1;

    cout << "Digite o segundo numero: ";
    cin >> num2;

    cout << "Digite o terceiro numero: ";
    cin >> num3;

    med = (num1 + num2 + num3) / 3;
    cout << "A media dos numeros e: " << med << "\n\n";

    // EX4
    float base, alt, area;

    cout << "Digite a base do triangulo: ";
    cin >> base;

    cout << "Digite a altura do triangulo: ";
    cin >> alt;

    area = base * alt / 2;

    cout << "A area do triangulo e: " << area << "\n\n";

    // EX5
    float a, r, n, soma;

    cout << "Digite o primeiro termo (a): ";
    cin >> a;

    cout << "Digite a razao (r): ";
    cin >> r;

    cout << "Digite o numero de termos (n): ";
    cin >> n;

    soma = (n / 2) * (2 * a + (n - 1) * r);

    cout << "A soma dos " << n << " termos da P.A, e: " << soma;

    return 0;
}