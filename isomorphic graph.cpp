#include<iostream>
#include<stack>
using namespace std;

class Graph
{
	public:
		int** graph;
		int ce;
		int vertices;
		stack<int> t;
		Graph(){}
		Graph(int v)
		{
			ce  =0;
			vertices = v;
			graph = new int*[v];
			for(int i=0 ; i<v ; i++)
			{
				graph[i] = new int[v];	
			}	
			for(int i=0 ; i<vertices ; i++)
			{
				for(int j=0 ; j<vertices ; j++)
				{
					graph[i][j] = 0;
				}
			}
		}	
		void BFS(int sv,bool visited[])
		{
			visited[sv] = true;
			int* queue = new int[vertices];
			int front = 0;
			int rear = 0;
			queue[rear] = sv;
			rear++;
			while(front != rear)
			{
				int cv = queue[front];
				front++;
				cout << cv;
				for(int i=0 ; i<vertices ; i++)
				{
					if(!graph[cv][i] != 0 && !visited[i])
					{
						visited[i] = true;
						BFS(i,visited);
					}
				}
			}
		}
		void startBFS()
		{
			cout << "Enter starting vertex: ";
			int sv;
			cin >> sv;
			bool visited[vertices]{false};
			BFS(sv,visited);
		}
		void addEdge(int i,int j,int w)
		{
			ce++;
			graph[i][j] = w;
//			graph[j][i] = w;
		}
		void toposort()
		{
			if(t.empty())
			{
				return;
			}
			int temp = t.top();
			toposort();
			cout << temp << "-->";
		}
		void DFS(int sv,bool visited[],int w)
		{
			cout << sv << "  ";
			t.push(sv);
			visited[sv] = true;
			for(int i=0 ; i<vertices ; i++)
			{
				if(!visited[i] && graph[sv][i] != 0)
				{
					DFS(i,visited,w);
				}
			}
		}
		void start()
		{
			cout << "Enter source: ";
			int sv;
			cin >> sv;
			bool visited[vertices];
			for(int i=0 ; i<vertices ; i++)
			{
				visited[i] = 0;
			}
			DFS(sv,visited,0);
		}
		void print()
		{
			for(int i=0 ; i<vertices ; i++)
			{
				for(int j=0 ; j<vertices ; j++)
				{
					cout << graph[i][j] << "\t";	
				}	
				cout << endl;
			}
		}
			
};

int main()
{
	Graph g1(5);
	Graph g2(5);
	g1.addEdge(0,1,4);
	g1.addEdge(0,2,8);
	g1.addEdge(1,3,5);
	g1.addEdge(1,2,2);
	g1.addEdge(3,4,5);
	g1.addEdge(4,3,9);
	
	g2.addEdge(0,1,4);
	g2.addEdge(0,2,8);
	g2.addEdge(1,3,5);
	g2.addEdge(1,2,2);
	g2.addEdge(2,3,5);
	if(g1.ce == g2.ce)
	{
		int arr1[g1.vertices];
		int arr2[g2.vertices];
		for(int i=0 ; i<g1.vertices ; i++)
		{
			int c1 = 0;
			for(int j=0 ; j<g1.vertices ; j++)
			{
				if(g1.graph[i][j] != 0)
				{
					c1++;
				}
			}
			arr1[i] = c1;
		}
		for(int i=0 ; i<g2.vertices ; i++)
		{
			int c1 = 0;
			for(int j=0 ; j<g2.vertices ; j++)
			{
				if(g2.graph[i][j] != 0)
				{
					c1++;
				}
			}
			arr2[i] = c1;
		}
		cout << endl << endl;
		for(int i=0 ; i<g2.vertices ; i++)
		{
			cout << arr1[i] << "  ";
		}
		cout << endl << endl;
		for(int i=0 ; i<g2.vertices ; i++)
		{
			cout << arr2[i] << "  ";
		}
		int c1=0,c2=0;
		for(int i=0 ; i<g1.vertices ; i++)
		{
			for(int j=0 ; j<g1.vertices ; j++)
			{
				if(arr1[i] == arr2[j])
				{
					c1++;
				}
			}
		}
		for(int i=0 ; i<g2.vertices ; i++)
		{
			for(int j=0 ; j<g2.vertices ; j++)
			{
				if(arr2[i] == arr1[j])
				{
					c2++;
				}
			}
		}
		if(c1==c2)
		{
			cout << "Isomorphic\n";
		}
		else
		{
			cout << "Not isomorphic\n";
		}
	}
	else
	{
		cout << "Not isomorphic\n";
	}
	
}