
#include <bits/stdc++.h>
using namespace std;


void testcase()
{
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
}

int ar[100][100];
int a[100][100],n, u, e[100]={0};
bool visited[100]={false};


void  BFS(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visited[u] = true;
        // cout<<u<<" "<<endl;
        for(int v=0;v<=n;v++){
            if(a[u][v] == 1 && !visited[v]){
                q.push(v);
                visited[v] = true;
                e[v]=u;
            }
        }
    }
}




int main() {
    testcase();
    cin>>n>>u;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }


    T_BFS(u);

// for(int i=0;i<=n;i++){
//     if(!vis[i]) DFS(i);
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
// 3 
// 4 
// 5 
// 6 
// Co cay khung: 
// (1,2)
// (1,3)
// (2,4)
// (2,5)
// (4,6)


