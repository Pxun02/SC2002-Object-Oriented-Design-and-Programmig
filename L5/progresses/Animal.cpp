#include <iostream>
#include <string>

using namespace std ;

enum COLOR { Green, Blue, White, Black, Brown } ;

class Animal {
    public :
        Animal() : _name("unknown") {
            cout << "constructing Animal object "<< _name << endl ;
        }
        Animal(string n, COLOR c) : _name(n), _color(c){
            /*auto c_str = 
                std::meta::get_base_name_v<
                    std::meta::get_element_m<
                        std::meta::get_enumerators_m<reflexpr(COLOR)>,
                        0>
                    >;
*/
            cout << "constructing Animal object "<< _name << endl ;
            cout << "Color of the object is: "<< _color << endl ;
        }
        ~Animal() {
            cout << "destructing Animal object "<< _name << endl ;
        }
        void speak() const {
        cout << "Animal speaks "<< endl ;
        }
        void move() const { }
    private :
        string _name;
        COLOR _color ;
};

int main() {
    Animal a("Dog", White);
    a.speak() ;
    cout << "Program exiting …. "<< endl ;
    return 0;
}