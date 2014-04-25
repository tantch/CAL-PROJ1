/*
 * Graph.h
 *
 *  Created on: Apr 24, 2014
 *      Author: pim
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include "Edge.h"
#include "Vertex.h"
#include "People.h"

using namespace std;


class Graph {
	vector<Vertex *> vertexSet;
	void dfs(Vertex *v, vector<People> &res) const;

public:
	bool addVertex(const People &in);
	bool addEdge(const People &sourc, const People &dest, double w);
	bool removeVertex(const People &in);
	bool removeEdge(const People &sourc, const People &dest);
	vector<People> dfs() const;
	vector<People> bfs(Vertex *v) const;
	int maxNewChildren(Vertex *v, People &inf) const;
	vector<Vertex * > getVertexSet() const;
	int getNumVertex() const;

	void clone(Graph &g);
};

#endif /* GRAPH_H_ */
