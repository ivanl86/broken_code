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

public class Secondsv2 {
    public static void main(String[] args) {
        int hours = 0, minutes = 0, seconds = 0, totalSeconds;
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the total number of seconds: ");
        totalSeconds = scan.nextInt();
        seconds = totalSeconds;

        while (seconds >= 3600) {
            seconds -= 3600;
            ++hours;
        }
        while (seconds >= 60) {
            seconds -= 60;
            ++minutes;
        }
        scan.close();
        System.out.println();

        System.out.println(totalSeconds + " seconds is equivalent to ");
        System.out.print( hours + " hour(s) " + minutes + " minute(s) " + seconds + " seconds.");
    }
}
