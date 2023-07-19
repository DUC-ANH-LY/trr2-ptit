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

// thuat toan:

// dfs(u){
// 	vs[u] = 1;
// 	for(auto v:ke(u)){
// 		if(vs[v]=0) {
// 			e[v]=u;
// 			dfs(v);
// 		}
// 	}
// }


// G cho bởi ma trận kề a[i][j]
int a[100][100], n, u, e[100] = {0};
bool visited[100] = {false};


// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Auxiliary Space: O(V + E), since an extra visited array of size V is required, And stack size for iterative call to DFS function.
void dfs(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int v = 1; v <= n; v++)
		if (!visited[v] && a[u][v] == 1) {
			e[v] = u;
			dfs(v);
		}
}

// Driver code
int main()
{
	// testcase();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}

	dfs(1);
	cout << endl;
	for (int v = 1; v <= n; v++) cout << v << "(" << e[v] << "),";
}
