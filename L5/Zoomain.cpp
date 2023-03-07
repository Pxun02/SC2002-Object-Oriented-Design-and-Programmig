#include <iostream>
#include <string>
#include "Animal.h"
#include "ChildAnimal.h"

using namespace animal;
using namespace childAnimal;
using namespace std;

Animal::Animal() : _name("unknown") {
    cout << "constructing Animal object "<< _name << endl ;
}
Animal::Animal(string n, COLOR c) : _name(n), _color(c){
    cout << "constructing Animal object "<< _name << endl ;
    cout << "Color of the object is: "<< _color << endl ;
}       

Animal::~Animal() {
    cout << "destructing Animal object "<< _name << endl ;
}

Mammal::Mammal() {}
Mammal::Mammal(string n, COLOR c) : Animal(n, c) { }
Mammal::~Mammal() { }

Dog::Dog(string n, COLOR c, string o) : Mammal(n, c), _owner(o) {
    cout << "Owner of the Dog is: " << _owner << endl;
}
Dog::~Dog(){}

Cat::Cat(string n, COLOR c, string o) : Mammal(n, c), _owner(o) {
    cout << "Owner of the Cat is: " << _owner << endl;
}
Cat::~Cat(){}

Lion::Lion(string n, COLOR c, string o) : Mammal(n, c), _owner(o) {
    cout << "Owner of the Lion is: " << _owner << endl;
}
Lion::~Lion(){}

void Animal::speak() const {
    cout << "Animal speaks "<< endl ;
}

void Mammal::eat() const {
    cout << "Mammal eat " << endl;
}
void Mammal::move() const {
    cout << "Move" << endl;
}
void Dog::speak() const {
    cout << "Woof" << endl;
}
void Dog::move() const {
    cout << "Dog moves" << endl;
}

void Cat::speak() const {
    cout << "Meow" << endl;
}
void Cat::move() const {
    cout << "Cat moves" << endl;
}

void Lion::speak() const {
    cout << "Roar" << endl;
}
void Lion::move() const {
    cout << "Lion moves" << endl;
}

int main() {
    animal::Mammal *select[10];
    childAnimal::Dog D("John", Black, "Piel");
    childAnimal::Cat C("Lassie", White, "Andy");
    childAnimal::Lion L("Charie", Brown, "Angerica");
    int i = 0; 
    int inp;
    bool br = false;
    while(!br){
    std::cout << "Select the animal send to Zoo :\n(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit" << endl;
    cin >> inp;
    switch(inp){
        case(1):{
            select[i] = &D;
            select[i]->move();
            select[i]->speak();
            select[i]->eat();
            i++;
            break;
        }
        case(2):{
            select[i] = &C;
            select[i]->move();
            select[i]->speak();
            select[i]->eat();
            i++;
            break;
        }
        case(3):{
            select[i] = &L;
            select[i]->move();
            select[i]->speak();
            select[i]->eat();
            i++;
            break;
        }
        case(4):{
            for(int j=0;j<i;j++){
                select[j]->move();
                select[j]->speak();
                select[j]->eat();
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