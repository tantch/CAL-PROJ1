/*
 * Edge.h
 *
 *  Created on: Apr 24, 2014
 *      Author: pim
 */

#ifndef EDGE_H_
#define EDGE_H_
#include <vector>
#include <list>
#include <queue>
#include "Graph.h"
#include "Vertex.h"
#include "People.h"

using namespace std;


class Edge {
	Vertex* dest;
	double weight;
	bool visited;
	bool active;
public:
	Edge(Vertex *d, double w);
	friend class Graph;
	friend class Vertex;
};
#endif /* EDGE_H_ */
