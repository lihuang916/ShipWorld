/* Cruiser.cpp */

#include <iostream>
#include "Cruiser.h"

using namespace std;
Cruiser::Cruiser(const string& name_, Point position_) : Warship(name_, position_, 1000., 20., 10., 6, 3, 15.) {
    cout << "Creating Cruiser: " << get_name() << endl; 
}

Cruiser::~Cruiser() {
    cout << "Destroying Cruiser: " << get_name() << endl;
}

void Cruiser::update() {

}

void Cruiser::describe() const {
    Ship::describe();
    cout << "Cruiser " << get_name() << ":" << endl;
    cout << "firepower: " << firepower << endl;
    cout << "maximum range: " << maximum_range << endl;
}

void Cruiser::receive_hit(int hit_force, Ship* attacker_ptr) {

}
