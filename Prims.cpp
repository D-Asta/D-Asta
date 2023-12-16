#include <iostream>

using namespace std;

const int INF = 9999;

// Function to find the minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
    int min = INF, min_index;

    for (int v = 0; v < vertices; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the MST
void printMST(int parent[], int graph[][5], int vertices) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

// Function to perform Prim's algorithm
void primMST(int graph[][5], int vertices) {
    int parent[vertices]; // Array to store constructed MST
    int key[vertices];    // Key values used to pick minimum weight edge

    bool mstSet[vertices]; // To represent set of vertices included in MST

    for (int i = 0; i < vertices; ++i) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; ++count) {
        int u = minKey(key, mstSet, vertices);

        mstSet[u] = true;

        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, vertices);
}

int main() {
    const int vertices = 5;
    int graph[vertices][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, vertices);

    return 0;
}
