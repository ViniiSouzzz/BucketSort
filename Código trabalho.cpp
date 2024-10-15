#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Estrutura para representar um balde
struct Bucket {
    int* data;
    int count;
};

// Função para inserir um valor no balde
void insertIntoBucket(struct Bucket* bucket, int value) {
    bucket->data[bucket->count++] = value;
}

// Função para ordenar um balde usando Insertion Sort
void insertionSort(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Função principal de Bucket Sort
void bucketSort(int array[], int n) {
    struct Bucket buckets[BUCKET_COUNT];
    
    // Inicializar os baldes
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i].data = (int*)malloc(n * sizeof(int));  // Aloca espaço para cada balde
        buckets[i].count = 0;  // Inicializa a contagem de elementos do balde
    }

    // Distribui os elementos no balde apropriado
    for (int i = 0; i < n; i++) {
        int bucketIndex = array[i] / BUCKET_COUNT;
        if (bucketIndex >= BUCKET_COUNT) bucketIndex = BUCKET_COUNT - 1; // Evitar overflow
        insertIntoBucket(&buckets[bucketIndex], array[i]);
    }

    // Ordena cada balde usando Insertion Sort
    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertionSort(buckets[i].data, buckets[i].count);
    }

    // Concatenar os elementos de todos os baldes no array original
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].data[j];
        }
    }

    // Libera a memória alocada para os baldes
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i].data);
    }
}

// Função para imprimir o array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    printArray(array, n);

    bucketSort(array, n);

    printf("Array ordenado: ");
    printArray(array, n);

    return 0;
}

