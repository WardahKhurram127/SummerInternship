#include <iostream>
#include <string>
using namespace std;

//This example models a GUI Factory for creating UI elements (like Buttons and Checkboxes) 
// for different operating systems (e.g., Windows and Mac).

//Product A
class Button {
public:
    virtual ~Button() {}
    virtual string Render() const = 0;
};

//Product B
class Checkbox {
public:
    virtual ~Checkbox() {}
    virtual string Render() const = 0;
};

//Concrete Product A1
class WindowsButton : public Button {
public:
    string Render() const override {
        return "Rendering a Windows Button.";
    }
};

//Concrete Product A2
class MacButton : public Button {
public:
    string Render() const override {
        return "Rendering a Mac Button.";
    }
};

//Concrete Product B1
class WindowsCheckbox : public Checkbox {
public:
    string Render() const override {
        return "Rendering a Windows Checkbox.";
    }
};

//Concrete Product B2
class MacCheckbox : public Checkbox {
public:
    string Render() const override {
        return "Rendering a Mac Checkbox.";
    }
};

//Abstract Factory
class GUIFactory {
public:
    virtual ~GUIFactory() {}
    virtual Button* CreateButton() const = 0;
    virtual Checkbox* CreateCheckbox() const = 0;
};

//Concrete Factory
class WindowsFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new WindowsButton();
    }

    Checkbox* CreateCheckbox() const override {
        return new WindowsCheckbox();
    }
};

//Concrete Factory 
class MacFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new MacButton();
    }

    Checkbox* CreateCheckbox() const override {
        return new MacCheckbox();
    }
};

void Application(const GUIFactory& factory) {
    Button* button = factory.CreateButton();
    Checkbox* checkbox = factory.CreateCheckbox();

    cout << button->Render() << "\n";
    cout << checkbox->Render() << "\n";

    delete button;
    delete checkbox;
}

int main() {
    cout << "Client: Windows GUI:\n";
    GUIFactory* windowsFactory = new WindowsFactory();
    Application(*windowsFactory);
    delete windowsFactory;

    cout << "\nClient: Mac GUI:\n";
    GUIFactory* macFactory = new MacFactory();
    Application(*macFactory);
    delete macFactory;

    return 0;
}
