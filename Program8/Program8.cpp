#include<bits/stdc++.h>
using namespace std;
#define V 5

void printPrims(vector<int> parent, int graph[V][V]) {

    cout<<"Edge\t\tWeight\n";

 for(int i=1;i<V;i++)
 {
     cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<"\n";
 }

}

int minKey(vector<int>&key, vector<bool>&mstSet)
{
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++)
    {
        if(mstSet[i]==false && key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
    }

    return min_index;

}
void primsMST(int graph[V][V])
{
    vector<bool>mstSet(V,false);
    vector<int>parent(V);
    vector<int>key(V,INT_MAX);
    parent[0]=-1;
    key[0]=0;

    for(int i=0;i<V-1;i++)
    {
        int u= minKey(key,mstSet);

        mstSet[u]=true;

        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }

    }

    printPrims(parent,graph);


}



int main()
{
     int m;
     int graph[V][V];
     cout<<"Enter the graph\n";
     for(int i=0;i<V;i++)
     {
         for(int j=0;j<V;j++)
         {
             cin>>graph[i][j];
         }
     }
     primsMST(graph);
     return 0;
}