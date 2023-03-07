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
            cout << "constructing Animal object "<< _name << endl ;
            cout << "Color of the object is: "<< _color << endl ;
        }
        ~Animal() {
            cout << "destructing Animal object "<< _name << endl ;
        }
        virtual void speak() const {
        cout << "Animal speaks "<< endl ;
        }
        virtual void move() const {
            cout << "Animal moves " << endl;
        };
    private :
        string _name;
        COLOR _color ;
};

class Mammal : public Animal {
    public :
        Mammal() {}
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
        void move() const {
            cout << "Dog Move" << endl;
        }
    private:
        string _name;
        COLOR _color;
        string _owner;
};

class Cat : public Mammal {
    public :
        Cat(string n, COLOR c, string o) : Mammal(n, c), _owner(o) {
            cout << "Owner of the Cat is: " << _owner << endl;
        }
        ~Cat() {}
        void speak() const {
            cout << "Meow" << endl;
        }
        void move() const {
            cout << "Cat moves" << endl;
        }
    
    private :
        string _name;
        COLOR _color;
        string _owner;
};

class Lion : public Mammal {
    public :
        Lion(string n, COLOR c, string o) : Mammal(n, c), _owner(o) {
            cout << "Owner of the Lion is: " << _owner << endl;
        }
        ~Lion() { }
        void speak() const {
            cout << "Roar" << endl;
        }
        void move() const {
            cout << "Lion moves" << endl;
        }
    
    private :
        string _name;
        COLOR _color;
        string _owner;
};

int main() {
    Mammal *select[10];
    int i = 0; 
    int inp;
    bool br = false;
    Dog D("John", Black, "Piel");
    Cat C("Lassie", White, "Andy");
    Lion L("Charie", Brown, "Angerica");
    while(!br){
    cout << "Select the animal send to Zoo :\n(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit" << endl;
    cin >> inp;
    switch(inp){
        case(1):{
            select[i] = &D;
            i++;
            break;
        }
        case(2):{
            select[i] = &C;
            i++;
            break;
        }
        case(3):{
            select[i] = &L;
            i++;
            break;
        }
        case(4):{
            for(int j=0;j<i;j++){
                Mammal* tmp = select[j];
                tmp->move();
                tmp->speak();
                tmp->eat();
            }
            break;
        }
        default:{
            br = true;
            break;
        }
    }
    }
    cout << "Program exiting …. "<< endl ;
    return 0;
}