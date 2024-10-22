package mergesort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FileSort {

    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            
            int mid = (left + right) / 2;

            
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            
            merge(arr, left, mid, right);
        }
    }

    public static void merge(int[] arr, int left, int mid, int right) {
        
        int n1 = mid - left + 1;
        int n2 = right - mid;

        
        int[] L = new int[n1];
        int[] R = new int[n2];

        
        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        
        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
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

            mergeSort(arr, 0, arr.length - 1); 

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
