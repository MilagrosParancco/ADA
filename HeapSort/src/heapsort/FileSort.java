package heapsort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FileSort {

    public static void heapSort(int[] arr) {
        int n = arr.length;

        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        
        for (int i = n - 1; i > 0; i--) {
            
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;

            
            heapify(arr, i, 0);
        }
    }

    
    private static void heapify(int[] arr, int n, int i) {
        int largest = i; 
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 

        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            
            heapify(arr, n, largest);
        }
    }

    public static int[] readFromFile(String filename) throws IOException {
        List<Integer> numbers = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(filename));
        String line;

        while ((line = br.readLine()) != null) {
            String[] parts = line.split("\\s+");
            for (String part : parts) {
                if (!part.trim().isEmpty()) {
                    try {
                        numbers.add(Integer.parseInt(part.trim()));
                    } catch (NumberFormatException e) {
                        System.err.println("Error en el formato de número: " + part);
                    }
                }
            }
        }
        br.close();
        return numbers.stream().mapToInt(i -> i).toArray();
    }

    public static void printArray(int[] arr) {
        int count = 0;
        for (int num : arr) {
            System.out.print(num + " ");
            count++;
            if (count % 10 == 0) {
                System.out.println();
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese el nombre del archivo (con extensión .txt): ");
        String filename = scanner.nextLine();

        try {
            int[] arr = readFromFile(filename);
            long startTime = System.nanoTime(); 

            heapSort(arr); 

            long endTime = System.nanoTime(); 
            long duration = endTime - startTime; 

            System.out.print("Números ordenados: ");
            printArray(arr);
            System.out.println("Tiempo de ordenamiento: " + duration + " nanosegundos");
        } catch (IOException e) {
            System.err.println("Error al leer el archivo: " + e.getMessage());
        }
    }
}
