#include <iostream>
using namespace std;
class A {
    protected :
        int a,b;
    public :
        A(int x, int y) { // rightmost for default value
            a = x ;
            b = y ;
        }
        virtual void print() ;
        friend int doubleIt(A a); // use ‘friend’ to show, but not gd practice
        A operator+(A op){
            int _x = a + op.a;
            int _y = b + op.b;
            return (A(_x, _y)); 
        }
};
class B: public A {
    private:
        float p,q ;
    public :
        B(int m, int n, float u, float v) : A(m,n) {
            p = u ;
            q = v ;
        }
        B() : A(0,0) { p = q = 0 ; }
        void input(float u, float v) ;
        virtual void print(float) ;
};
void A::print(void) {
    cout << "A values: " << a << " " << b << "\n" ;
}
void B::print(float) {
    cout << "B values : " << p << " " << q << "\n" ;
}
void B::input(float x, float y) {
    p = x ; q = y ;
}
int doubleIt(A a) { return a.a * a.a ; } // ref to top
int main() {
    A a1(10,20), *ptr ;
    B b1;
    b1.input(7.5, 3.142) ;
    ptr = &a1 ;
    ptr->print() ;
    ptr = &b1;
    ptr->print() ;
}