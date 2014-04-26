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
#include <vector>

vector<Students *> students;
vector<ProjResp *> projects;
vector<Supervisors *> supervisors;
Graph<People>* stableGraph;

void setGraph() {
	stableGraph = new Graph<People>();
	stableGraph->setProjectsN(projects.size());
	stableGraph->setStudentsN(students.size());
	stableGraph->setSupervisorsN(supervisors.size());

	for (int i = 0; i++; i < students.size()) {
		stableGraph->addVertex(*students[i]);

	}
	for (int i = 0; i++; i < projects.size()) {
		stableGraph->addVertex(*projects[i]);
	}
	for (int i = 0; i++; i < supervisors.size()) {
		stableGraph->addVertex(*supervisors[i]);
	}

	for (int i = 0; i++; i < students.size()) {
		vector<int> temp1 = students[i]->getPrefOrder();
		vector<int> temp2 = students[i]->getPrefPrio();
		//vector<Vertex<People> *> temp3 = stableGraph->getVertexSet();
		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*students[i], *projects[temp1[j] - 1],
					temp2[j] - 1);
			//stableGraph->addEdge(temp3[i],temp3[i+students.size()],temp2[j]-1);
		}
	}
	for (int i = 0; i++; i < projects.size()) {
		vector<int> temp1 = projects[i]->getPrefOrder();
		vector<int> temp2 = projects[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*projects[i], *students[temp1[j] - 1],
					temp2[j] - 1);
		}
	}
	for (int i = 0; i++; i < supervisors.size()) {
		vector<int> temp1 = supervisors[i]->getPrefOrder();
		vector<int> temp2 = supervisors[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*supervisors[i], *projects[temp1[j] - 1],
					temp2[j] - 1);
		}
	}

}


int main() {

//create students
	cout<<"cenas\n";
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
	ProjResp* p1 = new ProjResp(5, "PR1", "P1", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempPrio->push_back(1);
	ProjResp* p2 = new ProjResp(6, "PR2", "P2", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(2);
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempPrio->push_back(2);
	tempPrio->push_back(3);
	tempPrio->push_back(1);
	ProjResp* p3 = new ProjResp(7, "PR3", "P3", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(3);
	tempPrio->push_back(2);
	ProjResp* p4 = new ProjResp(8, "PR4", "P4", *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(2);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	ProjResp* p5 = new ProjResp(9, "PR5", "P5", *tempOrder, *tempPrio);
//setSupervisors

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempPrio->push_back(1);
	tempPrio->push_back(2);
	tempPrio->push_back(3);
	Supervisors* s1 = new Supervisors(10, "S1", 2, *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(1);
	tempOrder->push_back(4);
	tempOrder->push_back(5);
	tempPrio->push_back(2);
	tempPrio->push_back(3);
	tempPrio->push_back(1);
	Supervisors* s2 = new Supervisors(11, "S2", 1, *tempOrder, *tempPrio);

	tempPrio->clear();
	tempOrder->clear();
	tempOrder->push_back(3);
	tempOrder->push_back(4);
	tempOrder->push_back(5);
	tempPrio->push_back(3);
	tempPrio->push_back(2);
	tempPrio->push_back(1);
	Supervisors* s3 = new Supervisors(12, "S3", 2, *tempOrder, *tempPrio);

//add to vectos

	students.push_back(e1);
	students.push_back(e2);
	students.push_back(e3);
	students.push_back(e4);

	projects.push_back(p1);
	projects.push_back(p2);
	projects.push_back(p3);
	projects.push_back(p4);
	projects.push_back(p5);

	supervisors.push_back(s1);
	supervisors.push_back(s2);
	supervisors.push_back(s3);
//set to vertex and edges using the 3 global vectors

	setGraph();
	cout<<"aplciar sabelmarriage";
	//@TODO Print the graph to check data input
	stableGraph->applyStableMarriage();
	//@TODO apply Hung Alg
	/**
	 * @TODO print final graph
	 */
	return 0;
}

