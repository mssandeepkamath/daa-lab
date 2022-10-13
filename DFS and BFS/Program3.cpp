#include <bits/stdc++.h>
using namespace std;

void BFS(int V);
void addEdge(int v, int u);
void DFSUtil(int source);
void BFSUtil(int source);
void DFS(int V);

vector<bool> visited(100, false);
vector<int> adj[100];

void addEdge(int v, int u)
{
    adj[v].push_back(u);
}

void DFSUtil(int source)
{
    visited[source] = true;
    cout << source << " ";
    for (int v : adj[source])
    {
        if (!visited[v])
            DFSUtil(v);
    }
}

void BFSUtil(int source)
{
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

void DFS(int V)
{
    int count_component=0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i);
            count_component++;
        }
    }

    if(count_component!=0)
    {
        cout<<"The given graph is disconnected and has "<<count_component<<" components\n";
    }
    else
    {
        cout<<"The given graph is connected\n";
    }
}

void BFS(int V)
{
    int count_component = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            BFSUtil(i);
            count_component++;
        }
           
    }
    if (count_component != 0)
    {
        cout << "The given graph is disconnected and has " << count_component << " components\n";
    }
    else
    {
        cout << "The given graph is connected\n";
    }
}

int main()
{
    int V, E, in, opt;
    cout << "Enter number of vertices\n";
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        cout << "Enter number of vertices adjacent to the vertex " << i << "\n";
        cin >> E;
        cout << "Enter the adjacent vertices\n";
        for (int j = 0; j < E; j++)
        {
            cin >> in;
            addEdge(i, in);
        }
    }
    while (1)
    {
        cout << "Enter the option\n1.DFS\n2.BFS\n3.exit";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "DFS (source:0)\n";
            DFS(V);
            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
            }
            break;
        }
        case 2:
        {
            cout << "BFS (source:0)\n";
            BFS(V);
            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
            }
            break;
        }
        case 3:
        {
            exit(0);
        }
        }
    }
    return 0;
}