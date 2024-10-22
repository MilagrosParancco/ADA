import os
import time

def heapify(arr, n, i):
    largest = i  
    left = 2 * i + 1  
    right = 2 * i + 2  

    
    if left < n and arr[left] > arr[largest]:
        largest = left

    
    if right < n and arr[right] > arr[largest]:
        largest = right

    
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  
        heapify(arr, n, largest)  

def heap_sort(arr):
    n = len(arr)

    
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

   
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  
        heapify(arr, i, 0)

    return arr

def read_file(file_path):
    try:
        with open(file_path, 'r') as file:
            return [int(num) for num in file.readline().strip().split()]
    except Exception as e:
        print(f"Error al leer el archivo {file_path}: {e}")
        return []

def process_files(file_paths):
    for file_path in file_paths:
        if os.path.isfile(file_path):
            data = read_file(file_path)
            if data:  
                start_time = time.time()
                sorted_data = heap_sort(data)
                end_time = time.time()
                execution_time = end_time - start_time
                print(f"Archivo: {file_path}, Tiempo de ejecución: {execution_time:.6f} segundos")
        else:
            print(f"Archivo no encontrado: {file_path}")

if __name__ == "__main__":
    archivos = [
        '100.txt', '500.txt', '1000.txt', '2000.txt', '3000.txt',
        '4000.txt', '5000.txt', '6000.txt', '7000.txt', '8000.txt',
        '9000.txt', '10000.txt', '20000.txt', '30000.txt',
        '40000.txt', '50000.txt', '60000.txt', '70000.txt',
        '80000.txt', '90000.txt', '100000.txt'
    ]  
    process_files(archivos)
