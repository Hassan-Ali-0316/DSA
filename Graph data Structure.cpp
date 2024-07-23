///*
//	An adjacency matrix is a way of repersenting a graph as a matrix of booleans 
//	a finite graph can be reperesented in the form of a square matrix on a computer ,where boolean value indicates if a direct path exists 
//	between two pair of vertices
//	
//	-> Lets assume the n*n matrix as adj[n][n]
//		if there is an edge from vertex i to j, mark adj[i][j] as 1 else mark 0
//		Find all nodes - O(n)
//		check if two nodes are connected O(1)
//		
//	In adjacency list,we use an array of a list to repersent the graph. The size of the array is equal to number of vertices. Let the array 
//	be an array[] an entry array[i] repersents the list of vertices adjacent to ith vertex
//*/
//
#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;

class edge
{
	public:
		int destinationVertexId;
		int weight;	
		edge(){}
		edge(int id,int w)
		{
			this->destinationVertexId = id;
			this->weight = w;
		}
		void setedgevalue(int id,int w)
		{
			this->destinationVertexId = id;
			this->weight = w;
		}
};

class vertex
{
	public:
		int stateid;
		string name;
		list<edge>edgelist;
		
		vertex()
		{
			stateid = 0;
			name = "-";	
		}	
		vertex(int id,string n)
		{
			this->stateid = id;
			this->name = n;
		}
		void setvertex(int id,string n)
		{
			this->stateid = id;
			this->name = n;
		}
		list<edge> getEdgeList()
		{
			return edgelist;
		}
};

class graph
{
	public:
		vector<vertex> vertices;
		graph(){}
		bool exists(vertex v)
		{
			for(int i=0 ; i<vertices.size() ; i++)
			{
				if(vertices.at(i).stateid == v.stateid)
				{
					return true;
				}
			}
			return false;
		}
		vertex getVertexById(int id)
		{
			vertex temp;
			for(int i=0 ; i<vertices.size() ; i++)
			{
				temp = vertices.at(i);
				if(temp.stateid == id)
				{
					return temp;
				}
			}
			return temp;
		}
		void addvertex(vertex v)
		{
			if(exists(v))
			{
				cout << "Vertex with id exists\n";
				return;
			}
			else
			{
				vertices.push_back(v);
				cout << "Vertex added\n";
				return;
			}
		}
		bool edgeExists(vertex v1,vertex v2)
		{
			vertex v = v1;
			list<edge> e;
			e = v.getEdgeList();
			for(auto it = e.begin() ; it!=e.end() ; it++)
			{
				if(it->destinationVertexId == v2.stateid)
				{
					return true;
				}	
			} 
			return false;
		}
		void addedge(vertex v1,vertex v2,int w)
		{
			if(exists(v1) == true && exists(v2) == true)
			{
				if(edgeExists(v1,v2))
				{
					cout << "Edge already exists between these pair of vertices " << v1.name << " & " << v2.name << endl;
					return;
				}
				else
				{
					for(int i=0 ; i<vertices.size() ; i++)
					{
						if(vertices.at(i).stateid == v1.stateid)
						{
							edge e(v2.stateid,w);
							vertices.at(i).edgelist.push_back(e);
						}
						else if(vertices.at(i).stateid == v2.stateid)
						{
							edge e(v1.stateid,w);
							vertices.at(i).edgelist.push_back(e);
						}
					}
				}
			}
			else
			{
				cout << "Either edge 1 or edge 2 d.n.e in the graph\n";
				return;
			}
		}
		void printedgelist(vertex v)
		{
			cout << "[";
			list<edge> e = v.getEdgeList();
			for(auto it=e.begin() ; it!=e.end() ; it++)
			{
				cout << it->destinationVertexId << "(" << it->weight << ") --> ";
			}
			cout << "]";
		}
		void updateEdge(vertex v1,vertex v2,int neww)
		{
			if(edgeExists(v1,v2))
			{
				for(int i=0 ; i<vertices.size() ; i++)
				{
					if(vertices.at(i).stateid == v1.stateid)
					{
						for(auto it = vertices.at(i).edgelist.begin() ; it != vertices.at(i).edgelist.end() ; it++)
						{
							if(it->destinationVertexId == v2.stateid)
							{
								it->weight = neww;
								break;
							}
						}
					}
					else if(vertices.at(i).stateid == v2.stateid)
					{
						for(auto it = vertices.at(i).edgelist.begin() ; it != vertices.at(i).edgelist.end() ; it++)
						{
							if(it->destinationVertexId == v1.stateid)
							{
								it->weight = neww;
								break;
							}
						}
					}
				}
			}
		}
		void deleteVertex(vertex v)
		{
			int idx = -1;
			if(exists(v))
			{
				for(int i=0 ; i<vertices.size() ; i++)
				{
					if(vertices.at(i).stateid == v.stateid)
					{
						idx = i;
						for(auto it = vertices.at(i).edgelist.begin() ; it != vertices.at(i).edgelist.end() ; it++)
						{
							deleteEdge(vertices.at(i),v);
						}
					}
				}
				if(idx != -1)
				{
					vertices.erase(vertices.begin()+idx);
				}
			}
		}
		void deleteEdge(vertex v1,vertex v2)
		{	
			if(edgeExists(v1,v2))
			{
				for(int i=0 ; i<vertices.size() ; i++)
				{
					if(vertices.at(i).stateid == v1.stateid)
					{
						for(auto it = vertices.at(i).edgelist.begin() ; it != vertices.at(i).edgelist.end() ; it++)
						{
							if(it->destinationVertexId == v2.stateid)
							{
								vertices.at(i).edgelist.erase(it);
								break;
							}
						}
					}
					else if(vertices.at(i).stateid == v2.stateid)
					{
						if(vertices.at(i).stateid == v2.stateid)
						{
							for(auto it = vertices.at(i).edgelist.begin() ; it != vertices.at(i).edgelist.end() ; it++)
							{
								if(it->destinationVertexId == v1.stateid)
								{
									vertices.at(i).edgelist.erase(it);
									break;
								}
							}
						}
					}
				}
			}
			else{
				cout<< "edgr not exists\n";
				return;
			}
		}
		void printgraph()
		{
			for(int i=0 ; i<vertices.size() ; i++)
			{
				vertex temp = vertices.at(i);
				cout << temp.name << " (" << temp.stateid << ") ---> ";
				printedgelist(temp);
				cout << endl;
			}
			cout << endl;
		}
		void printNeighbours(vertex v)
		{
			cout << "[" << v.name << "(" << v.stateid << ")]";
			for(int i=0 ; i<vertices.size() ; i++)
			{
				if(vertices.at(i).stateid == v.stateid)
				{
					for(auto it = vertices.at(i).edgelist.begin() ; it != vertices.at(i).edgelist.end() ; it++)
					{
						cout << "--->" << it->destinationVertexId << "(" << it->weight << ")";
					}
				}
			}
			cout << endl;
		}
};

