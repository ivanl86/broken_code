package java_practice.Exceptions;

import java.io.FileNotFoundException;
// import java.io.FileReader;
import java.util.Arrays;

public class Main {
    
    public static void main(String[] args) throws FileNotFoundException {
        Integer[] arr = new Integer[4];
        // int[] arr = new int[4];
        // openFile("file.txt");
        for (int i = 0; i < arr.length; ++i) {
            arr[i] = i + 1;
        }
        System.out.println(Arrays.toString(arr));
        swap(arr, 0, 1);
        for (Integer i : arr) {
            System.out.print(" " + i);
        }
    }

    // public static void openFile(String fileName) throws FileNotFoundException {
    //     FileReader file = new FileReader(fileName);
    // }

    private static <T> void swap (T[] arr, int left, int right) {
        T temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
}
