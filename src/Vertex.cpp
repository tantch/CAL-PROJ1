/*
 * Vertex.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: pim
 */

#include "Vertex.h"
#define NULL 0
using namespace std;

People Vertex::getInfo() const {
	return info;
}

bool Vertex::removeEdgeTo(Vertex *d) {
	typename vector<Edge>::iterator it = adj.begin();
	typename vector<Edge>::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

Vertex::Vertex(People in) :
		info(in), visited(false), num(0), low(0), path(NULL) {
}

Vertex::Vertex(const Vertex & in) :
		info(in.info), visited(in.visited), num(in.num), low(in.low), path(NULL) {
}

void Vertex::addEdge(Vertex *dest, double w) {
	Edge edgeD = new Edge(dest, w);
	adj.push_back(edgeD);
}
