#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector <int> adjmat[N];
bool visited[N];
int height[N];
void dfs(int u){
   visited[u] = true;   
    for (int v:adjmat[u])
    {
       if(visited[v] == true) continue;
       dfs(v);  
       height[u] = max(height[u], height[v]+1);
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
        cout<<"Height of "<<i<<" = "<<height[i]<<endl;
    }
    }
   
    
    return 0;
}