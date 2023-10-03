#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector <int> adjmat[N];
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

    for (int i = 1; i<=n; i++)
    {
        cout<<"list :"<<i<<": ";
        for (int j:adjmat[i])
        {
           cout<<j<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}