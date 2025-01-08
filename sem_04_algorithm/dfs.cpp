#include <iostream>

using namespace std;

// Define the maximum number of nodes in the graph
const int MAX_NODES = 9; // 0-8 for 9 nodes

// Recursive DFS function
void dfs(int graph[MAX_NODES][MAX_NODES], int node, bool visited[], int numNodes) {
    visited[node] = true; // Mark the current node as visited
    cout << node + 4 << " "; // Print the current node (adding 4 to match the actual node value)

    // Explore all adjacent nodes
    for (int neighbor = 0; neighbor < numNodes; neighbor++) {
        if (graph[node][neighbor] == 1 && !visited[neighbor]) {
            dfs(graph, neighbor, visited, numNodes); // Recursively visit the neighbor
        }
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0}, // Node 4 (0) -> 7 (1), 11 (2)
        {0, 0, 0, 1, 1, 0, 0, 0, 0}, // Node 7 (1) -> 5 (3), 3 (4)
        {0, 0, 0, 0, 0, 1, 1, 1, 0}, // Node 11 (2) -> 1 (5), 6 (6), 8 (7)
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 5 (3) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 3 (4) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 1}, // Node 1 (5) -> 12 (8)
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 6 (6) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 8 (7) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 0}  // Node 12 (8) -> No children
    };

    // Array to track visited nodes
    bool visited[MAX_NODES] = {false};

    // Perform DFS starting from the root node (Node 4, index 0)
    cout << "DFS Traversal starting from node 4: ";
    dfs(graph, 0, visited, MAX_NODES);
    cout << endl;

    return 0;
}
