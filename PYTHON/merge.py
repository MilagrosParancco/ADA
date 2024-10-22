import os
import time

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

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
                sorted_data = merge_sort(data)
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
