/*
 * Supervisors.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#include "Supervisors.h"

Supervisors::Supervisors(int id, string name, int numMax, vector<int> prefOrder,
		vector<int> prefPrio) {
	this->id = id;
	this->name = name;
	this->numMax = numMax;
	this->prefOrder = prefOrder;
	this->prefPrio = prefPrio;

}

Supervisors::~Supervisors() {
	// TODO Auto-generated destructor stub
}

