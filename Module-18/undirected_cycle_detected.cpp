#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentSize[1000];

void dsu_set(int n)
{
    for (int i = 1; i <=n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
       node=parent[node];
    }
    return node;
};
void dsu_union(int a,int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA !=leaderB )
    {
       if (parentSize[leaderA]>parentSize[leaderB] )
    {
        parent[leaderB] = leaderA;
 
    }
    else if (parentSize[leaderB] > parentSize[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA]++;
        }
    }
}

int main()
{   
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        // cout<<leaderA<<" "<<leaderB<<endl;
        if (leaderA == leaderB)
        {
            cout<<"cycle detected between "<<a<< "and"<<b;
        }
        else{
            dsu_union(a,b);
            // cout<<"cycle not found"<<endl;
        }
    }

 	return 0;

  
}