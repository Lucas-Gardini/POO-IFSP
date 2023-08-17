#include <iostream>

// principais
int soma(int num1, int num2) {
	return num1 + num2;
}

int fatorial(int num) {
	int total = num;
	for (int i = 1; i < num; i++) {
		total = total * (num - i);
	}
	
	return total;
}

void fatorialRef(int *num) {
	int &rTotal = *num;

	for (int i = 1; i < *num; i++) {
		rTotal = rTotal * (*num - i);
	}
	
}

int menorValor(int vetor[], int tamanho) {
	int menor = vetor[0];

	for (int i = 1; i < tamanho; i++) {
		if (vetor[i] < menor) menor = vetor[i];
	}

	return menor;
}

void elevar(int *valor, int potencia);
void elevarTodoOVetor(int vetor[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		elevar(&vetor[i], 2);
	}
}

void duplicar(int *valor);
void duplicarElementosMatriz(int matriz[4][4]) {
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++)
			duplicar(&matriz[i][j]);
	
}

void fatorialVetorCompleto(int vetor[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		fatorialRef(&vetor[i]);
	}
}

// utilitários
void elevar(int *valor, int potencia) {
	for (int i = 1; i < potencia; i++) {
		*valor = *valor * *valor;
	}
}

void duplicar(int *valor) {
	*valor = *valor * 2;
}

int main() {
	int valor1 = 5, valor2 = 92;
	int valores[10] = {99, 5, 8, 10, 54, 26, 12, 7, 3 ,9};
	int tamanhoVetor = sizeof(valores) / sizeof(int);
	int matriz[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	// EX1 
	std::cout << "SOMA: " << soma(valor1, valor2) << "\n";

	// EX2
	std::cout << "FATORIAL (" << valor1 << "): " << fatorial(valor1) << "\n";
	
	// EX3
	std::cout << "MENOR VALOR: " << menorValor(valores, tamanhoVetor) << "\n";
	
	// EX4
	std::cout << "VETOR INICIAL: ";
	for (int i = 0; i < tamanhoVetor; i++) {
		std::cout << valores[i] << " ";
	}
	std::cout << "\n";

	elevarTodoOVetor(valores, tamanhoVetor);

	std::cout << "VETOR FINAL: ";
	for (int i = 0; i < tamanhoVetor; i++) {
		std::cout << valores[i] << " ";
	}
	std::cout << "\n\n";

	// EX5
	std::cout << "MATRIZ INICIAL: \n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) std::cout << matriz[i][j] << " ";

		std::cout << "\n";
	}
	std::cout << "\n";
	
	duplicarElementosMatriz(matriz);

	std::cout << "MATRIZ FINAL: \n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) std::cout << matriz[i][j] << " ";

		std::cout << "\n";
	}
	std::cout << "\n";

	// EX6
	int valores2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

	std::cout << "VETOR INICIAL: ";
	for (int i = 0; i < tamanhoVetor; i++) {
		std::cout << valores2[i] << " ";
	}
	std::cout << "\n";

	fatorialVetorCompleto(valores2, tamanhoVetor);

	std::cout << "VETOR FINAL: ";
	for (int i = 0; i < tamanhoVetor; i++) {
		std::cout << valores2[i] << " ";
	}
	std::cout << "\n\n";


	return 0;
}