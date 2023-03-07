enum COLOR { Green, Blue, White, Black, Brown } ;
using namespace std;
namespace animal{
class Animal {
    public :
        Animal();
        Animal(string n, COLOR c);
        ~Animal();
        virtual void speak() const;
        virtual void move() const=0;
    private :
        std::string _name;
        COLOR _color ;
};
class Mammal : public Animal {
    public :
        Mammal();
        Mammal(string n, COLOR c);
        ~Mammal();
        void eat() const;
        void move() const;
    private :
        std::string _name;
        COLOR _color ;
};

}
