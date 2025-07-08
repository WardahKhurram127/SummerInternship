#include <iostream>
#include <string>
using namespace std;

//Imagine a logistics application that needs to handle different modes of transport. 
// Instead of using conditionals throughout the code to decide which transport to use, 
// we apply the Factory Method to delegate the decision to subclasses.


//Product interface
class Transport {
public:
	virtual ~Transport() {}
	virtual string deliver() const = 0;
};

//Concrete products
class Truck : public Transport {
public:
	string deliver() const override {
		return "Deliver by land in a truck";
	}
};

class Ship : public Transport {
public:
	string deliver() const override {
		return "Deliver by sea in a ship";
	}
};

//The Creator class declares the factory method, which returns an object of the Transport class.
class Logistics {
public:
	virtual ~Logistics() {}
	//It returns a Transport* — an object that implements the Transport interface.
	virtual Transport* createTransport() const = 0;
	string plan_delivery() const {
		Transport* transport = this->createTransport();
		string result = "Logistics: " + transport->deliver();
		delete transport;
		return result;
	}
};

class RoadLogistics : public Logistics {
	Transport* createTransport() const override {
		return new Truck();
	}
};

class SeaLogistics : public Logistics {
	Transport* createTransport() const override {
		return new Ship();
	}
};

void ClientCode(const Logistics& logistics) {
	cout << logistics.plan_delivery() << std::endl;
}

int main()
{
	cout << "App: Launched with RoadLogistics.\n";
	Logistics* road = new RoadLogistics();
	ClientCode(*road);
	cout << "\nApp: Launched with SeaLogistics.\n";
	Logistics* sea = new SeaLogistics();
	ClientCode(*sea);
	delete road;
	delete sea;
	return 0;
}