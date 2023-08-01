#include <iostream>

int main() {
	// Desafio: Um programa que escreva um "V" usando declarações for (solicitando de 1 a 9)
	int linhas;

	std::cout << "\n\nDigite a quantidade de linhas: ";
	std::cin >> linhas;

	for (int i = linhas; i > 0; i--) {
		int imprimir = linhas + 1 - i;
		int espacos_esquerda = linhas - i;
		int espacos_direita = espacos_esquerda - 1;

		// Parte da esquerda
		for (int j = 0; j < espacos_esquerda; j++) {
			std::cout << " ";
		}

		std::cout << imprimir;

		for (int j = 0; j < espacos_esquerda; j++) {
			std::cout << " ";
		}

		// Parte da direita
		for (int j = 0; j < espacos_direita; j++) {
			std::cout << " ";
		}

		std::cout << imprimir;
		
		std::cout << "\n";
	}

	return 0;
}