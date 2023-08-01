#include <iostream>

int main() {
	// 	Calcular o fatorial de um número inteiro não negativo

	int num, fat;

	std::cout << "Digite o numero a ser calculado seu fatorial: ";
	std::cin >> num;

	if (num <= 0) {
		std::cout << "Digite um valor inteiro não negativo!";
	}

	fat = num;

	for (int i = 1; i < num; i++) {
		fat = fat * i;
	}

	std::cout << "O fatorial de " << num << " e: " << fat;

	// Calcular a sequencia de fibbonaci
	int fib = 0, antecessor = 0, atual = 1;

	std::cout << "\n\nDigite a quantidade da sequencia de fibonnaci: ";
	std::cin >> num;

	std::cout << "Resultado da sequencia: 0 1 ";
	for (int i = 2; i < num; i++) {
		fib = antecessor + atual;
		std::cout << fib << " ";

		antecessor = atual;
		atual = fib;
	}

	// Leia um conjunto de valores inteiros e positivos e determine qual o menor, qual o maior, negativo encerra;

	int val_atual, maior = -1, menor = -1;

	std::cout << "\n\n";

	while(true) {
		std::cout << "Digite o valor a ser adicionado no conjunto (x < 0 para sair): ";
		std::cin >> val_atual;

		if (menor == -1) menor = val_atual;
		if (maior == -1) maior = val_atual;

		if (val_atual < 0) break;

		if (val_atual > maior) maior = val_atual;
		else if (val_atual < menor) menor = val_atual;
	}

	std::cout << "O maior valor e: " << maior;
	std::cout << "\nO menor valor e: " << menor;

	return 0;
}