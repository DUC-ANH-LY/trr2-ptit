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
int a[100][100],n, u, e[100]={0};
bool visited[100]={false};


// 6
// 0 1 1 0 0 0 
// 1 0 0 1 1 0 
// 1 0 0 1 0 0 
// 0 1 1 0 1 1 
// 0 1 0 1 0 1
// 0 0 0 1 1 0 
// => 1(0),2(1),3(4),4(2),5(4),6(5),
		void dfs(int u) { 
		cout << u << " ";
		visited[u]= true;
		for (int v= 1; v<=n; v++)
			if (!visited[v] && a[u][v]==1){ 
				e[v]= u;
				dfs(v);
				}
		}


void tplt_dfs(int a[100][100]){
	int c=0;
	for(int i=1;i<=n;i++) {
			if(!visited[i]) {
				dfs(i);
				c++;
			}
		}
	cout<<endl;
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
	tplt_dfs(a);
	// int c=0;
		// for(int i=1;i<=n;i++) {
		// 	if(!visited[i]) {
		// 		dfs(i);
		// 		c++;
		// 	}
		// }

		// cout<<"so thanh phan lien thong "<<c<<endl;
}

	