#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>>adj;
map<int,bool>visited;
map<int,int>indegree;


void addEdge(int v,int u)
{
    adj[v].push_back(u);
}

void topologicalSort()
{
    queue<int>q;

    for(auto x:adj)
    {
        for(auto y : x.second)
        {
            indegree[y]++;
        }
    }

    for(auto x:adj)
    {
        if(indegree[x.first]==0)
        {
          q.push(x.first);
        }
    }

    while(!q.empty())
    {
        int v=q.front();
        cout<<v;
        q.pop();
        for(auto x:adj[v])
        {
            if(--indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
}

 int main()
 {
     int n,m;
     cout<<"Enter number of vertices\n";
     cin>>n;
     int a;
     for(int i=0;i<n;i++)
     {
         cout<<"Enter number of vertices adjacent to vertex: "<<i<<"\n";
         cin>>m;
         cout<<"Enter vertices\n";
         for(int j=0;j<m;j++)
         {
             cin>>a;
             addEdge(i,a);
         }
     }
     cout<<"Topological sort: \n";
     topologicalSort();

 }