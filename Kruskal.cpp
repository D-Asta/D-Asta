#include <iostream>

using namespace std;

const int MAX_VERTICES = 5;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function prototypes
int find(Subset subsets[], int i);
void Union(Subset subsets[], int x, int y);
void kruskalMST(Edge edges[], int vertices, int numEdges);

// Function to create 2D array and call Kruskal's algorithm
void generateKruskalMST() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int numEdges = 0;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        for (int j = i + 1; j < MAX_VERTICES; ++j) {
            if (graph[i][j] != 0) {
                ++numEdges;
            }
        }
    }

    Edge edges[numEdges];
    int edgeCount = 0;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        for (int j = i + 1; j < MAX_VERTICES; ++j) {
            if (graph[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                ++edgeCount;
            }
        }
    }

    kruskalMST(edges, MAX_VERTICES, numEdges);
}

// Function to find the subset of an element i
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Function to perform union of two subsets x and y
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to perform Kruskal's algorithm
void kruskalMST(Edge edges[], int vertices, int numEdges) {
    Edge result[MAX_VERTICES];
    int e = 0; // Index variable for result[]

    // Step 1: Sort all the edges in non-decreasing order of their weight
    for (int i = 0; i < numEdges - 1; ++i) {
        for (int j = 0; j < numEdges - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                swap(edges[j], edges[j + 1]);
            }
        }
    }

    // Allocate memory for creating subsets
    Subset subsets[MAX_VERTICES];

    // Create V subsets with single elements
    for (int v = 0; v < vertices; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < vertices - 1 && numEdges > 0) {
        // Step 2: Pick the smallest edge. And increment the index
        // for the next iteration
        Edge next_edge = edges[--numEdges];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it
        // in the result and increment the index of result for the next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the constructed MST
    cout << "Edges in the MST:" << endl;
    for (int i = 0; i < e; ++i) {
        cout << result[i].src << " - " << result[i].dest << " \tWeight: " << result[i].weight << endl;
    }
}

int main() {
    generateKruskalMST();

    return 0;
}
