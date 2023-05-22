package hw.pa.pa2;

/*  Java Class: CSCI 145
    Author: Ivan Leung
    Class: Mon/Wed
    Date: Mar 1 2023
    Description:

    I certify that the code below is my own work.

	Exception(s): N/A

*/

//***************************************************************
//File: Paint.java
//
//Purpose: Determine how much paint is needed to paint the walls
//of a room given its length, width, and height
//***************************************************************
import java.util.Scanner;

public class Paint {
    public static void main(String[] args) {
        final int COVERAGE = 350; // paint covers 350 sq ft/gal
        int length, width, height, numberOfDoor, numberOfWindow; // declare integers length, width, and height;
        double totalSqft; // declare double totalSqFt;
        double paintNeeded; // declare double paintNeeded;
        Scanner scan = new Scanner(System.in); // declare and initialize Scanner object
        System.out.println("Enter the length of the room: ");// Prompt for and read in the length of the room
        length = scan.nextInt();
        System.out.println("Enter the width of the room: ");// Prompt for and read in the width of the room
        width = scan.nextInt();
        System.out.println("Enter the height of the room: ");// Prompt for and read in the height of the room
        height = scan.nextInt();
        System.out.println("Enter the number of the door(s) in the room: ");// Compute the total square feet to be painted--think
        numberOfDoor = scan.nextInt();
        System.out.println("Enter the number of the window(s) in the room: ");// Compute the total square feet to be painted--think
        numberOfWindow = scan.nextInt();
        scan.close();
        totalSqft = 2 * ((length * height) + (width * height));
        totalSqft -= (numberOfDoor * 20);
        totalSqft -= (numberOfWindow * 15);
        paintNeeded = totalSqft / COVERAGE;
        // about the dimensions of each wall
        // Compute the amount of paint needed
        // Print the length, width, and height of the room and the
        // number of gallons of paint needed.
        System.out.println("\tLength - " + length + " ft");
        System.out.println("\tWidth - " + width + " ft");
        System.out.println("\tHeight - " + height + " ft");
        System.out.println("\t" + numberOfDoor + " door(s)" + " and " + numberOfWindow + " window(s)");
        System.out.println(paintNeeded + " gallons -- amount of paint");
    }
}