/*
 * main.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: pim
 */

#include "People.h"
#include "Students.h"
#include "Supervisors.h"
#include "ProjResp.h"
#include "Graph.h"
#include <iostream>

int main() {

	//create students

	vector<int>* tempPrio = new vector<int>();
	vector<int>* tempOrder = new vector<int>();
	tempOrder->push_back(1);
	tempOrder->push_back(2);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	tempPrio->push_back(3);

	Students* e1 = new Students(1, "E1", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(3);
	tempOrder->push_back(5);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	tempPrio->push_back(3);

	Students* e2 = new Students(2, "E2", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	tempPrio->push_back(3);

	Students* e3 = new Students(3, "E3", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempOrder->push_back(5);
	tempPrio->push_back(3);
	tempPrio->push_back(1);
	Students* e4 = new Students(4, "E4", *tempOrder, *tempPrio);

	//set Projects
	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(2);
	tempOrder->push_back(3);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	tempPrio->push_back(3);
	ProjResp* p1 = new ProjResp(1, "PR1", "P1", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempPrio->push_back(1);
	ProjResp* p2 = new ProjResp(2, "PR2", "P2", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(2);
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempPrio->push_back(2);
	tempPrio->push_back(3);
	tempPrio->push_back(1);
	ProjResp* p3 = new ProjResp(3, "PR3", "P3", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(3);
	tempPrio->push_back(2);
	ProjResp* p4 = new ProjResp(4, "PR4", "P4", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(2);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	ProjResp* p5 = new ProjResp(5, "PR5", "P5", *tempOrder, *tempPrio);
	//setSupervisors

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	tempPrio->push_back(3);
	Supervisors* s1 = new Supervisors(1, "S1", 2, *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(4);
	tempOrder->push_back(5);
	tempPrio->push_back(2);
	tempPrio->push_back(3);
	tempPrio->push_back(1);
	Supervisors* s2 = new Supervisors(2, "S2", 1, *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempOrder->push_back(5);
	tempPrio->push_back(3);
	tempPrio->push_back(2);
	tempPrio->push_back(1);
	Supervisors* s3 = new Supervisors(3, "S3", 2, *tempOrder, *tempPrio);

	//set to vertex and edges

	Graph<People> hungGraph();


	return 0;
}
