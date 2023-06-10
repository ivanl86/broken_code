package java_practice.pets;

// import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Pet dog = new Dog("Doggy", 2, 95);
        Pet cat = new Cat("Kitten", 3, 30);

        Pet[] pets = new Pet[2];

        pets[0] = new Dog("Lucky", 2, 95);
        pets[1] = new Cat("Mi", 3, 30);
    
        // Scanner scan = new Scanner(System.in);
        System.out.println(cat.speak());
        System.out.println(dog.speak());

        if (cat instanceof Cat)
            System.out.println(cat.getName() + " " + ((Cat) cat).rubHead());
        else
            System.out.print(" is not a cat!\n");

        System.out.println(dog.getName() + " " + ((dog instanceof Dog) ? ((Dog) dog).wagTail() : " is not a dog!"));

        for (Pet pet : pets) {
            System.out.println(pet.getName() + " " + ((pet instanceof Dog) ? ((Dog) pet).wagTail() : " is not a dog!"));
            System.out.println(pet.getName() + " " + ((pet instanceof Cat) ? ((Cat) pet).rubHead() : " is not a cat!"));
        }
    }
}
