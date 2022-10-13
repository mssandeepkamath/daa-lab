#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
vector<int> indegree(100, 0);

void addEdge(int v, int u)
{
    adj[v].push_back(u);
}

void BFS(int V)
{
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            indegree[v]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : adj[v])
        {
            if (--indegree[u] == 0)
            {
                q.push(u);
            }
        }
    }
}

int main()
{

    int V, E, in;
    cout << "Enter number of vertices\n";
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        cout << "Enter number of vertices adjacent to vertex " << i << "\n";
        cin >> E;
        cout << "Enter the adjacent vertices\n";
        for (int j = 0; j < E; j++)
        {
            cin >> in;
            addEdge(i, in);
        }
    }
    cout << "Topological sort(source=0) :\n";
    BFS(V);
    return 0;
}