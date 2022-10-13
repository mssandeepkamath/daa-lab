#include<bits/stdc++.h>
using namespace std;

vector<bool>visited(100,false);
vector<int> adj[100];

void addEdge(int v,int u)
{
    adj[v].push_back(u);
}


void DFSUtil(int source,stack<int>&s)
{

    visited[source]=true;
    for(int v:adj[source])
    {
        if(!visited[v])
            DFSUtil(v,s);
    }

  s.push(source);

}


void DFS(int V)
{
    stack<int>s;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            DFSUtil(i,s);
    }

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}



int main()
{

    int V,E,in;
    cout<<"Enter number of vertices\n";
    cin>>V;
    for(int i=0;i<V;i++)
    {
        cout<<"Enter number of vertices adjacent to vertex "<<i<<"\n";
        cin>>E;
        cout<<"Enter the adjacent vertices\n";
        for(int j=0;j<E;j++)
        {
            cin>>in;
            addEdge(i,in);
        }
    }
    cout<<"Topological sort(source=0) :\n";
    DFS(V);
    return 0;
}