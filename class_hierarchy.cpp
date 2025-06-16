//Animal Kingdom Hierarchy (Basic Inheritance)

/*+---------------------+
|      Animal         |
+---------------------+
| # name: string      |
| # age: int          |
+---------------------+
| + makeSound(): virtual void |
| + displayInfo(): virtual void |
+---------------------+
        ^
        |
+-------+-------+
|               |
v               v
+-------------+ +-------------+
|    Mammal   | |     Bird    |
+-------------+ +-------------+
| - furColor: string | - canFly: bool |
+-------------+ +-------------+
        ^               ^
        |               |
+-------+-------+ +-----+-----+
|               | |           |
v               v v           v
+-------------+ +-------------+ +-------------+
|     Dog     | |     Cat     | |    Eagle    |
+-------------+ +-------------+ +-------------+
| + bark()    | | + meow()    | | + soar()    |
+-------------+ +-------------+ +-------------+*/


#include <iostream>
#include <string>
using namespace std;

//Base class
class Animal
{

protected:
    string name;
    int age;

public:
    Animal(string n,int a):name(n),age(a){}

    virtual void makeSound() const {
         cout << "Some generic animal sound" << endl;

    }

    virtual void displayInfo() const {
         cout << "Name: " << name << "\nAge: " << age << " years" << endl;

    }
    virtual ~Animal(){}

};

// Intermediate level - Mammal

class Mammal : public Animal
{

    protected:
    string furcolor;

    public:
    Mammal(string n,int a, string color):Animal(n,a),furcolor(color){}
    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Fur color: " << furcolor << endl;
    }


};

// Intermediate level - Bird
class Bird : public Animal {
protected:
    bool canFly;

public:
    Bird(string n, int a, bool fly) 
        : Animal(n, a), canFly(fly) {}
        
    void displayInfo() const override {
        Animal::displayInfo();
        cout << "Can fly: " << (canFly ? "Yes" : "No") << endl;
    }
};

// Concrete classes - Dog
class Dog : public Mammal {
public:
    Dog(string n, int a, string color) 
        : Mammal(n, a, color) {}
        
    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }
    
    void bark() const {
        cout << name << " is barking loudly!" << endl;
    }
};

// Concrete classes - Cat
class Cat : public Mammal {
public:
    Cat(string n, int a, string color) 
        : Mammal(n, a, color) {}
        
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
    
    void meow() const {
        cout << name << " says meow softly" << endl;
    }
};

// Concrete classes - Eagle
class Eagle : public Bird {
public:
    Eagle(string n, int a, bool fly = true) 
        : Bird(n, a, fly) {}
        
    void makeSound() const override {
        cout << "Screech!" << endl;
    }
    
    void soar() const {
        if (canFly) {
            cout << name << " is soaring high in the sky!" << endl;
        } else {
            cout << name << " cannot fly" << endl;
        }
    }
};

// int main() {
//     Dog dog("Buddy", 3, "Golden");
//     Cat cat("Whiskers", 2, "Gray");
//     Eagle eagle("Sky", 5);
    
//     Animal* animals[] = {&dog, &cat, &eagle};
    
//     cout << "=== Animal Sounds ===" << endl;
//     for (Animal* animal : animals) {
//         animal->makeSound(); // Polymorphic call
//     }
    
//     cout << "\n=== Animal Information ===" << endl;
//     dog.displayInfo();
//     cat.displayInfo();
//     eagle.displayInfo();
    
//     cout << "\n=== Specific Behaviors ===" << endl;
//     dog.bark();
//     cat.meow();
//     eagle.soar();
// }