#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,vector<int>>adj;

void addEdge(int v,int u)
{
    adj[v].push_back(u);
}

void DFSUtil(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    for(auto x:adj[v])
    {
        if(!visited[x])
        {
            DFSUtil(x);
        }
    }

}

void DFS()
{
    for(auto x:adj)
    {
        if(!visited[x.first])
        {
            DFSUtil(x.first);
        }
    }
}

void BFS()
{
    queue<int>q;
    for(auto x:adj)
    {
        if(!visited[x.first])
        {
            visited[x.first]=true;
            q.push(x.first);
        }

        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            cout<<v<<" ";
            for(auto y:adj[v])
            {
                if(!visited[y])
                {
                    visited[y]=true;
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
//    0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
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
int opt;
cout<<"Enter option\n1.DFS\n2.BFS\n";
cin>>opt;
switch(opt)
{
    case 1:{
        cout<<"DFS is :\n";
        DFS();
        break;
    }
    case 2:
    {
        cout<<"BFS is :\n";
        BFS();
        break;
    }
    default: break;

}
    return 0;
}


