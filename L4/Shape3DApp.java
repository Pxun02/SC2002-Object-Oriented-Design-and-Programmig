class Cubiod extends Rectangle{
    private double length;
    private double breadth;
    public Cubiod(double length, double breadth){
        super(length, breadth);
        this.length = length;
        this.breadth = breadth;
    }
    public double area(){ return 2*(length*breadth + length*breadth + breadth*breadth); }
}

class Sphere extends Circle{
    private double radius;
    public Sphere(double radius){ super(radius); this.radius = radius; }
    public double area(){ return 4*Math.PI*Math.pow(radius, 2); }
}

class Pyramid extends Triangle{
    private double base;
    private double height;
    public Pyramid(double base, double height){
        super(base, height);
        this.base = base;
        this.height = height;
    }
    public double area(){ return base * height * 2 + base * base; }
}

class Cone extends Triangle{
    private double base;
    private double height;
    public Cone(double base, double height){
        super(base, height);
        this.base = base;
        this.height = height;
    }
    public double area(){ return Math.PI * Math.pow(0.5*base, 2) * height; }
}

class Cylinder extends Rectangle{
    private double length;
    private double breadth;
    public Cylinder(double length, double breadth){
        super(length, breadth);
        this.length = length;
        this.breadth = breadth;
    }
    public double area(){ return Math.PI * Math.pow(0.5*breadth, 2)*length; } 
}

public class Shape3DApp{
    public static void main(String[] args){
        Sphere s = new Sphere(10);
        Pyramid p = new Pyramid(20, 25);
        Cubiod cu = new Cubiod(50, 20);
        double tot2 = s.area() + p.area() + cu.area();
        System.out.println("Total Area for the second shape is: " + tot2);

        Cone cn = new Cone(20, 25);
        Cylinder cy = new Cylinder(50, 20);
        double tot3 = s.area() + cn.area() + cy.area();
        System.out.println("Total Area for the third shape is: " + tot3);
    }
}
