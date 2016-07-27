/* Ship.cpp */
#include <iostream>
#include "Ship.h"
#include "Island.h"

using namespace std;

Ship::Ship(const std::string& name_, Point position_, double fuel_capacity_, 
           double maximum_speed_, double fuel_consumption_, int resistance_) : Sim_object(name_), Track_base(position_), fuel_capacity(fuel_capacity_), maximum_speed(maximum_speed_), fuel_consumption(fuel_consumption_), resistance(resistance_) {
    fuel = fuel_capacity_;
    ship_state = STOPPED;
    cout << "Creating Ship: " << get_name() << endl;
}


/*** Readers ***/
// Return true if ship can move (it is not dead in the water or in the process or sinking); 
bool Ship::can_move() const {

}
	
// Return true if ship is moving; 
bool Ship::is_moving() const {

}

// Return true if ship is docked; 
bool Ship::is_docked() const {

}
	
// Return true if ship is afloat (not in process of sinking), false if not
bool Ship::is_afloat() const {
}
		
// Return true if ship is on the bottom
bool Ship::is_on_the_bottom() const {

}
	
// Return true if Stopped and within 0.1 nm of the island
bool Ship::can_dock(Island* island_ptr) const {

}
	
/*** Interface to derived classes ***/
// Update the state of the Ship
void Ship::update() {

}

// output a description of current state to cout
void Ship::describe() const {
}
	
void Ship::broadcast_current_state() {
}
	
/*** Command functions ***/
// Start moving to a destination position at a speed
// may throw Error("Ship cannot move!")
// may throw Error("Ship cannot go that fast!")
void Ship::set_destination_position_and_speed(Point destination_position, double speed) {


}

// Start moving on a course and speed
// may throw Error("Ship cannot move!")
// may throw Error("Ship cannot go that fast!");
void Ship::set_course_and_speed(double course, double speed) {

}

// Stop moving
// may throw Error("Ship cannot move!");
void Ship::stop() {

}

// dock at an Island - set our position = Island's position, go into Docked state
// may throw Error("Can't dock!");
void Ship::dock(Island * island_ptr) {

}

// Refuel - must already be docked at an island; fill takes as much as possible
// may throw Error("Must be docked!");
void Ship::refuel() {

}

/*** Fat interface command functions ***/
// These functions throw an Error exception for this class
// will always throw Error("Cannot load at a destination!");
void Ship::set_load_destination(Island *) {

}

// will always throw Error("Cannot unload at a destination!");
void Ship::set_unload_destination(Island *) {

}

// will always throw Error("Cannot attack!");
void Ship::attack(Ship * in_target_ptr) {


}

// will always throw Error("Cannot attack!");
void Ship::stop_attack() {

}

// interactions with other objects
// receive a hit from an attacker
void Ship::receive_hit(int hit_force, Ship* attacker_ptr) {
}



/*
Define the destructor function even if it was declared as a pure virtual function.
This seems odd, because pure virtual functions are usually not defined in the class
that declares them. But this is often done as a way to make a class abstract, 
if there is no other virtual function that makes sense to mark as pure. Here we
are defining it just to get the destructor message output.
*/

Ship::~Ship()
{
	cout << "Ship "  << get_name() << " destructed" << endl;
}

/* Private Function Definitions */

/*
Calculate the new position of a ship based on how it is moving, its speed, and
fuel state. This function should be called only if the state is 
MOVING_TO_POSITION or MOVING_ON_COURSE.

Track_base has an update_position(double time) function that computes the new position
of an object after the specified time has elapsed. If the Ship is going to move
for a full time unit (one hour), then it will get go the "full step" distance,
so update_position would be called with time = 1.0. If we can move less than that,
e.g. due to not enough fuel, update position  will be called with the corresponding
time less than 1.0.

For clarity in specifying the computation, this code assumes the specified private variable names, 
but you may change the variable names or state names if you wish (e.g. movement_state).
*/
 
void Ship:: calculate_movement()
{
	// Compute values for how much we need to move, and how much we can, and how long we can,
	// given the fuel state, then decide what to do.
	double time = 1.0;	// "full step" time
	// get the distance to destination
	double destination_distance = cartesian_distance(get_location(), destination);
	// get full step distance we can move on this time step
	double full_distance = get_speed() * time;
	// get fuel required for full step distance
	double full_fuel_required = full_distance * fuel_consumption;	// tons = nm * tons/nm
	// how far and how long can we sail in this time period based on the fuel state?
	double distance_possible, time_possible;
	if(full_fuel_required <= fuel) {
		distance_possible = full_distance;
		time_possible = time;
		}
	else {
		distance_possible = fuel / fuel_consumption;	// nm = tons / tons/nm
		time_possible = (distance_possible / full_distance) * time;
		}
	
	// are we are moving to a destination, and is the destination within the distance possible?
	if(ship_state == MOVING_TO_POSITION && destination_distance <= distance_possible) {
		// yes, make our new position the destination
		set_position(destination);
		// we travel the destination distance, using that much fuel
		double fuel_required = destination_distance * fuel_consumption;
		fuel -= fuel_required;
		set_speed(0.);
		ship_state = STOPPED;
		}
	else {
		// go as far as we can, stay in the same movement state
		// simply move for the amount of time possible
		update_position(time_possible);
		// have we used up our fuel?
		if(full_fuel_required >= fuel) {
			fuel = 0.0;
			ship_state = DEAD_IN_THE_WATER;
			}
		else {
			fuel -= full_fuel_required;
			}
		}
}

