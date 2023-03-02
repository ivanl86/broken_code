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

public class IdealWeight {
    public static void main(String[] args) {
        final int FEMALE_WEIGHT_INTERVAL = 5;
        final int MALE_WEIGHT_INTERVAL = 6;
        int feet, inches, heightInInches;
        int femaleIdealWeight = 100, maleIdealWeight = 106;
        final double idealRange = 0.15;
        Scanner scan = new Scanner(System.in);
        System.out.println("Please enter your height in feet and inches format");
        System.out.print("Enter your height in feet: ");
        feet = scan.nextInt();
        System.out.print("Enter your height in inches: ");
        inches = scan.nextInt();
        scan.close();
        heightInInches = feet * 12;
        heightInInches += inches;
        femaleIdealWeight += ((heightInInches - 60) * FEMALE_WEIGHT_INTERVAL);
        maleIdealWeight += ((heightInInches - 60) * MALE_WEIGHT_INTERVAL);
        System.out.println();
        System.out.println("\tYour female ideal weight is: " + femaleIdealWeight + " pounds");
        System.out.println("\tYour male ideal weight is: " + maleIdealWeight + " pounds");
        System.out.print("\tYour female ideal weight range is between ");
        System.out.print((double)femaleIdealWeight - (femaleIdealWeight * idealRange) + " and ");
        System.out.println((double)femaleIdealWeight + (femaleIdealWeight * idealRange) + " pounds");
        System.out.print("\tYour male ideal weight range is between ");
        System.out.print((double)maleIdealWeight - (maleIdealWeight * idealRange) + " and ");
        System.out.println((double)maleIdealWeight + (maleIdealWeight * idealRange) + " pounds");
    }
}
