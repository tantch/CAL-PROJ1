/*
 * People.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#include "People.h"

People::People(int id, string name, vector<int> prefOrder,
		vector<int> prefPrio) {
	this->id = id;
	this->name = name;
	this->prefOrder = prefOrder;
	this->prefPrio = prefPrio;
	this->numMax=1;

}
People::People() {
	this->id = 0;
	this->name = ",";
	this->numMax=1;
}

People::~People() {
	// TODO Auto-generated destructor stub
}

bool People::operator==(const People & p) {
	if (id == p.id)
		return true;
	else
		return false;
}
string People::print(){

	return name;
}
