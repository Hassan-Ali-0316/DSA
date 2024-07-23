#include <iostream>
#include <climits>
using namespace std;

class Graph 
{
    int vertices;
    int** graph;

public:
    Graph(int v) 
	{
        this->vertices = v;
        graph = new int*[v];
        for (int i = 0; i < v; i++) 
		{
            graph[i] = new int[v];
            for (int j = 0; j < v; j++) 
			{
                graph[i][j] = 0;  // Initialize with 0 for no edges
            }
        }
    }

    void addEdge(int i, int j, int weight) 
	{
        graph[i][j] = weight;
        graph[j][i] = weight;  // For an undirected graph
    }

    void removeEdge(int i, int j) 
	{
        graph[i][j] = 0;
        graph[j][i] = 0;
    }

    void primsMST() 
	{
        bool* inMST = new bool[vertices];
        int* parent = new int[vertices];
        int* key = new int[vertices];

        for (int i = 0; i < vertices; i++) 
		{
            key[i] = INT_MAX;
            inMST[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertices - 1; count++) 
		{
            int minVertex = findMinKey(key, inMST);
            inMST[minVertex] = true;

            for (int v = 0; v < vertices; v++) 
			{
                if (graph[minVertex][v] && !inMST[v] && graph[minVertex][v] < key[v]) 
				{
                    parent[v] = minVertex;
                    key[v] = graph[minVertex][v];
                }
            }
        }

        printMST(parent);
        delete[] inMST;
        delete[] parent;
        delete[] key;
    }

    int findMinKey(int* key, bool* inMST) 
	{
        int min = INT_MAX, minIndex = -1;

        for (int v = 0; v < vertices; v++) 
		{
            if (!inMST[v] && key[v] < min) 
			{
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    void printMST(int* parent) 
	{
        cout << "Edges in MST (Prim's Algorithm):\n";
        for (int i = 1; i < vertices; i++) 
		{
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << graph[i][parent[i]] << endl;
        }
    }

    void kruskalMST() 
	{
        int* parent = new int[vertices];
        for (int i = 0; i < vertices; i++) 
		{
            parent[i] = i;
        }

        cout << "Edges in MST (Kruskal's Algorithm):\n";
        int edgeCount = 0;
        while (edgeCount < vertices - 1) 
		{
            int min = INT_MAX, a = -1, b = -1;
            for (int i = 0; i < vertices; i++) 
			{
                for (int j = 0; j < vertices; j++) 
				{
                    if (find(parent, i) != find(parent, j) && graph[i][j] < min && graph[i][j] != 0) 
					{
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
            unionSets(parent, a, b);
            cout << "Edge: " << a << " - " << b << " Weight: " << min << endl;
            edgeCount++;
        }
        delete[] parent;
    }

    int find(int parent[], int i) 
	{
        while (parent[i] != i) 
		{
            i = parent[i];
        }
        return i;
    }

    void unionSets(int parent[], int x, int y) 
	{
        int xSet = find(parent, x);
        int ySet = find(parent, y);
        parent[xSet] = ySet;
    }
    
    int findMin(int distance[],bool visited [])
    {
    	int minVertex = -1;
    	for(int i=0 ; i<vertices ; i++)
    	{
    		if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex]))
    		{
    			minVertex = i;
			}
		}
		return (minVertex);
	}
    void dijkstra()
    {
    	bool visited[vertices]{false};
    	int distance[vertices];
    	for(int i=0 ; i<vertices ; i++)
    	{
    		distance[i] = INT_MAX;
		}
		
		distance[0] = 0;
		
		for(int i=0 ; i<vertices-1 ; i++)
		{
			int minVertex = findMin(distance,visited);
			visited[minVertex] = true;
			
			for(int j=0 ; j<vertices ; j++)
			{
				if(!visited[j] && graph[minVertex][j] != 0)
				{
					int dist = distance[minVertex] + graph[minVertex][j];
					if(dist<distance[j])
					{
						distance[j] = dist;
					}
				}
			}
		}
		cout << endl << endl << "Printing dijsktra:\n";
		for(int i=0 ; i<vertices ; i++)
		{
			cout << i << " ---> " << distance[i] << endl;
		}
	}
    
    void print() 
	{
        cout << "Adjacency Matrix Representation:\n";
        for (int i = 0; i < vertices; i++) 
		{
            for (int j = 0; j < vertices; j++) 
			{
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 4, 4);

    g.primsMST();
    cout << endl;
    g.kruskalMST();
    g.dijkstra();
    g.print();
    return 0;
}
