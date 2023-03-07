class Polygon{
    public enum KindofPolygon { POLY_PLAIN, POLY_RECT, POLY_TRIANG };
    protected String name;
    protected float width;
    protected float height;
    protected KindofPolygon polytype;

    public Polygon(String theName, float theWidth, float theHeight){
        name = theName;
        width = theWidth;
        height = theHeight;
        polytype = KindofPolygon.POLY_PLAIN;
    }
    public KindofPolygon getPolytype(){
        return polytype;
    }
    public void setPolytype(KindofPolygon value){
        polytype = value;
    }
    public String getName(){ return name; }
    public float calArea(){ return 0; }
    public void printWidthHeight(){
        System.out.println("Width = " + width + " Height = " + height);
    }
}

class Rectangle extends Polygon{
    public Rectangle(String theName, float theWidth, float theHeight)
    { super(theName, theWidth, theHeight); polytype = KindofPolygon.POLY_RECT; }
    public float calArea(){ return width * height; }
}

class Triangle extends Polygon{
    public Triangle(String theName, float theWidth, float theHeight)
    { super(theName, theWidth, theHeight); polytype = KindofPolygon.POLY_TRIANG; }
    public float calArea(){ return width * height / 2; }
}

public class TestPolygon{
    public static void printArea(Polygon p){
        System.out.println("Area = " + p.calArea());
    }
    public static void main(String[] args){
        Polygon r = new Rectangle("r", 10, 20);
        Polygon t = new Triangle("t", 10, 20);
        printArea(r);
        printArea(t);
    }
}
