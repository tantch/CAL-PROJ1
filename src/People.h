/*
 * People.h
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_
#include <string>
using namespace std;
class People {

	string name;
	int id;

public:
	People(int id,string name);
	virtual ~People();
};

#endif /* PEOPLE_H_ */
