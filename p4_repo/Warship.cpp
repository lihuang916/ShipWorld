/* Warship.cpp */

#include <iostream>
#include "Warship.h"

using namespace std;

Warship::Warship(const std::string& name_, Point position_, double fuel_capacity_, double maximum_speed_, double fuel_consumption_, int resistance_, int firepower_, double maximum_range_) : Ship(name_, position_, fuel_capacity_, maximum_speed_, fuel_consumption_, resistance_), firepower(firepower_), maximum_range(maximum_range_) {
    cout << "Creating Warship: " << get_name() << endl;
}

Warship::~Warship() {
    cout << "Destroying Warship: " << get_name() << endl;
}
// perform warship-specific behavior
void Warship::update() {

}

// Warships will act on an attack and stop_attack command

// will	throw Error("Cannot attack!") if not Afloat
// will throw Error("Warship may not attack itself!")
// if supplied target is the same as this Warship
void Warship::attack(Ship* target_ptr_) {

}

// will throw Error("Was not attacking!") if not Attacking
void Warship::stop_attack() {

}
	
void Warship::describe() const {


}

