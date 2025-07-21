#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); // Semente para o gerador de números aleatórios
    int X = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
    printf("Adivinhe o número entre 1 e 100:\n");
    
    int palpite = 0;
    for (int i = 0; i < 100; i++) {
        cin >> palpite;
        
        if (palpite < 1 || palpite > 100) {
            printf("Número inválido! Tente novamente\n");
        } else if (palpite == X) {
            printf("Acertou!\n");
            break; 
        } else if (palpite < X) {
            printf("Um pouco menor! Tente novamente.\n");
        } else {
            printf("Um pouco maior! Tente novamente.\n");
        }
    }

    return 0;
}