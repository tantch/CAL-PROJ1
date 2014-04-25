/*
 * Graph.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: pim
 */

#include "Graph.h"
using namespace std;

int Graph::getNumVertex() const {
	return vertexSet.size();
}

vector<Vertex *> Graph::getVertexSet() const {
	return vertexSet;
}

bool Graph::addVertex(const People &in) {
	typename vector<Vertex *>::iterator it = vertexSet.begin();
	typename vector<Vertex *>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in)
			return false;
	Vertex *v1 = new Vertex(in);
	vertexSet.push_back(v1);
	return true;
}

bool Graph::removeVertex(const People &in) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	typename vector<Vertex*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) {
			Vertex * v = *it;
			vertexSet.erase(it);
			typename vector<Vertex *>::iterator it1 = vertexSet.begin();
			typename vector<Vertex *>::iterator it1e = vertexSet.end();
			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}
			delete v;
			return true;
		}
	}
	return false;
}

bool Graph::addEdge(const People &sourc, const People &dest, double w) {
	typename vector<Vertex *>::iterator it = vertexSet.begin();
	typename vector<Vertex *>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex *edgeS, *edgeD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			edgeS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			edgeD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	edgeS->addEdge(edgeD, w);
	return true;
}

bool Graph::removeEdge(const People&sourc, const People &dest) {
	typename vector<Vertex *>::iterator it = vertexSet.begin();
	typename vector<Vertex *>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex *edgeS, *edgeD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			edgeS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			edgeD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	return edgeS->removeEdgeTo(edgeD);
}

void Graph::clone(Graph &gr) {
	typename vector<Vertex *>::const_iterator it = vertexSet.begin();
	typename vector<Vertex *>::const_iterator ite = vertexSet.end();

	// 1. clone vertices
	for (; it != ite; it++) {
		gr.addVertex((*it)->getInfo());
		gr.vertexSet[gr.getNumVertex() - 1]->visited = false;
	}

	// 2. clone edges
	for (it = vertexSet.begin(); it != ite; it++) {
		typename vector<Edge>::iterator edgeIt = ((*it)->adj).begin();
		typename vector<Edge>::iterator edgeIte = ((*it)->adj).end();
		for (; edgeIt != edgeIte; edgeIt++) {
			gr.addEdge((*it)->getInfo(), edgeIt->dest->getInfo(),
					edgeIt->weight);
		}
	}
}

vector<People> Graph::dfs() const {
	typename vector<Vertex *>::const_iterator it = vertexSet.begin();
	typename vector<Vertex *>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	vector res;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfs(*it, res);
	return res;
}

void Graph::dfs(Vertex *v, vector<People> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge>::iterator it = (v->adj).begin();
	typename vector<Edge>::iterator ite = (v->adj).end();
	for (; it != ite; it++)
		if (it->dest->visited == false)
			dfs(it->dest, res);
}

vector<People> Graph::bfs(Vertex *v) const {
	vector<People> res;
	queue<Vertex *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename vector<Edge>::iterator it = v1->adj.begin();
		typename vector<Edge>::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
			}
		}
	}
	return res;
}

int Graph::maxNewChildren(Vertex *v, People &inf) const {
	vector<People> res;
	queue<Vertex *> q;
	queue<int> level;
	int maxChildren = 0;
	inf = v->info;
	q.push(v);
	level.push(0);
	v->visited = true;
	while (!q.empty()) {
		Vertex *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		int l = level.front();
		level.pop();
		l++;
		int nChildren = 0;
		typename vector<Edge>::iterator it = v1->adj.begin();
		typename vector<Edge>::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
				level.push(l);
				nChildren++;
			}
		}
		if (nChildren > maxChildren) {
			maxChildren = nChildren;
			inf = v1->info;
		}
	}
	return maxChildren;
}

