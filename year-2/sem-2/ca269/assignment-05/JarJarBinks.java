/**
 * JarJarBinks.java - Assignment 05
 * 
 * This program analyzes Star Wars characters from a CSV file, creating instances of a Java Beans class
 * to represent each character. It utilizes Apache Commons CSV for reading the CSV file and the GSON library
 * for serializing the Java Beans instances into JSON format. The main method orchestrates the reading,
 * processing, and serializing of character data, demonstrating file I/O, CSV parsing, Java Beans usage,
 * and JSON serialization in Java.
 * 
 * The output is a JSON file named "characters.json" that contains serialized data of Star Wars characters.
 * This program is designed to be flexible and efficient, showcasing best practices in Java development.
 * 
 * @author Ayden Jahola
 */

import com.google.gson.Gson;
import org.apache.commons.csv.CSVFormat;
import org.apache.commons.csv.CSVRecord;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

/**
 * This class represents a Star Wars character with various attributes like name, height, and mass.
 * It includes a default constructor, getters, and setters for all properties.
 */
class StarWarsCharacter {
    String name = "";
    String height = "";
    String mass = "";
    String hairColor = "";
    String skinColor = "";
    String eyeColor = "";
    String birthYear = "";
    String gender = "";
    String homeworld = "";
    String species = "";

    // Default constructor
    public StarWarsCharacter() { }

    // Getters and setters for all properties
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getHeight() {
        return height;
    }

    public void setHeight(String height) {
        this.height = height;
    }

    public String getMass() {
        return mass;
    }

    public void setMass(String mass) {
        this.mass = mass;
    }

    public String getHairColor() {
        return hairColor;
    }

    public void setHairColor(String hairColor) {
        this.hairColor = hairColor;
    }

    public String getSkinColor() {
        return skinColor;
    }

    public void setSkinColor(String skinColor) {
        this.skinColor = skinColor;
    }

    public String getEyeColor() {
        return eyeColor;
    }

    public void setEyeColor(String eyeColor) {
        this.eyeColor = eyeColor;
    }

    public String getBirthYear() {
        return birthYear;
    }

    public void setBirthYear(String birthYear) {
        this.birthYear = birthYear;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getHomeworld() {
        return homeworld;
    }

    public void setHomeworld(String homeworld) {
        this.homeworld = homeworld;
    }

    public String getSpecies() {
        return species;
    }

    public void setSpecies(String species) {
        this.species = species;
    }

    @Override
    public String toString() {
        // Custom toString method to print character information
        return "StarWarsCharacter{" +
                "name='" + name + '\'' +
                ", height='" + height + '\'' +
                ", mass='" + mass +
                ", hairColor='" + hairColor + '\'' +
                ", skinColor='" + skinColor + '\'' +
                ", eyeColor='" + eyeColor + '\'' +
                ", birthYear='" + birthYear + '\'' +
                ", gender='" + gender + '\'' +
                ", homeworld='" + homeworld + '\'' +
                ", species='" + species + '\'' +
                '}';
    }
}

/**
 * Main class to perform the task of reading CSV, creating Java Beans, and exporting to JSON.
 */
public class JarJarBinks {

    public static void main(String[] args) throws Exception {
        List<StarWarsCharacter> charactersList = new ArrayList<>();
        Reader in = new FileReader("characters.csv");
        Iterable<CSVRecord> records = CSVFormat.Builder.create().setHeader().build().parse(in);

        for (CSVRecord record : records) {
            StarWarsCharacter character = new StarWarsCharacter();
            character.name = record.get("name");
            character.height = record.get("height");
            character.mass = record.get("mass");
            character.hairColor = record.get("hair_color");
            character.skinColor = record.get("skin_color");
            character.eyeColor = record.get("eye_color");
            character.birthYear = record.get("birth_year");
            character.gender = record.get("gender");
            character.homeworld = record.get("homeworld");
            character.species = record.get("species");
            charactersList.add(character);
        }

        // Serialization of character list to JSON
        Gson gson = new Gson();
        Writer out = new FileWriter("characters.json");
        gson.toJson(charactersList, out);
        out.close();
    }
}
