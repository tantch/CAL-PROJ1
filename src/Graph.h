/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <iostream>
using namespace std;

template<class T> class Edge;
template<class T> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;

/*
 * Class Vertex
 */
template<class T>
class Vertex {
	T info;
	vector<Edge<T> > adj;
	bool visited;
	bool processing;
	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);

	//folha pratica 5
	int indegree;
	int dist;
public:
	Vertex(T in);
	friend class Graph<T> ;
	vector<Edge<T> > getAdj() {
		return adj;
	}
	T getInfo() const;
	int getIndegree() const;

	Vertex* path;

};

template<class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it = adj.begin();
	typename vector<Edge<T> >::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

//atualizado pelo exercicio 5
template<class T>
Vertex<T>::Vertex(T in) :
		info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest, w);
	adj.push_back(edgeD);
}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

/*
 * Class Edge
 */
template<class T>
class Edge {
	Vertex<T> * dest;
	double weight;
	bool proposed;
	bool rejected;
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T> ;
	friend class Vertex<T> ;

	bool getProp() {
		return proposed;
	}
	bool getRej() {
		return rejected;
	}
	Vertex<T> * getDest() {
		return dest;
	}
};

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w) :
		dest(d), weight(w), proposed(false), rejected(false) {
}

/*
 * Class Graph
 */
template<class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, vector<T> &res) const;
	int studentsN, projectsN, supervisorsN;

public:
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	void applyStableMarriage();
	void setStudentsN(int n);
	void setProjectsN(int n);
	void printGraph();
	void setSupervisorsN(int n);
	bool studentsLinked();
	void applyHungAlg();
	//Exercicio 5
	Vertex<T>* getVertex(const T &v) const;

};

template<class T>
bool Graph<T>::addVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) {

			return false;
		}
	}
	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);

	return true;
}

template<class T>
void Graph<T>::setStudentsN(int n) {
	studentsN = n;
}

template<class T>
void Graph<T>::setProjectsN(int n) {
	projectsN = n;
}

template<class T>
void Graph<T>::setSupervisorsN(int n) {
	supervisorsN = n;
}

template<class T>
bool Graph<T>::removeVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) { //se encontrar
			Vertex<T> * v = *it;  //guarda temporario
			vertexSet.erase(it); //apaga
			typename vector<Vertex<T>*>::iterator it1 = vertexSet.begin();
			typename vector<Vertex<T>*>::iterator it1e = vertexSet.end();
			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}
			// decrementa indegree para arestas que se iniciam em "v"
			typename vector<Edge<T> >::iterator itAdj = v->adj.begin();
			typename vector<Edge<T> >::iterator itAdje = v->adj.end();
			for (; itAdj != itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vD->indegree++; //adicionado pelo exercicio 5
	vS->addEdge(vD, w);

	return true;
}

template<class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;

	//adicionado pelo exercicio 5
	return vS->removeEdgeTo(vD);
}

//****
template<class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v)
			return vertexSet[i];
	return NULL;
}

template<class T>
void Graph<T>::applyStableMarriage() {

	//percorrer estudantes
	for (int i = 0; i < studentsN; i++) {
		int min = -1;
		int edj;
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			if ((min == -1 || vertexSet[i]->adj[j].weight < min)
					&& !vertexSet[i]->adj[j].rejected) {
				min = vertexSet[i]->adj[j].weight;
				edj = j;
			}

		}
//colocar as ligaçoes selecioanas nos 2 sentidso
		if (min != -1) {
			vertexSet[i]->adj[edj].proposed = true;
			vertexSet[i]->adj[edj].rejected = true;
			Vertex<T> * de = vertexSet[i]->adj[edj].dest;
			for (int c = 0; c < de->adj.size(); c++) {
				if (de->adj[c].dest->info == vertexSet[i]->info) {
					de->adj[c].proposed = true;
				}
			}
		}
	}

	for (int i = studentsN; i < studentsN + projectsN; i++) {
		int min = -1;
		int edj;
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			cout << "testing conection of edge to: "
					<< vertexSet[i]->adj[j].dest->info.print() << endl;
			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				vertexSet[i]->adj[j].rejected = true;

				if (min == -1 || vertexSet[i]->adj[j].weight < min) {
					min = vertexSet[i]->adj[j].weight;
					edj = j;
				}
			}
		}
		if (min != -1) {

			vertexSet[i]->adj[edj].rejected = false;
			Vertex<T> * de = vertexSet[i]->adj[edj].dest;
			cout << "apor o destino : " << de->info.print() << endl;
			for (int c = 0; c < de->adj.size(); c++) {
				if (de->adj[c].dest->info == vertexSet[i]->info) {

					de->adj[c].rejected = false;
				}
			}
		}
	}

