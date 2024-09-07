#include <iostream>
#include <vector>

int calcularPuntuacion(const std::vector<int>& numeros) {
    int puntuacionTotal = 0;

    for (int num : numeros) {
        if (num == 5) {
            puntuacionTotal += 5; 
        } else if (num % 2 == 0) {
            puntuacionTotal += 1; 
        } else {
            puntuacionTotal += 3; 
        }
    }

    return puntuacionTotal;
}

int main() {
    std::vector<int> numeros = {0, 2, 3, 5, 7, 8, 5};

    int resultado = calcularPuntuacion(numeros);

    std::cout << "La puntuación total es: " << resultado << std::endl;

    return 0;
}