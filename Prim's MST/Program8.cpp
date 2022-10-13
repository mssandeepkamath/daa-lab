#include <bits/stdc++.h>
using namespace std;

void primsPrint(vector<int> parent, int graph[100][100], int V)
{
    cout << "Edge  Weight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << "->" << i << " = " << graph[i][parent[i]] << "\n";
    }
    cout << "\n";
}

int minKey(vector<int> key, vector<bool> mstSet, int V)
{
    int min_val = INT_MAX, min_index = 0;
    for (int i = 0; i < V; i++)
    {
        if (!mstSet[i] && key[i] < min_val)
        {
            min_val = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primsMST(int graph[100][100], int V)
{
    vector<bool> mstSet(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V);
    parent[0] = -1;
    key[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] && !mstSet[j] && graph[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    primsPrint(parent, graph, V);
}

// {0, 2, 0, 6, 0},
// {2, 0, 3, 8, 5},
// {0, 3, 0, 0, 7},
// {6, 8, 0, 0, 9},
// {0, 5, 7, 9, 0}

int main()
{

    int graph[100][100];
    int V;
    cout<<"Enter number of vertices\n";
    cin >> V;
    cout << "Enter the graph (weighted adjacency matrix)\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    primsMST(graph, V);

    return 0;
}