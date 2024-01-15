import java.util.Scanner;

public class VowelAge {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String name = scanner.nextLine();

        int age = scanner.nextInt();

        int vowelCount = countVowels(name);
        String ageCategory = (age >= 18) ? "an adult" : "a minor";

        System.out.println("Hello " + name + ", you have " + vowelCount + " vowels, and you are " + ageCategory);
    }

    private static int countVowels(String name) {
        int count = 0;
        for (int i = 0; i < name.length(); i++) {
            char c = Character.toLowerCase(name.charAt(i));
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }
}
