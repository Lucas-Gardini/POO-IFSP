#include <iostream>

int main() {
	// Verificar se número é par ou ímpar
	int num;

	std::cout << "Digite o numero a ser verificado: ";
	std::cin >> num;

	if (num % 2) std::cout << num << " -> impar\n";
	else std::cout << num << " -> par\n";

	// Verificar se número é positivo, zero, ou negativo

	if (num == 0) std::cout << num << " -> zero";
	else if (num > 0) std::cout << num << " -> positivo";
	else std::cout << num << " -> negativo";

	// Verifica quais dos três números é maior, e avisa caso 2 ou 3 sejam iguais
	int num1, num2, num3, maior, qtd_iguais = 0;

	std::cout << "\nDigite o primeiro numero a ser verificado: ";
	std::cin >> num1;

	std::cout << "Digite o segundo numero a ser verificado: ";
	std::cin >> num2;

	std::cout << "Digite o terceiro numero a ser verificado: ";
	std::cin >> num3;

	maior = num1;

	if (maior < num2) maior = num2;
	if (maior < num3) maior = num3;

	if (num1 == num2) qtd_iguais+=2;
	if (num1 == num3) qtd_iguais+=2;
	if (num2 == num3) qtd_iguais+=2;

	// Se por acaso ele passar em todas as condições acima, quer dizer que todos são iguais
	if (qtd_iguais == 6) qtd_iguais = 3;

	std::cout << "\nO maior numero -> " << maior << " e " << qtd_iguais << " sao iguais!";

	// Verificando se o ano é bissexto
	int ano, dezena;

	std::cout << "\nDigite o ano a ser verificado: ";
	std::cin >> ano;

	if (ano % 4 == 0) {
		dezena = ano % 100;
		if (dezena % 4 == 0) std::cout << ano << " -> bissexto";
		else std::cout << ano << " -> nao bissexto";
	} else std::cout << ano << " -> nao bissexto";

	return 0;
}