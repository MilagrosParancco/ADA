import os
import time

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
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
                sorted_data = selection_sort(data)
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
