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

// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V), since an extra visited array of size V is required.
// https://www.geeksforgeeks.org/program-to-count-number-of-connected-components-in-an-undirected-graph/
// G cho bởi ma trận kề a[i][j]
int a[100][100],n, u, e[100]={0};
bool visited[100]={false};
		void bfs(int u) { 
			queue<int> q;
			q.push(u);
			visited[u] = true;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				// cout<<u<<" ";
				for(int v=1;v<=n;v++) {
					if(!visited[v] && a[u][v] == 1) {
						e[v]=u;
						visited[v] = true;
						q.push(v);
					}					
				}
			}


		}



		void tplt_bfs(int a[100][100]){
			int c=0;
		for(int i=1;i<=n;i++) {
			if(!visited[i]) {
				bfs(i);
				c++;
			}
		}
		cout<<c<<endl;
		}

// Driver code
int main()
{
		testcase();
		cin>>n;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) cin>>a[i][j];
		}
	tplt_bfs(a);
		// int c=0;
		// for(int i=1;i<=n;i++) {
		// 	if(!visited[i]) {
		// 		bfs(i);
		// 		c++;
		// 	}
		// }

		// cout<<"so thanh phan lien thong "<<c<<endl;
		// cout<<endl;
		// for(int v=1;v<=n;v++) cout<<v<<"("<<e[v]<<"),";
		// int c=0;
		// cout<<endl;
		// for(int v=1;v<=n;v++) if(visited[v]) c++;
		// if(c==n) cout<<"lien thong"<<endl;
		// else cout<<"khong lien thong"<<endl;
}
	