#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Graph
{
	public:
		int** matrix;
		int vertices;
		stack<int> topo;
		stack<int> st;
		Graph(){}
		Graph(int v)
		{
			vertices = v;
			matrix = new int*[v];
			for(int i=0 ; i<v ; i++)
			{
					matrix[i] = new int[v];
			}	
			for(int i=0 ; i<v ; i++)
			{
				for(int j=0 ; j<v ; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}	
		void addEdge(int i,int j,int w)
		{
			matrix[i][j] = w;
			matrix[j][i] = w;
		}
		void print()
		{
			for(int i=0 ; i<vertices ; i++)
			{
				for(int j=0 ; j<vertices ; j++)
				{
					cout << matrix[i][j] << "  ";
				}
				cout << endl;
			}
		}
		void cyclee(bool visited[],int pos,int parent)
		{	
			visited[pos] = true;
		
			for(int i=0 ; i<vertices ; i++)
			{
				if(matrix[pos][i] != 0)
				{
					if(!visited[i])
					{
						cyclee(visited,i,pos);
					}
					else if(i != parent)
					{
						cout << "Cycle detected\n\n";
						return;
					}
				}
			}
		}
		void checkCycle()
		{
			bool visited[vertices]{false};
			for(int i=0 ; i<vertices ; i++)
			{
				if(!visited[i])
				{
					cyclee(visited,i,-1);
				}
			}
		}
		void DFS(bool visited[],int sv)
		
		{
			cout << sv << "  ";
			visited[sv] = true;
			for(int i=0 ; i<vertices ; i++)
			{
				if(matrix[sv][i] !=0 && visited[i] == false)
				{
					DFS(visited,i);
				}
			}
		}
		void startDFS()
		{
			cout << "Enter starting vertex: ";
			int sv;
			cin >> sv;
			bool visited[vertices];
			for(int i=0 ; i<vertices ; i++)
			{
				visited[i] = false;
			}
			DFS(visited,sv);
		}
		void BFS(bool visited[],int sv)
		{
			visited[sv] = true;
			int front = 0;
			int rear = 0;
			int* queue = new int[vertices];
			queue[rear] = sv;
			rear++;
			while(front != rear)
			{
				int cv = queue[front];
				front++;
				cout << cv << "  ";
				for(int i=0 ; i<vertices ; i++)
				{
					if(matrix[cv][i] !=0 && !visited[i])
					{
						visited[i] = true;
						queue[rear] = i;
						rear++;
					}
				}
			}
		}
		void startBFS()
		{
			cout << "Enter sv: ";
			int sv;
			cin >> sv;
			bool visited[vertices];
			for(int i=0 ; i<vertices ; i++)
			{
				visited[i] = false;
			}
			BFS(visited,sv);
		}
		
		int findMin(int *distance,bool *visited)
		{
			int minVertex = -1;
			
			for(int i=0 ; i<vertices ; i++)
			{
				if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex]))
				{
					minVertex = i;
				}
			}
			return minVertex;
		}
	
		void dijkstra()
		{
			int distance[vertices];
			bool visited[vertices]{false};
			for(int i=0 ; i<vertices ; i++)
			{
				distance[i] = INT_MAX;
			}
			distance[0] = 0;
			
			for(int i=0 ; i<vertices ; i++)
			{
				int minVertex = findMin(distance,visited);
				visited[minVertex] = true;
				for(int j=0 ; j<vertices ; j++)
				{
					if(matrix[i][j] !=0 && !visited[j])
					{
						int dist = matrix[minVertex][j] + distance[minVertex];
						if(dist<distance[j])
						{
							distance[j] = dist;
						}
					}
				}
			}
			cout << endl << "Printing...\n";	
			for(int i=0 ; i<vertices ; i++)
			{
				cout << distance[i] << endl;
			}
		}
	
		void sortt(bool visited[],int i)
		{
			visited[i] = true;
			for(int j=0 ; j<vertices ; j++)
			{
				if(visited[j] == false && matrix[i][j] != 0)
				{
					sortt(visited,j);
				}
			}
			topo.push(i);
		}
		void topological()
		{
			bool visited[vertices]{false};
			int sv = 0;
			
			for(int i=0 ; i<vertices ; i++)
			{
				if(!visited[i])
				{
					sortt(visited,i);
				}
			}
			
			cout << endl << "Sorted array: ";
			while(!topo.empty())
			{
				cout << topo.top() << "  ";
				topo.pop();
			}
		}
		void cycle(bool visited[],int i)
		{
			visited[i] = true;
			for(int j=0 ; j<vertices ; j++)
			{
				if(!visited[j] && matrix[i][j] != 0)
				{
					cycle(visited,j);
				}
			}
			st.push(i);
		}
		void topological()
		{
			bool visited[vertices]{false};
			
			for(int i=0 ; i<vertices ; i++)
			{
				if(!visited[i])
				{
					cycle(visited,i);
				}
			}
			cout << endl << "Sorted Array: ";
			while(!st.empty())
			{
				cout << st.top() << endl;
				st.pop(); 
			}
		}
		bool checkifAll(bool* &visited)
		{
			for(int i=0 ; i<vertices ; i++)
			{
				if(visited[i] == false)
				{
					return false;
				}
			}
			return true;
		}
		void AddInOutput(int** &output,int i,int j,int w)
		{
			output[i][j] = w;
			output[j][i] = w;
		}
		
		void primsUntil(int** &output,bool * &visited,int sv)
		{
			if(checkifAll(visited))
			{
				cout << "Prims Algo:\n";
				for(int i=0 ; i<vertices ; i++)
				{
					for(int j=0 ; j<vertices ; j++)
					{
						cout << output[i][j] << "  ";
					}
					cout << endl;
				}
				return;
			}
			
			visited[sv] = true;
			
			int minw = INT_MAX;
			int minp = INT_MAX;
			int mini = INT_MAX;
			
			for(int i=sv ; i<vertices ; i++)
			{
				if(visited[i])
				{
					for(int j=0 ; j<vertices ; j++)
					{
						if(!visited[j] && matrix[i][j] != 0)
						{
							if(minw>matrix[i][j])
							{
								minw = matrix[i][j];
								minp = i;
								mini = j;
							}
						}
					}
				}
			}
			visited[mini] = true; 
			AddInOutput(output,minp,mini,minw);
			primsUntil(output,visited,0);
		}
		
		void prims()
		{
			int **output = new int*[vertices];
			for(int i=0 ; i<vertices ; i++)
			{
				output[i] = new int[vertices];
			}
			for(int i=0 ; i<vertices ; i++)
			{
				for(int j=0 ; j<vertices ; j++)
				{
					output[i][j] = 0;
				}
			}
			bool* vis = new bool[vertices]{false};
			
			primsUntil(output,vis,0);
		}	
		
};

int main()
{
	Graph obj(4);
	
	obj.addEdge(0, 1, 3);
    obj.addEdge(0, 2, 5);
    obj.addEdge(0, 3, 11);
	obj.addEdge(2, 3, 2);
	obj.addEdge(1, 3, 7);

	//obj.print();	
	obj.dijkstra();
	//obj.prims();
	obj.topological();
	
}