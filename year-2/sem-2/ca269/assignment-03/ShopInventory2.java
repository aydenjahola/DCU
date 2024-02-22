
/**
 * ShopInventory2.java - Assignment 02
 * 
 * This class represents a shop inventory with various attributes such as items,
 * baskets, checkouts, and bills. It also provides constructors, getters, and a
 * toString method for accessing and displaying shop inventory information. The class
 * includes classes Item, Basket, Checkout, and Bill to represent different attributes
 * of a shop inventory. The main method demonstrates the usage of the ShopInventory2
 * class.
 * 
 * @author Ayden Jahola
 */

import java.util.*;

/**
 * Class Item
 * Represents Food Items
 * has name, weight, price
 */
class Item {
    private final String name;
    private final double price;

    /**
     * Creates an Item
     * 
     * @param name  of item
     * @param price of item
     */
    Item(String name, double price) {
        this.name = name;
        this.price = price;
    }

    /**
     * Gets the name of the item
     * 
     * @return name of item
     */
    public String getName() {
        return this.name;
    }

    /**
     * Gets the price of the item
     * 
     * @return price of item
     */
    public double getPrice() {
        return this.price;
    }

    /**
     * Returns a string representation of the item
     * 
     * @return string representation of item
     */
    public String toString() {
        return this.name + " " + this.price;
    }
}

/**
 * Class Basket
 * Represents a basket of items
 * has a stack of items
 */
class Basket {
    private final Stack<Item> basket;

    // TODO - create new stack for basket

    /**
     * Creates a new Basket
     */
    Basket() {
        this.basket = new Stack<Item>();
    }

    /**
     * Adds an item to the basket
     * 
     * @param item to add
     */
    public void addItem(Item item) {
        this.basket.push(item);
    }

    /**
     * Removes an item from the basket
     * 
     * @return removed item
     */
    public Item removeItem() {
        if (this.basket.isEmpty()) {
            return null;
        }
        return this.basket.pop();
    }

    /**
     * Checks if the basket is empty
     * 
     * @return true if empty, false otherwise
     */
    public boolean isEmpty() {
        return this.basket.isEmpty();
    }

    /**
     * Returns a string representation of the basket
     * 
     * @return string representation of basket
     */
    public String toString() {
        return "basket:" + this.basket.toString();
    }

}

/**
 * Class Checkout
 * Represents a checkout of items
 * has a queue of items
 */
class Checkout {
    private final Queue<Item> checkout;

    Checkout(Basket basket) {
        // TODO - create the queue, add items from basket by using addItem()
        // first, create a new queue for the checkout
        // remember - Queue is an interface, so you need to choose a suitable
        // implementation like LinkedList
        // second, go through the basket, remove each item out of the basket
        // and add it to the checkout

        this.checkout = new LinkedList<Item>();
        while (!basket.isEmpty()) {
            this.checkout.add(basket.removeItem());
        }
    }

    /**
     * Adds an item to the checkout
     * 
     * @param item to add
     */
    public void addItem(Item item) {
        // TODO - add item to the checkout queue

        if (item != null) {
            this.checkout.add(item);
        }
    }

    /**
     * Removes an item from the checkout
     * 
     * @return removed item
     */
    public Item removeItem() {
        // TODO - remove item from the checkout queue
        // don't forget to check if its empty first!

        if (this.checkout.isEmpty()) {
            return null;
        }
        return this.checkout.remove();
    }

    /**
     * Checks if the checkout is empty
     * 
     * @return true if empty, false otherwise
     */
    public boolean isEmpty() {
        return this.checkout.isEmpty();
    }

    /**
     * Returns a string representation of the checkout
     * 
     * @return string representation of checkout
     */
    public String toString() {
        return "checkout:" + this.checkout.toString();
    }
}

/**
 * Class Bill
 * Represents a bill of items
 * has a map of items and a price
 */
class Bill {
    private final Map<String, Integer> basket;
    private double price;

    /**
     * Creates a new Bill
     * 
     */
    Bill(Checkout checkout) {
        // TODO - initialise Map, set price, bill items from checkout
        // first, create the Map for the basket - just like Queue,
        // you must select an implementation such as LinkedHashMap
        // second, our starting price is zero - there are no items yet
        // third, iterate through the checkout items -
        // take an item out of the checkout, and bill it

        this.basket = new LinkedHashMap<String, Integer>();
        this.price = 0;
        while (!checkout.isEmpty()) {
            billItem(checkout.removeItem());
        }
    }

    /**
     * Bills an item
     * 
     * @param item to bill
     */
    public void billItem(Item item) {
        // TODO - put item in map, keep count of same items being billed
        // Note that the Map is from key String to value Integer
        // Items have names as Strings and count of items is an integer
        // first, check if the Item already exists in the Map -
        // the Item name is what we use as the key
        // If it exists - we need to increment its counter by 1
        // If not - we need to create a new key with the item name and value 1
        // second, add the item's price to the bill total price

        /**
         * If the item is not null, then we add it to the basket and increment the price
         */
        if (item != null) {
            String itemName = item.getName();
            if (this.basket.containsKey(itemName)) {
                this.basket.put(itemName, this.basket.get(itemName) + 1);
            } else {
                this.basket.put(itemName, 1);
            }
            this.price += item.getPrice();
        }
    }

    /**
     * Gets the total price of the bill
     * 
     * @return total price of bill
     */
    public double getTotal() {
        return this.price;
    }

    /**
     * Returns a string representation of the bill
     * 
     * @return string representation of bill
     */
    public String toString() {
        String output = "";
        for (String item : this.basket.keySet()) {
            output += item + " (" + this.basket.get(item) + "nos)\n";
        }
        return output + "total: " + this.price;
    }

}

/**
 * Class ShopInventory2
 * Represents a shop inventory
 * has a main method to demonstrate the usage of the classes
 */
class ShopInventory2 {

    public static void main(String[] args) {
        Basket basket = new Basket();
        loadBasket(basket);
        // System.out.println(basket); // for DEBUG
        Checkout checkout = new Checkout(basket);
        // System.out.println(checkout); // for DEBUG
        Bill bill = new Bill(checkout);
        System.out.println(bill);
    }

    static void loadBasket(Basket basket) {
        basket.addItem(new Item("Twinings Earl Grey Tea", 4.50));
        basket.addItem(new Item("Folans Orange Marmalade", 4.00));
        basket.addItem(new Item("Free-range Eggs", 3.35));
        basket.addItem(new Item("Brennan's Bread", 2.15));
        basket.addItem(new Item("Ferrero Rocher", 7.00));
        basket.addItem(new Item("Ferrero Rocher", 7.00));
    }
}
