#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double media(int n, vector<double> numbers) {
    double sum = 0;
    double avg = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
        avg = sum / n;
    }
    return avg;
}

int quantidadePares(int n, vector<double>& numbers) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (static_cast<int>(round(numbers[i])) % 2 == 0) {
            count++;
        }
    }
    return count;
}

int quantidadeImpares(int n, vector<double>& numbers) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (static_cast<int>(round(numbers[i])) % 2 != 0) {
            count++;
        }
    }
    return count;
}

void ordenacao(int n, vector<double>& numbers) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

bool moda(vector<double>& numbers, double& modaValue) {
    if (numbers.empty()) return false;
    
    int maxCount = 0;
    bool foundModa = false;
    
    for (int i = 0; i < numbers.size(); i++) {
        int count = 0;
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[j] == numbers[i]) {
                count++;
            }
        }
        
        if (count > maxCount && count > 1) {
            maxCount = count;
            modaValue = numbers[i];
            foundModa = true;
        }
    }
    
    if (foundModa) {
        for (int i = 0; i < numbers.size(); i++) {
            int count = 0;
            for (int j = 0; j < numbers.size(); j++) {
                if (numbers[j] == numbers[i]) {
                    count++;
                }
            }
            if (count == maxCount && numbers[i] != modaValue) {
                return false; 
            }
        }
        return true;
    }
    
    return false;
}

double mediana(int n, vector<double>& numbers) {
    ordenacao(n, numbers);
    double median;
    if (n % 2 == 0) {
        median = (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else {
        median = numbers[n / 2];
    }
    printf("Mediana: %.2f\n", median);
    return median;
}

int main() {
    printf("Digite quantos números deseja inserir: ");
    int n;
    cin >> n;
    vector<double> numbers(n);

    printf("Digite os números:\n");
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    //Máximo e Mínimo
    printf("MAIOR E MENOR NÚMERO\n");

    double max = numbers[0];
    double min = numbers[0];
    for (int i = 0; i < n; i++){
        if(numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    printf("Maior número: %.2f\nMenor número: %.2f\n", max, min);

    //Média
    printf("MÉDIA\n");

    media(n, numbers);
    printf("Média: %.2f\n", media(n, numbers));

    //Quantidade de números pares e ímpares
    printf("QUANTIDADE DE NÚMEROS PARES E ÍMPARES\n");

    quantidadePares(n, numbers);
    quantidadeImpares(n, numbers);
    printf("Quantidade de números pares: %d\n"
            "Quantidade de números ímpares: %d\n", quantidadePares(n, numbers), quantidadeImpares(n, numbers));

    //Ordenação
    printf("NÚMEROS EM ORDEM\n");

    ordenacao(n, numbers);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");

    //Moda e mediana
    printf("MODA E MEDIANA DOS NÚMEROS\n");

    double result;
     if (moda(numbers, result)) {
        printf("Moda: %.2f\n", result);
    } else {
        printf("Não há moda\n");
    }
    mediana(n, numbers);

    return 0;
}