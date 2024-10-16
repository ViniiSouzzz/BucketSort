def insertion_sort(bucket):
    for i in range(1, len(bucket)):
        key = bucket[i]
        j = i - 1
        while j >= 0 and key < bucket[j]:
            bucket[j + 1] = bucket[j]
            j -= 1
        bucket[j + 1] = key

def bucket_sort(array):
    # Determinar o número de baldes
    bucket_count = 10
    max_value = max(array)
    size = len(array)
    
    # Criar baldes vazios
    buckets = [[] for _ in range(bucket_count)]

    # Distribuir os elementos nos baldes apropriados
    for i in range(size):
        index = int(array[i] * bucket_count / (max_value + 1))
        buckets[index].append(array[i])

    # Ordenar cada balde usando insertion sort
    for i in range(bucket_count):
        insertion_sort(buckets[i])

    # Concatenar os baldes em um único array
    sorted_array = []
    for i in range(bucket_count):
        sorted_array.extend(buckets[i])

    return sorted_array

# Função para imprimir o array
def print_array(array):
    for i in array:
        print(i, end=" ")
    print()

if __name__ == "__main__":
    array = [29, 25, 3, 49, 9, 37, 21, 43]
    print("Array original:")
    print_array(array)

    sorted_array = bucket_sort(array)
    print("Array ordenado:")
    print_array(sorted_array)
