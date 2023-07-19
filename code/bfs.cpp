// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;

void testcase()
{
	// For getting input from input.txt file
	freopen("input.txt", "r", stdin);

	// Printing the Output to output.txt file
	freopen("output.txt", "w", stdout);
}



// G cho bởi ma trận kề a[i][j]
int a[100][100], n, u, e[100] = {0};
bool visited[100] = {false};

// Time Complexity: O(V+E)
// Where V is the number of vertices and E is the number of edges in the graph.

// Space Complexity: O(V)
// We used an array of size V to store the BFS traversal. We also used an array of size V to keep track of visited vertices. We used a queue of size V to store the vertices.


void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (int v = 1; v <= n; v++) {
			if (!visited[v] && a[u][v] == 1) {
				e[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}


}



// Driver code
int main()
{
	testcase();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}

	bfs(1);
	cout << endl;
	for (int v = 1; v <= n; v++) cout << v << "(" << e[v] << "),";
}
