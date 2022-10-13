#include<bits/stdc++.h>
using namespace std;
#define V 9

void printST(vector<int>dist)
{
    cout<<"Vertex  Distance from source\n";
    for(int i=0;i<V;i++)
    {
        cout<<i<<"  "<<dist[i]<<"\n";
    }
    cout<<"\n";
}
int minDistance(vector<bool>stSet,vector<int>dist)
{
    int min_val=INT_MAX,min_index=0;
    for(int i=0;i<V;i++)
    {
        if(!stSet[i] && min_val>dist[i])
        {
            min_val=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void DST(int graph[V][V])
{
    vector<bool>stSet(V,false);
    vector<int>dist(V,INT_MAX);
    dist[0]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=minDistance(stSet,dist);
        stSet[u]=true;
        for(int v=0;v<V;v++)
        {
            if(!stSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printST(dist);

}

int main()
{

    int graph[V][V]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                    {4, 0, 8, 0, 0, 0, 0, 11, 0},
                    {0, 8, 0, 7, 0, 4, 0, 0, 2},
                    {0, 0, 7, 0, 9, 14, 0, 0, 0},
                    {0, 0, 0, 9, 0, 10, 0, 0, 0},
                    {0, 0, 4, 14, 10, 0, 2, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 1, 6},
                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
                    {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    // cout<<"Enter the graph\n";
    // for(int i=0;i<V;i++)
    // {
    //     for(int j=0;j<V;j++)
    //     {
    //         cin >> graph[i][j];
    //     }
    // }
    DST(graph);
    
    return 0;
}