#include <iostream>

int main() {
    float med_mts;
    int cent;

    std::cout << "Digite a media em metros: ";
    std::cin >> med_mts;

    cent = static_cast<int>(med_mts * 100);

    std::cout << med_mts << " equivale a " << cent << " centimetros";

    return 0;
}