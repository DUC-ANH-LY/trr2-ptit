
#include <bits/stdc++.h>
using namespace std;


void testcase()
{
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
}

int a[100][100],n, u, e[100]={0};
bool visited[100]={false};


void  DFS(int u){
    visited[u] = true;
    cout<<u<<" "<<endl;
    for(int v=1;v<=n;v++){
        if(!visited[v] && a[u][v] == 1 ) {
            e[v] = u;
            DFS(v);
        }
    }
}


void T_DFS(int u){
    DFS(u);
    int dem = 0;
    for(int i=1;i<=n;i++) if(visited[i]==true) dem++;
     if(dem == n){
        cout<<"Co cay khung: "<<endl;
         for(int v=1;v<=n;v++){
            if(e[v]!=0) cout<<e[v]<<" "<<v<<endl;
        }
    }
    else cout<<"Khong co cay khung"<<endl;
} 

int main() {
    testcase();
    cin>>n>>u;   
    // a.resize(n+1,vector<int>(n+1));
    // visited.resize(n+1,false);
    // e.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }


    T_DFS(u);

// for(int i=0;i<=n;i++){
//     if(!visited[i]) DFS(i);
//     }
   
}
// input
// 6 1
// 0 1 1 0 0 0
// 1 0 0 1 1 0
// 1 0 0 1 0 0
// 0 1 1 0 1 1
// 0 1 0 1 0 1
// 0 0 0 1 1 0

// output
// 1 
// 2 
// 4 
// 3 
// 5 
// 6 
// Co cay khung: 
// (1,2)
// (2,4)
// (4,3)
// (4,5)
// (5,6)

// Co cay khung: 
// 1 2
// 4 3
// 2 4
// 4 5
// 5 6


