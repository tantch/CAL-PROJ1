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
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

vector<Students *> students;
vector<ProjResp *> projects;
vector<Supervisors *> supervisors;
Graph<People>* stableGraph;
int idN = 0;
void loadStudents() {
	cout << "loading\n";
	ifstream file;
	file.open("students.txt");
	if (!file.is_open()) {
		cout << "falhou\n";
		return;
	}

	string name;
	vector<int> Ord;
	vector<int> Prio;
	char comma;
	int ite;
	int e;

	while (!file.eof()) {
		Ord.clear();
		Prio.clear();
		string str;
		getline(file, name);
		getline(file, str);
		ite = atoi(str.c_str());
		cout << "Ite : " << ite << endl;

		for (int i = 0; i < ite; i++) {
			if (i == ite - 1)
				getline(file, str);
			else
				getline(file, str, ';');
			e = atoi(str.c_str());
			cout << "e: " << e << endl;
			Ord.push_back(e);
		}
		for (int i = 0; i < ite; i++) {
			if (i == ite - 1)
				getline(file, str);
			else
				getline(file, str, ';');
			e = atoi(str.c_str());
			cout << "e: " << e << endl;
			Prio.push_back(e);
		}

		Students* s = new Students(++idN, name, Ord, Prio);
		students.push_back(s);

	}
	file.close();
}

void loadProjResp() {

	cout << "loading";
	ifstream file;
	file.open("projects.txt");
	if (!file.is_open()) {
		cout << "falhou\n";
		return;
	}

	string name;
	string nproj;
	vector<int> Ord;
	vector<int> Prio;
	int ite;
	int e;

	while (!file.eof()) {
		Ord.clear();
		Prio.clear();
		string str;
		getline(file, name);
		getline(file, nproj);
		getline(file, str);
		ite = atoi(str.c_str());
		cout << "Ite : " << ite << endl;

		for (int i = 0; i < ite; i++) {
			if (i == ite - 1)
				getline(file, str);
			else
				getline(file, str, ';');
			e = atoi(str.c_str());
			cout << "e: " << e << endl;
			Ord.push_back(e);
		}

		for (int i = 0; i < ite; i++) {
			if (i == ite - 1)
				getline(file, str);
			else
				getline(file, str, ';');
			e = atoi(str.c_str());
			cout << "e: " << e << endl;
			Prio.push_back(e);
		}

		ProjResp* s = new ProjResp(++idN, name, nproj, Ord, Prio);
		projects.push_back(s);

	}

	file.close();
}

void loadSupervisors() {
	cout << "loading";
	ifstream file;
	file.open("supervisors.txt");
	if (!file.is_open()) {
		cout << "falhou\n";
		return;
	}

	string name;
	int nmax;
	vector<int> Ord;
	vector<int> Prio;
	char comma;
	bool cont = true;
	int e;
	int ite;

	while (!file.eof()) {
		Ord.clear();
		Prio.clear();
		string str;
		getline(file, name);
		getline(file, str);
		nmax = atoi(str.c_str());
		getline(file, str);
		ite = atoi(str.c_str());
		cout << "Ite : " << ite << endl;

		for (int i = 0; i < ite; i++) {
			if (i == ite - 1)
				getline(file, str);
			else
				getline(file, str, ';');
			e = atoi(str.c_str());
			cout << "e: " << e << endl;
			Ord.push_back(e);
		}

		for (int i = 0; i < ite; i++) {
			if (i == ite - 1)
				getline(file, str);
			else
				getline(file, str, ';');
			e = atoi(str.c_str());
			cout << "e: " << e << endl;
			Prio.push_back(e);
		}

		Supervisors* s = new Supervisors(++idN, name, nmax, Ord, Prio);
		supervisors.push_back(s);

	}
	file.close();

}
void setGraph() {
	stableGraph = new Graph<People>();
	stableGraph->setProjectsN(projects.size());
	stableGraph->setStudentsN(students.size());
	stableGraph->setSupervisorsN(supervisors.size());

	for (int i = 0; i < students.size(); i++) {
		stableGraph->addVertex(*students[i]);

	}

	for (int i = 0; i < projects.size(); i++) {
		stableGraph->addVertex(*projects[i]);
	}
	for (int i = 0; i < supervisors.size(); i++) {
		stableGraph->addVertex(*supervisors[i]);
	}

	for (int i = 0; i < students.size(); i++) {
		vector<int> temp1 = students[i]->getPrefOrder();
		vector<int> temp2 = students[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*students[i], *projects[temp1[j] - 1],
					temp2[j] - 1);

		}
	}
	for (int i = 0; i < projects.size(); i++) {
		vector<int> temp1 = projects[i]->getPrefOrder();
		vector<int> temp2 = projects[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*projects[i], *students[temp1[j] - 1],
					temp2[j] - 1);
		}
	}
	for (int i = 0; i < supervisors.size(); i++) {
		vector<int> temp1 = supervisors[i]->getPrefOrder();
		vector<int> temp2 = supervisors[i]->getPrefPrio();

		for (int j = 0; j < temp1.size(); j++) {
			stableGraph->addEdge(*supervisors[i], *projects[temp1[j] - 1],
					temp2[j] - 1);
		}
	}

}

int main() {
	loadStudents();
	loadProjResp();
	loadSupervisors();

	setGraph();
	cout << "inicial : \n";
	stableGraph->printGraph();

	stableGraph->applyStableMarriage();

	stableGraph->applyHungAlg();
	cout << "final: \n";
	stableGraph->printGraph();

	return 0;
}

