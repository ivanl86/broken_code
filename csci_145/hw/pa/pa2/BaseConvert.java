package broken_code.csci_145.hw.pa.pa2;

/*  Java Class: CSCI 145
Author: Ivan Leung
Class: Mon/Wed
Date: Mar 1 2023
Description:

I certify that the code below is my own work.

Exception(s): N/A

*/
import java.util.Scanner;

public class BaseConvert {
    public static void main(String[] args) {
        int newBase;
        int baseTenNumber;
        int quotient;
        int maxNumber;
        int index = 3;
        int[] newBaseNumbers = new int[4];
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the number for the new base: ");
        newBase = scan.nextInt();
        maxNumber = (int)Math.pow(newBase, 4) - 1;
        System.out.println();

        System.out.println("The base 10 number to be converted cannot exceed " + maxNumber);
        System.out.print("Enter the number in base 10 to be converted: ");
        baseTenNumber = scan.nextInt();
        scan.close();
        System.out.println();

        quotient = baseTenNumber;

        while (index >= 0) {
            newBaseNumbers[index] = quotient % newBase;
            quotient /= newBase;
            --index;
        }

        System.out.println("Base 10 number: " + baseTenNumber);
        System.out.print("Base " + newBase + " number: ");
        for (int i = 0; i < newBaseNumbers.length; ++i) {
            System.out.print(newBaseNumbers[i]);
        }
    }
}
