package csci_145.hw.hw1;

/*  Java Class: CSCI 145
Author: Ivan Leung
Class: Mon/Wed
Date: Mar 1 2023
Description:

I certify that the code below is my own work.

Exception(s): N/A

*/

import java.util.Scanner;

public class Seconds {
    public static void main(String[] args) {
        int hours, minutes, seconds, totalSeconds;
        Scanner scan = new Scanner(System.in);
    
        System.out.print("Enter the number of hours: ");
        hours = scan.nextInt();
        System.out.print("Enter the number of minutes: ");
        minutes = scan.nextInt();
        System.out.print("Enter the number of seconds: ");
        seconds = scan.nextInt();
        scan.close();
        System.out.println();
    
        totalSeconds = seconds + (minutes * 60) + (hours * 3600);
    
        System.out.print(hours + " hour(s) " + minutes + " minute(s) " + seconds + " seconds ");
        System.out.println("is equivalent to " + totalSeconds + " seconds.");
    }
}
