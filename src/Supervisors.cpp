/*
 * Supervisors.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#include "Supervisors.h"

namespace std {

Supervisors::Supervisors(int id, string name, int numMax) {
	this->id = id;
	this->name=name;
	this->numMax=numMax;

}

Supervisors::~Supervisors() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
