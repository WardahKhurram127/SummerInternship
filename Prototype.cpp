#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    virtual Person* clone() const = 0;
    virtual void display() const = 0;
    virtual ~Person() {}
};

// Concrete Prototype
class Employee : public Person {
private:
    string name;
    int age;

public:
    Employee(string name, int age) : name(name), age(age) {}

    Person* clone() const override {
        return new Employee(*this); // Use copy constructor
    }

    void display() const override {
        cout << "Employee: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Employee original("Alice", 30);
    cout << "Original:\n";
    original.display();

    Person* copy = original.clone();
    cout << "\nCloned:\n";
    copy->display();

    delete copy;
    return 0;
}
