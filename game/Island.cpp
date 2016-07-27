/* Island.cpp */

#include <iostream>
#include "Island.h"

Island::Island(const std::string& name_, Point position_, double fuel_, double production_rate_) : Sim_object(name_), position(position_), fuel(fuel_), production_rate(production_rate_) {
    std::cout << "Creating Island: " << get_name() << std::endl;
}

Island::~Island() {
    std::cout << "Destroying Island: " << get_name() << std::endl;
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

void Island::update() {
    fuel += production_rate;
    std::cout << "Update Island, total amount of fuel: " << fuel << std::endl;
}

void Island::describe() const {
    std::cout << "Island " << get_name() << " state:" << std::endl;
    std::cout << "Position: (" << position.x << ", " << position.y << ")" << std::endl;
    std::cout << "Fuel: " << fuel << std::endl;
    std::cout << "Production rate: " << production_rate << std::endl;
}

void Island::broadcast_current_state() {
    //g_Model_ptr->notify_location(get_name(), position);
}
