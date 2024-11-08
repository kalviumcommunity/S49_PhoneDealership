#include <iostream>
#include <string>
using namespace std;

#include "Phone.cpp"  // Include the Phone class and derived classes

class Customer {
private:
    string customerID;
    string name;
    Phone* ownedPhone;  // Pointer to base class Phone to support polymorphism

public:
    Customer(string id, string n, Phone* phone) : customerID(id), name(n), ownedPhone(phone) {
        cout << "Customer constructor called for " << name << endl;
    }

    ~Customer() {
        delete ownedPhone;  // Free allocated memory
        cout << "Destructor called for Customer: " << name << endl;
    }

    void displayCustomerDetails() const {
        cout << "Customer ID: " << customerID << ", Name: " << name << endl;
        cout << "Owned Phone Details:" << endl;
        ownedPhone->display();  // Runtime polymorphism in action
    }
};
