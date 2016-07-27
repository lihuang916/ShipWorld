/* Sim_object.cpp */

#include <iostream>
#include "Sim_object.h"


Sim_object::Sim_object(const std::string& name_) {
    name = name_;
    std::cout << "Creating object: " << name << std::endl;
}

Sim_object::~Sim_object() {
    std::cout << "Destroying object: " << name << std::endl;
}
