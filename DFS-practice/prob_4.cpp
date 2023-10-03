#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector <int> adjmat[N];
bool visited[N];
int depth[N];
void dfs(int u){
   visited[u] = true;   
    for (int v:adjmat[u])
    {
       if(visited[v] == true) continue;
       depth[v]=depth[u] + 1;
       dfs(v);   
    }
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
    int val;
    cin>>val;
    dfs(1);
 
    for (int i = 1; i<=n; i++)
    {   if (i==val)
    {
        cout<<"Depth of "<<i<<" = "<<depth[i]<<endl;
    }
    }
   
    
    return 0;
}