/*
 * Students.h
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_

#include "People.h"

class Students: public People {
public:
	Students(int id,string name,vector<int> prefOrder,vector<int> prefPrio);
	virtual ~Students();
	string print(){
		string str = "Student: " + getName();
		return str;

		}

};

#endif /* STUDENTS_H_ */
