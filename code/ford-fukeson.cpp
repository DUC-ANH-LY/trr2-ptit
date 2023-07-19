#include <bits/stdc++.h>

using namespace std;


void io(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}

#define V 100
int graph[V][V];


bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				if (v == t) {
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return false;
}

int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	int rGraph[V][V]; 
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; 

	int max_flow = 0; 
	while (bfs(rGraph, s, t, parent)) {
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
	// io();
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++) cin>>graph[i][j];
	}

	cout << "The maximum possible flow is "
		<< fordFulkerson(graph, 0, 5);

	return 0;
}
