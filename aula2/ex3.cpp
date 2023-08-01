#include <iostream>

int main() {
	// Verificar dentro do intervalo
	int num1, num2, check;

	std::cout << "Digite o inicio do intevalo: ";
	std::cin >> num1;

	std::cout << "Digite o fim do intevalo: ";
	std::cin >> num2;

	std::cout << "Digite o numero a ser veriricado: ";
	std::cin >> check;

	if (check >= num1 && check <= num2) std::cout << "\nEsta dentro do intervalo!";
	else std::cout << "\nNao esta dentro do intervalo!";

	// Verificar numero positivo e não múltiplo de três
	int num3;

	std::cout << "\nDigite o numero a ser verificado: ";
	std::cin >> num3;

	if (num3 > 0 && num3 % 3 != 0) std::cout << "\nE positivo e nao multiplo de 3!";
	else std::cout << "\nNao e positivo ou e multiplo de 3!";

	return 0;
}