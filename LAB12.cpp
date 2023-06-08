#include <bits/stdc++.h>
using namespace std;

#define V 6

// Code to find minimum key.
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Code to print MST edges.
void printMST(int parent[], int graph[V][V], int start)
{
    cout << "Starting Vertex : " << start << endl;
    cout << " Edge    Weight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "      " << graph[i][parent[i]] << " \n";
}

// Code to find MST.
void primMST(int graph[V][V], int start)
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Code to initialize variables.
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = start;
    parent[0] = -1;

    // Code to update MST.
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, start);
}

int main()
{
    int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };

    primMST(graph, 0);

    return 0;
}