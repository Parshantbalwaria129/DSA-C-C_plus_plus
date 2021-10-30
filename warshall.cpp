#include <bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define V 4
/* Define Infinite as a large enough
value.This value will be used for
vertices not connected to each other */
#define INF 99999
// A function to print the solution matrix
void printSolution(int dist[][V]);
void floydWarshall (int graph[][V])
{
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist);
}
void printSolution(int dist[][V])
{
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				cout<<"INF"<<"	 ";
			else
				cout<<dist[i][j]<<"	 ";
		}
		cout<<endl;
	}
}
int main()
{
	int graph[V][V] = { {0, 6, INF, 8},
						{INF, 0, 4, INF},
						{INF, INF, 0, 3},
						{INF, INF, INF, 0}
					};
	floydWarshall(graph);
	return 0;
}
