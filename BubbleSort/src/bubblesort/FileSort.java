package bubblesort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FileSort {

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
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

            bubbleSort(arr);

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

