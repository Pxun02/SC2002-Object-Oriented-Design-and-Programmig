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
        virtual void move() const=0;
    private :
        string _name;
        COLOR _color ;
};

class Mammal : public Animal {
    public :
        Mammal(string n, COLOR c) : Animal(n, c) { }
        ~Mammal() {
        }

        void eat() const {
            cout << "Mammal eat " << endl;
        }
        void move() const {
            cout << "Move" << endl;
        }
    private :
        string _name;
        COLOR _color ;
};

class Dog : public Mammal {
    public : 
        Dog(string n, COLOR c, string o) : Mammal(n, c), _owner(o) {
            cout << "Owner of the Dog is: " << _owner << endl;
        }
        ~Dog() { }
        void speak() const {
            cout << "Woof" << endl;
        }
    private:
        string _name;
        COLOR _color;
        string _owner;
};

int main() {
    Dog dogi("Lassie", White, "Andy");
    Mammal *aniPtr = &dogi;
    Mammal &aniRef = dogi;
    Mammal aniVal = dogi;

    aniPtr->speak() ;
        aniRef.speak();
            aniVal.speak();
    cout << "Program exiting …. "<< endl ;
    return 0;
}