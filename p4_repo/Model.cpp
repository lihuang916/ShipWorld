/* Model.cpp */
/* create some islands and ships using the following code in the Model constructor.
Do not change the execution order of these code fragments. You should delete this comment. */

#include <iostream>
#include "Model.h"
#include "Sim_object.h"
#include "Island.h"
#include "Ship.h"
#include "Ship_factory.h"

Model* g_Model_ptr = nullptr;

using namespace std;

Model::Model() {
	islands.push_back(new Island("Exxon", Point(10, 10), 1000, 200));
	islands.push_back(new Island("Shell", Point(0, 30), 1000, 200));
	islands.push_back(new Island("Bermuda", Point(20, 20)));
	
	ships.push_back(create_ship("Ajax", "Cruiser", Point (15, 15)));
	ships.push_back(create_ship("Xerxes", "Cruiser", Point (25, 25)));
	ships.push_back(create_ship("Valdez", "Tanker", Point (30, 30)));
    
    for (auto &obj : islands)
        all_objects.push_back(obj);
    for (auto &obj : ships)
        all_objects.push_back(obj);

	cout << "Model constructed" << endl;
}

Model::~Model() {
    for (auto &obj : all_objects)
        delete obj;
    cout << "Model destroyed" << endl;
}

void Model::describe() const {
    for (auto &obj : all_objects)
        obj->describe();
}

void Model::update() {
    time += 1;
    for (auto &obj : all_objects)
        obj->update();
}
