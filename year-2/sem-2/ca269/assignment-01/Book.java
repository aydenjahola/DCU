/**
 * Book.java - Assignment 01
 * 
 * This class represents a book with various attributes such as title, author,
 * genre, etc.
 * It also provides constructors, getters, and a toString method for accessing
 * and displaying book information.
 * The class includes enums for BookMedium, BookGenre, and BookRating to
 * represent different attributes of a book.
 * The main method demonstrates the usage of the Book class.
 * 
 * @author Ayden Jahola
 */

enum BookMedium {
    PhysicalBook, EBook, AudioBook
}

enum BookGenre {
    Fiction, NonFiction
}

enum BookRating {
    Rating1(1), Rating2(2), Rating3(3), Rating4(4), Rating5(5);

    private final int value;

    BookRating(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

class Book {
    // fields are private
    private String title;
    private String author;
    private int publishedDate;
    private int readDate;
    private BookMedium readMedium;
    private BookGenre genre;
    private BookRating rating;

    /**
     * Default constructor takes title, author, and genre
     * 
     * @param title  The title of the book
     * @param author The author of the book
     * @param genre  The genre of the book
     */
    public Book(String title, String author, BookGenre genre) {
        this.title = title;
        this.author = author;
        this.genre = genre;
    }

    /**
     * Additional constructor also takes published date
     * 
     * @param title         The title of the book
     * @param author        The author of the book
     * @param genre         The genre of the book
     * @param publishedDate The published date of the book
     */
    public Book(String title, String author, BookGenre genre, int publishedDate) {
        this(title, author, genre);
        this.publishedDate = publishedDate;
    }

    /**
     * Additional constructor also takes published date,
     * read date, read medium, and rating
     * 
     * @param title         The title of the book
     * @param author        The author of the book
     * @param genre         The genre of the book
     * @param publishedDate The published date of the book
     * @param readDate      The read date of the book
     * @param readMedium    The medium in which the book was read
     * @param rating        The rating of the book
     */
    public Book(String title, String author, BookGenre genre, int publishedDate, int readDate,
            BookMedium readMedium, BookRating rating) {
        this(title, author, genre, publishedDate);
        this.readDate = readDate;
        this.readMedium = readMedium;
        this.rating = rating;
    }

    // getters
    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public int getPublishedDate() {
        return publishedDate;
    }

    public int getReadDate() {
        return readDate;
    }

    public BookMedium getMedium() {
        return readMedium;
    }

    public BookGenre getGenre() {
        return genre;
    }

    public BookRating getRating() {
        return rating;
    }

    // setters (optional, not used in this code)

    /**
     * toString implementation
     * Depends on available information
     * For title, an author, and a genre - Title by Author
     * If publication date is present - Title by Author (Year of Publication)
     * If read date, read medium, and rating is present -
     * Title by Author (Year of Publication) - read in Year of Reading, rated
     * rating/5
     */
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder(title + " by " + author);
        if (publishedDate != 0) {
            result.append(" (").append(publishedDate).append(")");
        }
        if (readDate != 0 && readMedium != null && rating != null) {
            result.append(" - read in ").append(readDate).append(", rated ").append(rating.getValue()).append("/5");
        }
        return result.toString();
    }

    public static void main(String[] args) {
        // Create instances of Book class
        Book b1 = new Book("Children of Time", "Adrian Tchaikovsky", BookGenre.Fiction);
        System.out.println(b1);
        Book b2 = new Book("The Fifth Season", "N. K. Jemesin", BookGenre.Fiction, 2015);
        System.out.println(b2);
        Book b3 = new Book("Perdido Street Station", "China Mieville",
                BookGenre.Fiction, 2000, 2020, BookMedium.EBook, BookRating.Rating5);
        System.out.println(b3);

        // Access and print book attributes
        System.out.println(b1.getTitle());
        System.out.println(b1.getAuthor());
        System.out.println(b1.getGenre());
        System.out.println(b2.getPublishedDate());
        System.out.println(b3.getReadDate());
        System.out.println(b3.getMedium());
        System.out.println(b3.getRating());
    }
}
