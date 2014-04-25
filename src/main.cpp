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


int main(){

	//set Projects

	ProjResp* pr1= new ProjResp(1,"Joao Tiras","super acucar");
	//setSupervisors

	Students* st1= new Students(1,"Pedro");

	//set to vertex and edges

	Supervisors* sp1 = new Supervisors(1,"Rui",2);





	return 0;
}
