#include <iostream>

int dadoDonabela = 0;

void count() {
	dadoDonabela++;
}

void modifier() {
	int dadoDonabela;

	dadoDonabela = 2;

	std::cout << "Variavel local: " << dadoDonabela << "\n";
}

int main() {
	// Exercício 1
	for (int i = 0; i < 199; i++) {
		count();
	}

	std::cout << "A funcao rodo: " << dadoDonabela << " vezes" << "\n";

	std::cout << "Variavel global: " << dadoDonabela << "\n";

	modifier();

	std::cout << "Variavel global: " << dadoDonabela << "\n";

	return 0;
}