#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack structure using linked list
struct Stack {
    Node* top;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack& stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack.top;
    stack.top = newNode;
}

// Function to pop an element from the stack
int pop(Stack& stack) {
    if (stack.top == NULL) {
        cerr << "Stack is empty." << endl;
        return -1;  // Return an invalid value if the stack is empty
    }

    int value = stack.top->data;
    Node* temp = stack.top;
    stack.top = stack.top->next;

    delete temp;
    return value;
}

// Node structure for the graph
struct GraphNode {
    int data;
    Node* neighbors;
    bool visited;
};

// Function to perform DFS on a graph represented using a linked list
void DFS(GraphNode graph[], int startVertex) {
    Stack stack;
    stack.top = NULL;

    cout << "DFS starting from vertex " << startVertex << ": ";

    // Push the starting vertex and mark it as visited
    push(stack, startVertex);
    graph[startVertex].visited = true;

    while (stack.top != NULL) {
        int currentVertex = pop(stack);
        cout << currentVertex << " ";

        // Push unvisited neighbors and mark them as visited
        Node* neighbor = graph[currentVertex].neighbors;
        while (neighbor != NULL) {
            int neighborData = neighbor->data;
            if (!graph[neighborData].visited) {
                push(stack, neighborData);
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
        Node* newNode = createNode(i + 3);
        newNode->next = graph[i].neighbors;
        graph[i].neighbors = newNode;

        newNode = createNode(i);
        newNode->next = graph[i + 1].neighbors;
        graph[i + 1].neighbors = newNode;
    }

    // Perform DFS starting from vertex 0
    DFS(graph, 0);

    return 0;
}
