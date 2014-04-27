/*
 * Students.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#include "Students.h"

Students::Students(int id, string name, vector<int> prefOrder,
		vector<int> prefPrio) {
	this->id = id;
	this->name = name;
	this->prefOrder = prefOrder;
	this->prefPrio = prefPrio;
	this->numMax=1;
}

Students::~Students() {
	// TODO Auto-generated destructor stub
}

