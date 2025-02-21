#include <iostream>
#include <climits>

using namespace std;

#define INF 999 // A large value to represent no direct connection

class PrimMST {
    int graph[20][20]; // Adjacency matrix
    int V; // Number of offices (vertices)

public:
    void input();
    void display();
    void findMST();
};

// Function to take input from the user
void PrimMST::input() {
    cout << "Enter number of offices: ";
    cin >> V;

    // Initialize adjacency matrix with INF
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }

    int E;
    cout << "Enter number of connections: ";
    cin >> E;

    cout << "Enter edges (office1 office2 cost):\n";
    for (int i = 0; i < E; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = cost; // Store in adjacency matrix
    }
}

// Function to display adjacency matrix
void PrimMST::display() {
    cout << "\nAdjacency Matrix:\n";
    cout << "   "; // Formatting for column headers
    for (int i = 0; i < V; i++)
        cout << i + 1 << "   ";
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << i + 1 << " "; // Row headers
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << "   ";
        }
        cout << endl;
    }
}

// Function to find MST using Prim's Algorithm
void PrimMST::findMST() {
    int parent[V];  // Stores MST edges
    int key[V];     // Stores minimum edge weight
    bool visited[V]; // Track visited nodes

    // Initialize all keys as INF and visited as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    key[0] = 0; // Start from first office
    parent[0] = -1; // First node is root

    for (int count = 0; count < V - 1; count++) {
        int minKey = INF, minIndex = -1;

        // Find the minimum key vertex not included in MST
        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true; // Include this node in MST

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[minIndex][v] != INF && !visited[v] && graph[minIndex][v] < key[v]) {
                key[v] = graph[minIndex][v];
                parent[v] = minIndex;
            }
        }
    }

    // Display MST
    cout << "\nMinimum Spanning Tree (MST) connections:\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << "Office " << parent[i] + 1 << " -> Office " << i + 1 << " with cost: " << graph[parent[i]][i] << endl;
        totalCost += graph[parent[i]][i];
    }

    cout << "Total minimum cost to connect all offices: " << totalCost << endl;
}

int main() {
    PrimMST t;
    int choice;

    do {
        cout << "\n======= PRIM'S ALGORITHM =======" << endl;
        cout << "1. Input Graph\n2. Display Graph\n3. Find MST\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.input();
                break;
            case 2:
                t.display();
                break;
            case 3:
                t.findMST();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
