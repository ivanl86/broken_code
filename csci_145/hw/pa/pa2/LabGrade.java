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

public class LabGrade {
    public static void main(String[] args) {
        double inClassWeight;
        double outClassWeight;
        int preLabPts;
        int preLabMax;
        int labPts;
        int labMax;
        int postLabPts;
        int postLabMax;
        double outClassAvg;
        double inClassAvg;
        double labGrade;
        Scanner scan = new Scanner(System.in);

        System.out.println("\nWelcome to the Lab Grade Calculator\n");
        System.out.print("Enter the number of points you earned on the pre-lab assignment: ");
        preLabPts = scan.nextInt();
        System.out.print("What was the maximum number of points you could have earned? ");
        preLabMax = scan.nextInt();
        System.out.print("Enter the number of points you earned on the lab assignment: "); 
        labPts = scan.nextInt(); 
        System.out.print("What was the maximum number of points for the lab assignement? "); 
        labMax = scan.nextInt(); 
        System.out.print("Enter the number of points you earned on the post-lab assignment: "); 
        postLabPts = scan.nextInt(); 
        System.out.print("What was the maximum number of points for the post-lab assignment? "); 
        postLabMax = scan.nextInt(); 
        System.out.println("Enter the weight for in-class and out-of-class works in decimal: ");
        System.out.println("For example, you shoubld enter 0.3 for 30%");
        System.out.print("What is the weight of the in-class work? ");
        inClassWeight = scan.nextDouble();
        System.out.print("What is the weight of the out-of-class work? ");
        outClassWeight = scan.nextDouble();
        scan.close();
        System.out.println();

        outClassAvg = (((double)preLabPts + postLabPts) / ((double)preLabMax + postLabMax) * 100);
        inClassAvg = (((double)labPts / labMax) * 100);
        labGrade = ((outClassAvg * outClassWeight) + (inClassAvg * inClassWeight));

        System.out.println("Your average on out-of-class work is " + outClassAvg + "%");
        System.out.println("Your average on in-class work is " + inClassAvg + "%");
        System.out.println("Your lab grade is " + labGrade + "%");
        System.out.println();
    }
}
