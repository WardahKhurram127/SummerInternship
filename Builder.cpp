#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Builder pattern used to construct different configurations of a Computer object,
//including optional parts like GPU, SSD, and Water Cooling.

//The Product class represents the complex object under construction.
class Computer {
public:
    vector<string> components;

    void ListComponents() const {
        cout << "Computer configuration: ";
        for (size_t i = 0; i < components.size(); ++i) {
            cout << components[i];
            if (i != components.size() - 1)
                cout << ", ";
        }
        cout << "\n\n";
    }
};


//The Builder interface declares product construction steps.

class ComputerBuilder {
public:
    virtual ~ComputerBuilder() {}
    virtual void AddCPU() const = 0;
    virtual void AddGPU() const = 0;
    virtual void AddRAM() const = 0;
    virtual void AddSSD() const = 0;
    virtual void AddCoolingSystem() const = 0;
};


//The ConcreteBuilder builds and assembles parts of the product.

class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;

public:
    GamingComputerBuilder() {
        this->Reset();
    }

    ~GamingComputerBuilder() {
        delete computer;
    }

    void Reset() {
        this->computer = new Computer();
    }

    void AddCPU() const override {
        this->computer->components.push_back("High-End CPU");
    }

    void AddGPU() const override {
        this->computer->components.push_back("RTX GPU");
    }

    void AddRAM() const override {
        this->computer->components.push_back("32GB RAM");
    }

    void AddSSD() const override {
        this->computer->components.push_back("1TB SSD");
    }

    void AddCoolingSystem() const override {
        this->computer->components.push_back("Liquid Cooling");
    }

    Computer* GetComputer() {
        Computer* result = this->computer;
        this->Reset();
        return result;
    }
};


//The Director defines the order in which to call building steps.
class ComputerDirector {
private:
    ComputerBuilder* builder;

public:
    void SetBuilder(ComputerBuilder* builder) {
        this->builder = builder;
    }

    void BuildBasicPC() {
        builder->AddCPU();
        builder->AddRAM();
    }

    void BuildGamingPC() {
        builder->AddCPU();
        builder->AddGPU();
        builder->AddRAM();
        builder->AddSSD();
        builder->AddCoolingSystem();
    }
};


//Client code: uses the Director and Builder to construct objects.

void ClientDemo(ComputerDirector& director) {
    GamingComputerBuilder* builder = new GamingComputerBuilder();
    director.SetBuilder(builder);

    cout << "Basic PC:\n";
    director.BuildBasicPC();
    Computer* pc = builder->GetComputer();
    pc->ListComponents();
    delete pc;

    cout << "Gaming PC:\n";
    director.BuildGamingPC();
    pc = builder->GetComputer();
    pc->ListComponents();
    delete pc;

    cout << "Custom PC:\n";
    builder->AddCPU();
    builder->AddRAM();
    builder->AddSSD();
    pc = builder->GetComputer();
    pc->ListComponents();
    delete pc;

    delete builder;
}

int main() {
    ComputerDirector* director = new ComputerDirector();
    ClientDemo(*director);
    delete director;
    return 0;
}