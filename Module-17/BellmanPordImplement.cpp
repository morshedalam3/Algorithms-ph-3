#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
 int u;
 int v;
 int w;
 Edge(int u,int v, int w)
 {
    this->u = u;
    this->v = v;
    this->w = w;
 }
};


int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> edges;
    while (e--)
    {
      int u,v,w;
      cin>>u>>v>>w;
      Edge ed(u, v, w);
      edges.push_back(ed);  
    }
    
   int dis[n+1];
   for (int i = 1; i <=n; i++)
   {
      dis[i]=INT_MAX;
   }
   dis[1]=0;
   
     for (int i = 0; i <n-1; i++)
      {
         for (int j = 0; j < edges.size(); j++)
         {
           Edge ed = edges[j];
           int a = ed.u;
           int b = ed.v;
           int w = ed.w;
           if (dis[a]+w < dis[b])
           {
            dis[b] = dis[a]+w;
           }
         }
      }
   
   for (int i = 1; i <= n; i++)
   {
      cout<<"Node"<<i<<": "<< dis[i]<<endl;
   }
 	return 0;
}