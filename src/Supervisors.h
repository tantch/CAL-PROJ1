/*
 * Supervisors.h
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#ifndef SUPERVISORS_H_
#define SUPERVISORS_H_

#include "People.h"


namespace std {

class Supervisors: public People {



public:
	Supervisors(int id, string name, int numMax,vector<int> prefOrder,vector<int> prefPrio);
	virtual ~Supervisors();

	string print(){
				string str = "Supervisor: " + getName();
				return str;

			}
};

} /* namespace std */

#endif /* SUPERVISORS_H_ */
