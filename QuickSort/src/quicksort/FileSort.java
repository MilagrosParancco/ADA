package quicksort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FileSort {

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            
            int pi = partition(arr, low, high);

            
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    private static int partition(int[] arr, int low, int high) {
        
        int pivot = arr[high];
        int i = (low - 1); 

        for (int j = low; j < high; j++) {
            
            if (arr[j] <= pivot) {
                i++;

                
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1; 
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

            quickSort(arr, 0, arr.length - 1); 

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
