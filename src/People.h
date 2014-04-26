/*
 * People.h
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_
#include <string>
#include <vector>
using namespace std;
class People {
protected:
	string name;
	int id;
	vector<int> prefOrder;
	vector<int> prefPrio;
public:
	People();
	People(int id,string name,vector<int> prefOrder,vector<int> prefPrio);
	virtual ~People();
	string getName(){
		return name;
	}
	int getId(){
		return id;
	}
	vector<int> getPrefOrder(){
		return prefOrder;
	}
	vector<int> getPrefPrio(){
		return prefPrio;
	}

	string print(){	}

	bool operator==(const People & p);
};


#endif /* PEOPLE_H_ */
