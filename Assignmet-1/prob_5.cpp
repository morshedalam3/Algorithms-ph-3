#include<bits/stdc++.h>
using namespace std;


void createResultArray(int arr1[],int arr2[],int n,int m,int result[]){
int x=0,y=0,z=0;
while (x<n &&y<m)
{
   if (arr1[x]>arr2[y])
   {
      result[z++] = arr1[x++];
   }else{
      result[z++] = arr2[y++];
   }
   
}
while (x<n)
{
    result[z++] = arr1[x++];
}
while (y<n)
{
    result[z++] = arr2[y++];
}

}

int main()
{
    int n,m;
    cin >>n;
    int arr1[n];
    for (int i=0; i<n; i++){
        cin >>arr1[i];
    }
    cin>>m;
    int arr2[m];
    for (int i=0; i<m; i++){
        cin>>arr2[i];
    }
    int result[n+m];
    createResultArray( arr1, arr2,n,m,result);
    for (int i=0; i<n+m; i++)
    {
       cout<< result[i]<<' ';
    }
    
    return 0;
}