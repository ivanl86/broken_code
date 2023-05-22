package hw.pa.pa2;

/*  Java Class: CSCI 145
Author: Ivan Leung
Class: Mon/Wed
Date: Mar 1 2023
Description:

I certify that the code below is my own work.

Exception(s): N/A

*/
import java.util.Scanner;
import java.text.NumberFormat;

public class Coins {
    public static void main(String[] args) {
        final double quarter = 0.25;
        final double dime = 0.10;
        final double nickel = 0.05;
        final double penny = 0.01;
        int quarterQty = 0;
        int dimeQty = 0;
        int nickelQty = 0;
        int pennyQty = 0;
        double amount;
        double actualAmount;

        Scanner scan = new Scanner(System.in);
        NumberFormat currency = NumberFormat.getCurrencyInstance();

        System.out.print("Enter an amount between 0.00 to 0.99 --> ");
        amount = scan.nextDouble();
        scan.close();
        actualAmount = amount;

        while (actualAmount >= quarter) {
            actualAmount -= quarter;
            ++quarterQty;
        }
        while (actualAmount >= dime) {
            actualAmount -= dime;
            ++dimeQty;
        }
        while (actualAmount >= nickel) {
            actualAmount -= nickel;
            ++nickelQty;
        }
        while (actualAmount > 0) {
            actualAmount -= penny;
            ++pennyQty;
        }

        actualAmount += (quarterQty * quarter) + (dimeQty * dime) + (nickel * nickelQty) + (penny * pennyQty);
        System.out.println("The amount " + currency.format(amount) + " is converted to:");
        System.out.println("\t" + quarterQty + " quarters");
        System.out.println("\t" + dimeQty + " dimes");
        System.out.println("\t" + nickelQty + " nickels");
        System.out.println("\t" + pennyQty + " pennies");
        System.out.println();
        System.out.println("Actual conversion amount: " + currency.format(actualAmount));
        if (Math.abs(actualAmount - amount) <= 0.01)
            System.out.println("The two amounts are the same!");
        else
            System.out.println("The two amounts are not the same!");
    }
}