//se nao tiverem todos uma ligaçao
	if (!studentsLinked())
		this->applyStableMarriage();

}

template<class T>
void Graph<T>::printGraph() {

	string main, dest;

	cout << "size " << vertexSet.size();
	for (int i = 0; i < vertexSet.size(); i++) {
		cout << "\n Info: ";
		main = vertexSet[i]->info.print();
		cout << main << endl;
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			dest = vertexSet[i]->adj[j].dest->info.print();
			cout << "Connected to ";
			cout << dest;
			if (vertexSet[i]->adj[j].proposed == false)
				cout << " with Proposed=false";
			else
				cout << " with Proposed=true";

			if (vertexSet[i]->adj[j].rejected == false)
				cout << " with Rejected=false";
			else
				cout << " with Rejected=true";

			if(vertexSet[i]->adj[j].proposed && !vertexSet[i]->adj[j].rejected){
				cout<<"  final connection \n";
			}
			else
				cout<<"\n";

		}

	}
}
template<class T>
bool Graph<T>::studentsLinked() {
	bool n;
	int errm = 0;
	for (int i = 0; i < studentsN; i++) {
		n = false;
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {

			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				n = true;
				errm++;
			}

		}
		if (n == false) {
			return false;
		}
	}
	return true;
}

template<class T>
void Graph<T>::applyHungAlg() {
	//getting total supervisors iterations
	int sptN = 0;
	for (int i = studentsN + projectsN; i < vertexSet.size(); i++) {
		sptN += vertexSet[i]->info.getNumMax();
	}
	cout << "Total of supervisors it: " << sptN << " \n";
	//getting number of projects with students
	int prN = 0;
	for (int i = studentsN; i < studentsN + projectsN; i++) {

		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				prN++;
			}
		}

	}
	cout << "Total of projects picked: " << prN << " \n";

	int matrixSize = 0;

	if (sptN >= prN) {
		matrixSize = sptN + 1;
	} else
		matrixSize = prN + 1;

	cout << "Matrix size: " << matrixSize << endl;

	int matrix[matrixSize][matrixSize];
	//colocar ids de projectos e sueprvisores

	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			matrix[i][j] = -1;
		}
	}

	int r = 1;
	for (int i = studentsN + projectsN; i < vertexSet.size(); i++) {
		for (int j = 0; j < vertexSet[i]->info.getNumMax(); j++) {
			matrix[0][r] = vertexSet[i]->info.getId();
			r++;

		}

	}
	r = 1;
	for (int i = studentsN; i < studentsN + projectsN; i++) {
		bool con = false;

		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				con = true;

			}
		}
		if (con) {
			matrix[r][0] = vertexSet[i]->info.getId();
			r++;
		}
	}

	for (int i = 1; i < matrixSize; i++) {
		int proT = matrix[i][0];

		for (int j = 1; j < matrixSize; j++) {
			int supT = matrix[0][j];

			for (int c = 0; c < vertexSet[supT - 1]->adj.size(); c++) {

				if (vertexSet[supT - 1]->adj[c].dest->info.getId() == proT) {
					matrix[i][j] = vertexSet[supT - 1]->adj[c].weight;
				}
			}

		}
	}

	int max = -1;
	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < matrixSize; j++) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
	}
	cout << "o maximo é: " << max << endl;

	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < matrixSize; j++) {
			if (matrix[i][j] == -1) {
				matrix[i][j] = max;
			}
		}
	}

	//print
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//reduzir colunas

	for (int i = 1; i < matrixSize; i++) {
		int minc = -1;

		for (int j = 1; j < matrixSize; j++) {
			if (minc == -1 || matrix[j][i] < minc) {
				minc = matrix[j][i];
			}
		}
		for (int j = 1; j < matrixSize; j++) {
			matrix[j][i] -= minc;
		}

	}
	//print
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//reduzir filas

	for (int i = 1; i < matrixSize; i++) {
		int minc = -1;

		for (int j = 1; j < matrixSize; j++) {
			if (minc == -1 || matrix[i][j] < minc) {
				minc = matrix[i][j];
			}
		}
		for (int j = 1; j < matrixSize; j++) {
			matrix[i][j] -= minc;
		}

	}
	//print
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	bool rejectedj[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		rejectedj[i] = false;
	bool rejectedi[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		rejectedi[i] = false;
	bool tickedj[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		tickedj[i] = false;
	bool tickedi[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		tickedi[i] = false;
	bool accepted[matrixSize][matrixSize];
	int atributed = 0;

	bool assigned = false;
	bool multipelchoices = false;
	bool finished = false;
	bool ticked = false;
	while (!finished) {
		cout << "iteracion\n";
		assigned = false;
		ticked = false;
		multipelchoices = false;
		atributed = 0;

		for (int i = 0; i < matrixSize; i++)
			rejectedj[i] = false;

		for (int i = 0; i < matrixSize; i++)
			rejectedi[i] = false;

		for (int i = 0; i < matrixSize; i++)
			tickedj[i] = false;

		for (int i = 0; i < matrixSize; i++)
			tickedi[i] = false;
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				accepted[i][j] = false;
			}
		}

		while (!assigned) {
			cout << "  itere  " << endl;
			for (int i = 1; i < matrixSize; i++) {

				int znum = 0;
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]) {
						znum++;
					}
				}
				if (znum == 1) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[i][j] == 0 && !rejectedj[j]
								&& !rejectedi[i]) {
							accepted[i][j] = true;
							rejectedj[j] = true;
							rejectedi[i] = true;
							atributed++;
						}
					}
				}
				if (znum > 1 && multipelchoices) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]
								&& multipelchoices) {
							accepted[i][j] = true;
							rejectedj[j] = true;
							rejectedi[i] = true;
							atributed++;
							multipelchoices = false;
						}
					}

				}

			}
			for (int i = 1; i < matrixSize; i++) {

				int znum = 0;
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[j][i] == 0 && !rejectedi[j] && !rejectedj[i]) {
						znum++;
					}
				}
				if (znum == 1) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[j][i] == 0 && !rejectedi[j]
								&& !rejectedj[i]) {
							accepted[j][i] = true;
							rejectedi[j] = true;
							rejectedj[i] = true;
							atributed++;
						}
					}
				}
				if (znum > 1 && multipelchoices) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[j][i] == 0 && !rejectedi[j] && !rejectedj[i]
								&& multipelchoices) {
							accepted[j][i] = true;
							rejectedi[j] = true;
							rejectedj[i] = true;
							atributed++;
							multipelchoices = false;
						}
					}

				}

			}

			assigned = true;
			for (int i = 1; i < matrixSize; i++) {
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]) {

						assigned = false;

					}
				}
			}
			if (atributed == matrixSize - 1) {
				assigned = true;
			}

			multipelchoices = false;
			for (int i = 1; i < matrixSize; i++) {
				int znum = 0;
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[i][j] == 0 && rejectedj[j] != -1
							&& rejectedi[i] != -1) {

						znum++;

					}
				}
				if (znum > 1) {
					multipelchoices = true;
				}
			}
			if (!multipelchoices) {
				for (int j = 1; j < matrixSize; j++) {
					int znum = 0;
					for (int i = 1; i < matrixSize; i++) {
						if (matrix[i][j] == 0 && rejectedj[j] != -1
								&& rejectedi[i] != -1) {

							znum++;

						}
					}
					if (znum > 1) {
						multipelchoices = true;
					}
				}
			}
			//print
			for (int i = 0; i < matrixSize; i++) {
				for (int j = 0; j < matrixSize; j++) {
					cout << matrix[i][j] << "|";
				}
				cout << endl;
			}
		}

		cout << "assginment numbers: " << atributed << "\n";
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				cout << accepted[i][j] << "|";
			}
			cout << endl;

		}
		cout << endl;

		if (atributed == matrixSize - 1) {
			cout << "hungarian done\n";
			finished = true;
			ticked = true;
		}
		if (!ticked) {

			for (int i = 1; i < matrixSize; i++) {
				if (!rejectedi[i]) {
					tickedi[i] = true;

				}
			}
			for (int i = 1; i < matrixSize; i++) {
				cout << tickedi[i] << "|";
			}
			cout << "\n";
			for (int i = 1; i < matrixSize; i++) {
				cout << tickedj[i] << "|";
			}
			cout << "\n";
			cout << "\n";

			while (!ticked) {
				cout << "starting tick process\n";
				ticked = true;
				for (int i = 0; i < matrixSize; i++) {
					if (tickedi[i]) {

						for (int j = 0; j < matrixSize; j++) {
							if (matrix[i][j] == 0 && !tickedj[j]) {
								ticked = false;
								tickedj[j] = true;

							}

						}

					}
				}
				for (int j = 0; j < matrixSize; j++) {
					if (tickedj[j]) {

						for (int i = 0; i < matrixSize; i++) {
							if (!tickedi[i] && accepted[i][j]) {
								ticked = false;
								tickedi[i] = true;

							}

						}

					}
				}
				for (int i = 1; i < matrixSize; i++) {
					cout << tickedi[i] << "|";
				}
				cout << "\n";
				for (int i = 1; i < matrixSize; i++) {
					cout << tickedj[i] << "|";
				}
				cout << "\n";
				cout << "\n";
			}
		}

		for (int i = 0; i < matrixSize; i++) {
			if (tickedi[i]) {
				tickedi[i] = false;
			} else
				tickedi[i] = true;
		}

		for (int i = 1; i < matrixSize; i++) {
			cout << tickedi[i] << "|";
		}
		cout << "\n";
		for (int i = 1; i < matrixSize; i++) {
			cout << tickedj[i] << "|";
		}
		cout << "\n";
		cout << "\n";
		cout << "all ticked\n";
		int minT = -1;

		for (int i = 1; i < matrixSize; i++) {
			for (int j = 1; j < matrixSize; j++) {
				if ((matrix[i][j] < minT || minT == -1) && !tickedi[i]
						&& !tickedj[j]) {
					minT = matrix[i][j];
				}

			}
		}
		for (int i = 1; i < matrixSize; i++) {
			for (int j = 1; j < matrixSize; j++) {
				if (!tickedi[i] && !tickedj[j]) {
					matrix[i][j] -= minT;
				}
				if (tickedi[i] && tickedj[j]) {
					matrix[i][j] += minT;
				}

			}
		}

		cout << "minT = " << minT << endl;
		//print
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				cout << matrix[i][j] << "|";
			}
			cout << endl;
		}

		cout << "subtractiosn and additions compelted\n";

		for (int i = 1; i < matrixSize; i++) {

			int aci = matrix[i][0];
			for (int j = 1; j < matrixSize; j++) {

				if (accepted[i][j]) {
					int acj = matrix[0][j];
					for (int c = 0; c < vertexSet[acj-1]->adj.size(); c++) {
						if (vertexSet[acj-1]->adj[c].dest->info.getId() == aci) {
							vertexSet[acj-1]->adj[c].proposed = true;
						}
					}
				}
			}
		}
		cout << "graph updated\n";

	}

}

#endif /* GRAPH_H_ */
