/*
 * Edge.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: pim
 */

#include "Edge.h"
using namespace std;

Edge::Edge(Vertex *d, double w): dest(d), weight(w), visited(false),active(false){}


