package java_practice.sort_n_search;

import java.util.Random;

public class Main {
    
    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[10];

        for (int i = 0; i < arr.length; ++i) {
            arr[i] = rand.nextInt(100) + 1;
        }
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
        mergeSort(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void mergeSort(int[] arr) {
        int midIdx;
        int[] leftHalf;
        int[] rightHalf;

        if (arr.length < 2)
            return;

        midIdx = arr.length / 2;

        leftHalf = new int[midIdx];
        rightHalf = new int[arr.length - midIdx];

        for (int i = 0; i < midIdx; ++i) {
            leftHalf[i] = arr[i];
        }
        for (int i = midIdx; i < arr.length; ++i) {
            rightHalf[i - midIdx] = arr[i];
        }

        mergeSort(leftHalf);
        mergeSort(rightHalf);

        merge(arr, leftHalf, rightHalf);
    }

    private static void merge(int[] arr, int[] leftHalf, int[] rightHalf) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < leftHalf.length && j < rightHalf.length) {
            if (leftHalf[i] <= rightHalf[j]) {
                arr[k] = leftHalf[i];
                ++i;
            }
            else {
                arr[k] = rightHalf[j];
                ++j;
            }
            ++k;
        }
        while (i < leftHalf.length) {
            arr[k] = leftHalf[i];
            ++i;
            ++k;
        }
        while (j < rightHalf.length) {
            arr[k] = rightHalf[j];
            ++j;
            ++k;
        }
    }
}