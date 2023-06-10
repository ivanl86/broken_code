package java_practice.pets;

public class Dog extends Pet {
    public Dog(String name, int age, int weight) {
        super(name, age, weight);
    }

    public String speak() {
        return "Woof";
    }

    public String wagTail() {
        return "Wagging its tail quickly.";
    }
}
