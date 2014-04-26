/*
 * ProjResp.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#include "ProjResp.h"

ProjResp::ProjResp(int id, string name, string projName, vector<int> prefOrder,
		vector<int> prefPrio) {
	this->id = id;
	this->name = name;
	this->projName = projName;
	this->prefOrder = prefOrder;
	this->prefPrio = prefPrio;
}

ProjResp::~ProjResp() {
	// TODO Auto-generated destructor stub
}

