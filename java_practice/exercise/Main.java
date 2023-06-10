package java_practice.exercise;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
        int[] arr = new int[5];
        Random rand = new Random();
        int same;

        for (int i = 0; i < arr.length; ++i) {
            arr[i] = rand.nextInt(6) + 1;
        }
        bubbleSort(arr);
        for (int i = 0; i < arr.length; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        same = isSame(arr);
        if (same > 1)
            System.out.println("There are " + same + " same values.");
        else if (same == 1)
            System.out.println("The values are in consecutive sequence.");
        else
            System.out.println("There are no same values or consecutive sequence.");
    }

    public static int isSame(int[] arr) {
        int[] frequency = new int[6];
        int max = 0;
        for (int i = 0; i < arr.length; ++i) {
            ++frequency[arr[i] - 1];
        }
        for (int i = 0; i < frequency.length; ++i) {
            if (frequency[i] > max)
                max = frequency[i];
        }
        return (max > 1 ? max : (isConseSorted(arr) ? 1 : 0));
    }

    public static boolean isConseSorted(int[] arr) {
        for (int i = 0; i < arr.length - 1; ++i) {
            if (arr[i] != arr[i + 1] - 1)
                return false;
        }
        return true;
    }

    public static void bubbleSort(int[] arr) {
        boolean isSwapped = false;
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr.length - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
                break;
        }
    }

    public static void swap(int[] arr, int left, int right) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
}
