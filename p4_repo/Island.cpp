/* Island.cpp */

#include <iostream>
#include "Island.h"

Island::Island(const std::string& name_, Point position_, double fuel_ = 0., double production_rate_ = 0.) : Sim_object(name_), position(position_), fuel(fuel_), production_rate(production_rate_) {
    std::cout << "Creating Island: " << name << std::endl;
}

Island::~Island() {
    std::cout << "Destroying Island: " << name << std::endl;
}

double Island::provide_fuel(double request) {
    if (request < fuel) 
        fuel -= request;
    else {
        request = fuel;
        fuel = 0.;
    }
    std::cout << "Delivered fuel: " << request << std::endl;
    return request;
}

void Island::accept_fuel(double amount) {
    fuel += amount;
    std::cout << "Total amount of fuel: " << fuel << std::endl;
}

void Island::update() override {
    fuel += production_rate;
    std::cout << "Update Island, total amount of fuel: " << fuel << std::endl;
}

void Island::describe() const override {
    std::cout << "Island " << name << " state:" << endl;
    std::cout << "Position: ";

}


void Island::broadcast_current_state() override {
    
}
