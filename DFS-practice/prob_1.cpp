#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector <int> adjmat[N];
bool visited[N];

void dfs(int u){
   visited[u] = true;
    for (int v:adjmat[u])
    {
       if(visited[v] == true) continue;
       dfs(v);
    }
     cout<<u<<' ';
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjmat[u].push_back(v);
        adjmat[v].push_back(u);
    }
    dfs(1);
    
    return 0;
}