#include <iostream>

int main() {
	// Solicite um numero e multiplique por 2 usando operadores bit a bit
	int num, result;

	std::cout << "Digite o numero a ser multiplicado: ";
	std::cin >> num;

	result = num << 1;

	std::cout << "\nA multiplicacao resultou em: " << result;

	// Verificar se é par ou ímpar com operadores bit a bit
	std::cout << "\n\nDigite o numero a ser verificado: ";
	std::cin >> num;

	if (num & 1) std::cout << num << " -> impar";
	else std::cout << num << " -> par";

	// Estude o código a seguir e explique o que ele faz e como funciona

	int a, b;

	std::cout << "\n\nDigite o valor de a: ";
	std::cin >> a;

	std::cout << "Digite o valor de b: ";
	std::cin >> b;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	std::cout << a << " " << b;
	return 0;
}