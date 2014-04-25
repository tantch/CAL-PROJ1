/*
 * Vertex.h
 *
 *  Created on: Apr 24, 2014
 *      Author: pim
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <vector>
#include <list>
#include <queue>
#include "Edge.h"
#include "Graph.h"
#include "People.h"

using namespace std;


class Vertex {
	People info;

	bool visited;
	Edge cenas;
	vector<Edge> adj;
	void addEdge(Vertex *dest, double w);
	bool removeEdgeTo(Vertex *d);

	//Fp09
	int num;
	int low;
	Vertex* path;

public:
	Vertex(People in);
	Vertex(const Vertex &v);
	People getInfo() const;
	friend class Graph;
};


#endif /* VERTEX_H_ */
