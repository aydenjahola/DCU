/**
 * PointFactory.java
 * 
 * This file contains the implementation of the PointFactory class and related
 * interfaces.
 * The PointFactory class is responsible for creating Point objects and keeping
 * track of the number of points created.
 * The Point class represents a point in a Cartesian coordinate system and
 * implements the GridQuadrant and CompareQuadrant interfaces.
 * The GridQuadrant interface defines a method to get the quadrant of a point.
 * The CompareQuadrant interface defines a method to check if two points are in
 * the same quadrant.
 * The Quadrant enum represents the four quadrants of a Cartesian coordinate
 * system.
 * The main method in the PointFactory class demonstrates the usage of the
 * PointFactory and Point classes.
 * 
 * @author Ayden Jahola
 */

enum Quadrant {
    Q1, // x +ve, y +ve
    Q2, // x -ve, y +ve
    Q3, // x -ve, y -ve
    Q4; // x +ve, y -ve
}

interface GridQuadrant {
    Quadrant getQuadrant(); // Returns the quadrant of a point
}

interface CompareQuadrant {
    boolean isInSameQuadrant(Point point); // Checks if two points are in the same quadrant
}

class Point implements GridQuadrant, CompareQuadrant {
    private double x, y;

    public Point(double x, double y) {
        setX(x);
        setY(y);
    }

    // getters
    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    // setters
    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public Quadrant getQuadrant() {
        if (this.x > 0 && this.y > 0) {
            return Quadrant.Q1;
        } else if (this.x < 0 && this.y > 0) {
            return Quadrant.Q2;
        } else if (this.x < 0 && this.y < 0) {
            return Quadrant.Q3;
        } else if (this.x > 0 && this.y < 0) {
            return Quadrant.Q4;
        } else {
            return null;
        }
    }

    public boolean isInSameQuadrant(Point point) {
        if (this.getQuadrant() == point.getQuadrant()) {
            return true;
        } else {
            return false;
        }
    }
}

interface PointMaker {
    Point makePoint(double x, double y); // Creates a new Point object

    int countPointsCreated(); // Returns the number of points created
}

class PointFactory implements PointMaker {
    private int pointsCreated = 0;

    public Point makePoint(double x, double y) {
        pointsCreated++;
        return new Point(x, y);
    }

    public int countPointsCreated() {
        return pointsCreated;
    }

    public static void main(String args[]) {
        PointFactory factory = new PointFactory();

        Point point1 = factory.makePoint(0, 0);
        Point point2 = factory.makePoint(1, 1);
        Point point3 = factory.makePoint(-2, 2);
        Point point4 = factory.makePoint(-3, -3);
        Point point5 = factory.makePoint(4, -4);
        Point point6 = factory.makePoint(1, 1);

        System.out.println(point1.getQuadrant());
        System.out.println(point3.getQuadrant());
        System.out.println(point2.isInSameQuadrant(point4));
        System.out.println(point2.isInSameQuadrant(point6));
        System.out.println(factory.countPointsCreated());
    }
}