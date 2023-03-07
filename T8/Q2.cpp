#include <iostream>
using namespace std;

enum KindofPolygon{ POLY_PLAIN, POLY_RECT, POLY_TRIANGLE };
class Polygon{
    public:
        Polygon(string theName, float theWidth, float theHeight) : name(theName), width(theWidth), height(theHeight), polytype(POLY_PLAIN){}
        ~Polygon() {}
        virtual float calArea()=0;
        virtual void printArea()=0;
    protected:
        string name;
        float width;
        float height;
        KindofPolygon polytype;
};

class Rectangle : public Polygon{
    public:
        Rectangle(string theName, float theWidth, float theHeight) : Polygon(theName, theWidth, theHeight), width(theWidth), height(theHeight){}
        ~Rectangle(){}
        float calArea(){ return width * height; }
        void printArea(){ cout << calArea() << endl; }
    private:
        string name;
        float width;
        float height;
        KindofPolygon polytype;
};

class Triangle : public Polygon {
    public:
        Triangle(string theName, float theWidth, float theHeight) : Polygon(theName, theWidth, theHeight), width(theWidth), height(theHeight){}
        ~Triangle(){}
        float calArea(){ return 0.5 * width * height; }
        void printArea(){ cout << calArea() << endl; }
    private:
        string name;
        float width;
        float height;
        KindofPolygon polytype;
};

int main(){
    Rectangle r("r1", 20, 10);
    Triangle t("t1", 20, 10);
    r.printArea();
    t.printArea();
}