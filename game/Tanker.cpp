/* Tanker.cpp */

#include <iostream>
#include "Tanker.h"

using namespace std;

Tanker::Tanker(const std::string& name_, Point position_) : Ship(name_, position_, 100., 10., 2., 0), cargo_capacity(100), cargo(0) {
    cout << "Creating Tanker: " << get_name() << endl;
}

Tanker::~Tanker() {
    cout << "Destroying Tanker: " << get_name() << endl;
}

void Tanker::set_destination_position_and_speed(Point destination, double speed) {
    
}

void Tanker::set_course_and_speed(double course, double speed) {

}

// Set the loading and unloading Island destinations
// if both cargo destination are already set, throw Error("Tanker has cargo destinations!").
// if they are the same, leave at the set values, and throw Error("Load and unload cargo destinations are the same!")
// if both destinations are now set, start the cargo cycle
void Tanker::set_load_destination(Island* I) {

}

void Tanker::set_unload_destination(Island* I) {

}
	
// when told to stop, clear the cargo destinations and stop
void Tanker::stop() {
    
}
	
void Tanker::update() {

}

void Tanker::describe() const {
    cout << "Tanker " << get_name() << ":" << endl;
    cout << "Cargo: " << cargo << endl;
    cout << "Load destination: " << endl;
    cout << "Unload destination: " << endl;
}


