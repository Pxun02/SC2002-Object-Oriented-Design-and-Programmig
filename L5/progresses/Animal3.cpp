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
        virtual void speak() const {
        cout << "Animal speaks "<< endl ;
        }
        void move() const { }
    private :
        string _name;
        COLOR _color ;
};

class Mammal : public Animal {
    public :
        Mammal() : _name("unknown") {
            cout << "constructing Mammal object" << _name << endl;
        }
        Mammal(string n, COLOR c) : Animal(n, c) {
            cout << "constructing Mammal object" << _name << endl;
            cout << "Color of the Mammal is: " << _color << endl;
        }
        ~Mammal() {
            cout << "destructing Mammal object " << _name << endl;
        }

        void eat() const {
            cout << "Mammal eat " << endl;
        }
    private :
        string _name;
        COLOR _color ;
};

class Dog : Mammal {
    public : 
        Dog(string n, COLOR c, string o) : Mammal(n, c), _owner(o) {
            cout << "constructing Dog object" << _name << endl;
            cout << "Color of the Dog is: " << _color << endl;
            cout << "Owner of the Dog is: " << _owner << endl;
        }
        ~Dog() {
            cout << "destructing Dog object " << _name << endl;
        }
        void speak() const {
            cout << "Woof" << endl;
        }
    private:
        string _name;
        COLOR _color;
        string _owner;
};

int main() {
    Dog d("John", White, "Jane");
    d.speak();
    cout << "Program exiting …. "<< endl ;
    return 0;
}