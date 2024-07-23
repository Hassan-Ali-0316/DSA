#include<iostream>
using namespace std;
class Graph{
	public:
	int **matrix;
	int vertices;
	Graph(int vertices)
	{
		this->vertices=vertices;
		matrix=new int*[vertices];
		for(int i=0;i<vertices;i++)
		{
			matrix[i]=new int[vertices];
			for(int j=0;j<vertices;j++)
			{
				matrix[i][j]=0;
			}
		}
	}
	void addEdge(int i,int j,int weight)
	{
		matrix[i][j]=weight;
		matrix[j][i]=weight;
	}
	void prims()
	{
		int **output;
		output=new int*[vertices];
		for(int i=0;i<vertices;i++)
		{
			output[i]=new int[vertices];
			for(int j=0;j<vertices;j++)
			{
				output[i][j]=0;
			}
		}
		bool *visited = new bool[vertices]{false};
		primsuntil(output,visited,0);
	}
	bool checkallvisited(bool *&visited)
	{
		for(int i=0;i<vertices;i++)
		{
			if(visited[i]==false)
			{
				return false;
			}
		}
		return true;
	}
	void primsuntil(int **&output,bool *&visited,int start)
	{
		if(checkallvisited(visited))
		{
			cout<<"Output:\n";
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					cout<<output[i][j]<<" ";
				}
				cout<<endl;
			}
			return;
		}
		visited[start]=true;
		int minweight=INT_MAX;
		int minparent=INT_MAX;
		int minindex=INT_MAX;
		for(int i=start;i<vertices;i++)
		{
			if(visited[i])
			{
				for(int j=0;j<vertices;j++)
				{
					if(!visited[j] && matrix[i][j]!=0)
					{
						if(minweight>matrix[i][j])
						{
							minweight=matrix[i][j];
							minparent=i;
							minindex=j;
						}
					}
				}
			}
		}
		visited[minindex]=true;
		addoutput(output,minweight,minparent,minindex);
		primsuntil(output,visited,0);
	}
	void addoutput(int **&output,int weight,int i,int j)
	{
		output[i][j]=weight;
		output[j][i]=weight;
	}
};

int main()
{
	Graph obj(6);
	obj.addEdge(0, 1, 2);
    obj.addEdge(0, 2, 3);
	obj.addEdge(2, 4, 4);
	obj.addEdge(1, 2, 5);
	obj.addEdge(1, 3, 3);
	obj.addEdge(3, 4, 2);
	obj.addEdge(3, 5, 3);
	obj.addEdge(1, 4, 4);
	obj.addEdge(4, 5, 5);
	obj.prims();
}