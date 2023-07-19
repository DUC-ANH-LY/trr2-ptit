#include <bits/stdc++.h>
using namespace std;
#define ll long long

void testcase()
{
	// For getting input from input.txt file
	freopen("input.txt", "r", stdin);

	// Printing the Output to output.txt file
	freopen("output.txt", "w", stdout);
}

int n;
bool visited[100]={false};
vector<int> vt;
int adj[100][100],path[100],i=0;


void print(){
	for(int i=0;i<(int)vt.size();i++) cout<<vt[i]<<" ";
		cout<<endl;
} 

void hamilton(int u){
	
	visited[u] = true;
	vt.push_back(u);
	// cout<<u<<endl;
	if(int(vt.size())==n) {
		vt.push_back(1);
		print();
		vt.pop_back();
		// return;
	}
	for(int v=1;v<=n;v++){
			if(adj[u][v] == 1 && !visited[v]) hamilton(v);
	}
	vt.pop_back();
	visited[u] = false;
}



int main(){
	// testcase();
	// 5
	// 0 0 1 1 0
	// 0 0 0 1 1
	// 1 0 0 1 1 
	// 1 1 1 0 0
	// 0 1 1 0 0
	cin>>n;
	// nhap ma tran ke 

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>adj[i][j];
	}

// for(int i=1;i<=n;i++){
// 		for(int j=1;j<=n;j++) cout<<adj[i][j]<<" ";
// 	}
	
	hamilton(1);

    
}