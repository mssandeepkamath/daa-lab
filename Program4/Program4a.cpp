#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,vector<int>>adj;
stack<int>s;

void DFSUtil(int v)
{
    visited[v]=true;

    for(auto x:adj[v])
    {
        if(!visited[x])
        {
            DFSUtil(x);
        }
    }

    s.push(v);

}

void TopologicalSort()
{
    for(auto x:adj)
    {
        if(!visited[x.first])
        {
            DFSUtil(x.first);
        }
    }

    while(!s.empty())
    {
        int v=s.top();
        s.pop();
        cout<<v<<" ";
    }

}

void addEdge(int v,int u)
{
    adj[v].push_back(u);
}

int main()
{

    int n,m;
    int a;
    cout<<"Enter number of vertices\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number of vertices adjacent to vertex: "<<i<<"\n";
        cin>>m;
        cout<<"Enter the vertices\n";
        for(int j=0;j<m;j++)
        {
            cin>>a;
            addEdge(i,a);
        }
    }

    cout<<"Topological sort:\n";


    TopologicalSort();

    return 0;
}
