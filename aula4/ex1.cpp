#include <iostream>

int main() {
	// Exercício 1
	int intVar;
	int *ptr1;
	int **ptr2;

	ptr1 = &intVar;
	ptr2 = &ptr1;

	**ptr2 = 17;

	std::cout << "O valor final de intVar: " << intVar << "\n";

	// Exercício 2
	int val1 = 11, val2 = 22;

	std::cout << "O valor inicial de val1 e val2: " << val1 << ", " << val2 << "\n";

	int *ptr3 = &val1, *ptr4 = &val2;
	int **ponteiro1 = &ptr3, **ponteiro2 = &ptr4;
	int temp = **ponteiro1;

	**ponteiro1 = **ponteiro2;
	**ponteiro2 = temp;

	std::cout << "O valor final de val1 e val2: " << val1 << ", " << val2 << "\n";

	// Exercícios 3
	int int1, int2, int3;

	for (int i = 0; i < 3; i++) {
		std::cout << "Digite o " << i + 1 << " numero: ";
		
		if (i == 0) std::cin >> int1;
		else if (i == 1) std::cin >> int2;
		else std::cin >> int3;
	}

	int *colunas[3];

	for (int i = 0; i < 3; i++) {
		colunas[i] = new int[3];
	}

	for (int col = 0; col < 3; col++) {
		for (int lin = 0; lin < 3; lin++) {
			if (lin == 0) colunas[col][lin] = int1;
			else if (lin == 1) colunas[col][lin] = int2;
			else colunas[col][lin] = int3;
		}
	}

	for (int col = 0; col < 3; col++) {
		for (int lin = 0; lin < 3; lin++) {
			std::cout << colunas[col][lin] << " ";
		}
		std::cout << "\n";
	} 

	for (int i = 0; i < 3; i++) {
		delete[] colunas[i];
	}

	return 0;
}