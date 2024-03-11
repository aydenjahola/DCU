/**
 * MyFancyDataStructure.java - Assignment 04
 * 
 * This class implements a fancy data structure that changes its behaviors based on a setting.
 * It includes a class Value representing a value with an integer field and methods to
 * compare and sort values based on a flag. Additionally, it provides implementations
 * of Comparator interfaces for sorting based on lower or higher values. The main method
 * demonstrates the usage of this data structure.
 * 
 * @author Ayden Jahola
 */

import java.util.*;

// Define a class Value representing a value with a single integer field
class Value implements Comparable<Value> {
    private final int value; // Declare integer field value

    // Constructor to initialize the value field
    public Value(int value) {
        this.value = value;
    }

    // Getter method for accessing the value field
    public int getValue() {
        return this.value;
    }

    // Override toString method to return string representation of the value
    @Override
    public String toString() {
        return String.valueOf(value);
    }

    // Flag indicating whether to sort lower values higher or not
    private static boolean SORT_LOWER = false;

    // Method to check if sorting is set to lower values
    public static boolean isSortLower() {
        return SORT_LOWER;
    }

    // Method to check if sorting is set to higher values
    public static boolean isSortHigher() {
        return !SORT_LOWER;
    }

    // Method to set sorting to lower values
    public static void setSortLower() {
        SORT_LOWER = true;
    }

    // Method to set sorting to higher values
    public static void setSortHigher() {
        SORT_LOWER = false;
    }

    // Implementing the compareTo method from Comparable interface
    // Compares two Value objects based on the SORT_LOWER flag
    @Override
    public int compareTo(Value other) {
        if (SORT_LOWER) {
            return Integer.compare(this.value, other.value);
        } else {
            return Integer.compare(other.value, this.value);
        }
    }
}

// Comparator to prefer lower values
class PreferLowerValues implements Comparator<Value> {
    @Override
    public int compare(Value v1, Value v2) {
        return Integer.compare(v1.getValue(), v2.getValue());
    }
}

// Comparator to prefer higher values
class PreferHigherValues implements Comparator<Value> {
    @Override
    public int compare(Value v1, Value v2) {
        return Integer.compare(v2.getValue(), v1.getValue());
    }
}

// Main class to test the implementations
public class MyFancyDataStructure {
    public static void main(String[] args) {
        // Create a list of Value objects
        List<Value> list = Arrays.asList(
                new Value(2), new Value(3), new Value(1));

        // Test sorting with SORT_LOWER=true
        Value.setSortLower();
        Collections.sort(list);
        System.out.println(list); // OUTPUT: [1, 2, 3]

        // Test sorting with SORT_LOWER=false
        Value.setSortHigher();
        Collections.sort(list);
        System.out.println(list); // OUTPUT: [3, 2, 1]

        // Test sorting with PreferLowerValues
        list.sort(new PreferLowerValues());
        System.out.println(list); // OUTPUT: [1, 2, 3]

        // Test sorting with PreferHigherValues
        list.sort(new PreferHigherValues());
        System.out.println(list); // OUTPUT: [3, 2, 1]
    }
}
