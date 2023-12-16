#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Queue structure using linked list
struct Queue {
    Node* front;
    Node* rear;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue an element in the queue
void enqueue(Queue& queue, int value) {
    Node* newNode = createNode(value);
    if (queue.rear == NULL) {
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue& queue) {
    if (queue.front == NULL) {
        cerr << "Queue is empty." << endl;
        return -1;  // Return an invalid value if the queue is empty
    }

    int value = queue.front->data;
    Node* temp = queue.front;

    if (queue.front == queue.rear) {
        queue.front = NULL;
        queue.rear = NULL;
    } else {
        queue.front = queue.front->next;
    }

    delete temp;
    return value;
}

// Node structure for the graph
struct GraphNode {
    int data;
    Node* neighbors;
    bool visited;
};

// Function to perform BFS on a graph represented using a linked list
void BFS(GraphNode graph[], int startVertex) {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    cout << "BFS starting from vertex " << startVertex << ": ";

    // Enqueue the starting vertex and mark it as visited
    enqueue(queue, startVertex);
    graph[startVertex].visited = true;

    while (queue.front != NULL) {
        int currentVertex = dequeue(queue);
        cout << currentVertex << " ";

        // Enqueue unvisited neighbors and mark them as visited
        Node* neighbor = graph[currentVertex].neighbors;
        while (neighbor != NULL) {
            int neighborData = neighbor->data;
            if (!graph[neighborData].visited) {
                enqueue(queue, neighborData);
                graph[neighborData].visited = true;
            }
            neighbor = neighbor->next;
        }
    }

    cout << endl;
}

int main() {
    const int numVertices = 6;
    GraphNode graph[numVertices];

    // Initialize graph vertices
    for (int i = 0; i < numVertices; ++i) {
        graph[i].data = i;
        graph[i].neighbors = NULL;
        graph[i].visited = false;
    }

    // Add edges (assuming an undirected graph)
    for (int i = 0; i < numVertices - 1; ++i) {
        Node* newNode = createNode(i + 1);
        newNode->next = graph[i].neighbors;
        graph[i].neighbors = newNode;

        newNode = createNode(i);
        newNode->next = graph[i + 1].neighbors;
        graph[i + 1].neighbors = newNode;
    }

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    return 0;
}
