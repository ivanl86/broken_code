package java_practice.pets;

public class Cat extends Pet {
    public Cat(String name, int age, int weight) {
        super(name, age, weight);
    }

    public String speak() {
        return "Meow";
    }

    public String rubHead() {
        return "Rubbing head against you.";
    }
}
