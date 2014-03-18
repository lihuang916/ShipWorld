/* Controller.cpp */

#include <iostream>
#include "Controller.h"
#include "Model.h"

using namespace std;
Controller::Controller() {
    cout << "Controller created" << endl;
}

Controller::~Controller() {
    cout << "Controller destroyed" << endl;
}

void Controller::run() {
    string input;
    while (true) {
        cout << "Please enter command" << endl;
        cin >> input;
        if (input == "update") 
            g_Model_ptr->update();
        else if (input == "describe")
            g_Model_ptr->describe();
        else if (input == "exit")
            break;
    }
}
