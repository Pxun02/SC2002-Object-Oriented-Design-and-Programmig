
interface Shape{
    public double area();
    public void printArea();
}

class Square implements Shape{
    private double side;
    public Square(double side){
        setSide(side);
    }
    public void setSide(double side){ this.side = side; }
    public double getSide(){ return side; }
    public double area(){ return side * side; }
    public void printArea(){
        System.out.println("Area of rectangle");
        System.out.println("Side: " + side);
        System.out.println("Area: " + area());
    }
}

class Rectangle implements Shape{
    private double length;
    private double breadth;
    public Rectangle(double length, double breadth){
        setLength(length);
        setBreadth(breadth);
    }
    public void setLength(double length){ this.length = length; }
    public void setBreadth(double breadth){ this.breadth = breadth;}
    public double getLength(){ return length; }
    public double getBreadth(){ return breadth; }
    public double area(){ return length*breadth; }
    public void printArea(){
        System.out.println("Area of rectangle");
        System.out.println("Length: " + length);
        System.out.println("Breadth: " + breadth);
        System.out.println("Area: " + area());
    }
}

class Circle implements Shape{
    private double radius;
    private static final double PI = 3.14159;
    public Circle(double radius){ setRadius(radius); }
    public void setRadius(double radius){ this.radius = radius; }
    public double getRadius(){ return radius; }
    public double area(){ return Math.PI*Math.pow(radius, 2); }
    public double circumference(){ return 2*PI*radius; }
    public void printArea(){
        System.out.println("Area of circle");
        System.out.println("Radius: " + radius);
        System.out.println("Area: " + area());
    }
    public void printCircumference(){
        System.out.println("Circumference pf circle");
        System.out.println("Radius: " + radius);
        System.out.println("Circumference: " + circumference());
    }
}

class Triangle implements Shape{
    private double base;
    private double height;
    public Triangle(double base, double height){
        setBase(base);
        setHeight(height);
    }
    public void setBase(double base){ this.base = base; }
    public void setHeight(double height){ this.height = height; }
    public double getBase(){ return base; }
    public double getHeihgt(){ return height; }
    public double area(){ return base * height * 0.5; }
    public void printArea(){
        System.out.println("Area of triangle");
        System.out.println("Base: " + base);
        System.out.println("Height: " + height);
        System.out.println("Area: " + area());
    }
}

public class Shape2DApp{
    public static void main(String[] args){
        Circle c = new Circle(10);
        Triangle t = new Triangle(20, 25);
        Rectangle r = new Rectangle(50, 20);
        double tot = c.area() + t.area() + r.area();
        System.out.println("Total Area is: " + tot);
    }
}