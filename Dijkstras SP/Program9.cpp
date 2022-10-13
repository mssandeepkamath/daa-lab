#include <bits/stdc++.h>
using namespace std;

void printST(vector<int> dist, int V)
{
    cout << "Vertex  Distance from source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "  " << dist[i] << "\n";
    }
    cout << "\n";
}
int minDistance(vector<bool> stSet, vector<int> dist, int V)
{
    int min_val = INT_MAX, min_index = 0;
    for (int i = 0; i < V; i++)
    {
        if (!stSet[i] && min_val > dist[i])
        {
            min_val = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void DST(int graph[100][100], int V)
{
    vector<bool> stSet(V, false);
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(stSet, dist, V);
        stSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!stSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printST(dist, V);
}

int main()
{

    int graph[100][100];
    int V;
    cout << "Enter number of vertices\n";
    cin >> V;
    cout << "Enter the graph (weighted adjacency matrix)\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    DST(graph, V);

    return 0;
}