int main() 
{
	graph g;
	string sname;
	int id1, id2, w;
	int opt;
	bool check;
	do 
	{
		cout << "What operation do you want to perform? " << endl;
		cout << "1. Add Vertex" << endl;
		cout << "2. Update Vertex" << endl;
		cout << "3. Delete Vertex" << endl;
		cout << "4. Add Edge" << endl;
		cout << "5. Update Edge" << endl;
		cout << "6. Delete Edge" << endl;
		cout << "7. Check if 2 Vertices are Neigbours" << endl;
		cout << "8. Print All Neigbors of a Vertex" << endl;
		cout << "9. Print Graph" << endl;
		cout << "10. Clear Screen" << endl;
		cout << "0. Exit Program" << endl;
		cin >> opt;
		if(opt == 1)
		{
			vertex v1;
			cout << "Enter state name: ";
			string n;
			cin >> n;
			cout << "Enter stateid: ";
			int id;
			cin >> id;
			v1.setvertex(id,n);
			g.addvertex(v1);
		}
		else if(opt == 2)
		{
			
		}
		else if(opt == 3)
		{
			cout << "Enter id vertex: ";
			int id1;
			cin >> id1;
			vertex v;
			v = g.getVertexById(id1);
			g.deleteVertex(v);	
		}
		else if(opt == 4)
		{
			cout << "Enter source id vertex: ";
			int id1;
			cin >> id1;
			vertex v1;
			v1 = g.getVertexById(id1);
			cout << "Enter destination id vertex: ";
			int id2;
			cin >> id2;
			vertex v2;
			v2 = g.getVertexById(id2);
			cout << "Enter weight of edge: ";
			int w;
			cin >> w;
			g.addedge(v1,v2,w);
		}
		else if(opt == 5)
		{
			cout << "Enter source id vertex: ";
			int id1;
			cin >> id1;
			vertex v1;
			v1 = g.getVertexById(id1);
			cout << "Enter destination id vertex: ";
			int id2;
			cin >> id2;
			vertex v2;
			v2 = g.getVertexById(id2);
			cout << "Enter new weight of edge: ";
			int w;
			cin >> w;
			g.updateEdge(v1,v2,w);
		}
		else if(opt == 6)
		{
			cout << "Enter source vertex id: ";
			int id1;
			cin >> id1;
			vertex v1 = g.getVertexById(id1);
			cout << "Enter destination vertex id: ";
			int id2;
			cin >> id2;
			vertex v2 = g.getVertexById(id2);
			g.deleteEdge(v1,v2);	
		}
		else if(opt == 7)
		{
			
		}
		else if(opt == 8)
		{
			cout << "Enter id vertex: ";
			int id1;
			cin >> id1;
			vertex v;
			v = g.getVertexById(id1);
			g.printNeighbours(v);
		}
		else if(opt == 9)
		{
			g.printgraph();
		}
		else if(opt == 10)
		{
			
		}
		else
		{
			exit(0);
		}
	}while (opt != 0);
	  return 0;
}