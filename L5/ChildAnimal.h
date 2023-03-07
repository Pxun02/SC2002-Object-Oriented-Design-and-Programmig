using namespace animal;\
namespace childAnimal{
class Dog : public Mammal {
    public : 
        Dog(string n, COLOR c, string o);
        ~Dog();
        void speak() const;
        void move() const;
    private:
        std::string _name;
        COLOR _color;
        std::string _owner;
};
class Cat : public Mammal {
    public :
        Cat(string n, COLOR c, string o);
        ~Cat();
        void speak() const;
        void move() const;
    
    private :
        std::string _name;
        COLOR _color;
        std::string _owner;
};
class Lion : public Mammal {
    public :
        Lion(string n, COLOR c, string o);
        ~Lion();
        void speak() const;
        void move() const;
    
    private :
        std::string _name;
        COLOR _color;
        std::string _owner;
};
}
