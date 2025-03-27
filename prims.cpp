#include <iostream>
using namespace std;

#define V 3  // Number of vertices (3x3 graph)

// Prim's Algorithm
void primMST(int graph[V][V]) {
    int final[V] = {0}; // Track vertices included in MST
    int start[V];        // Store all vertices initially

    // Step 1: Initialize start array with all vertices
    for (int i = 0; i < V; i++) {
        start[i] = i;
    }

    // Step 2: Choose a starting vertex (let's pick vertex 0)
    final[0] = 1; // Mark vertex 0 as added to MST
    start[0] = -1; // Remove it from the start array

    cout << "Edges in the Minimum Spanning Tree (MST):\n";

    // Step 3: Repeat until all vertices are added to MST
    for (int edgeCount = 0; edgeCount < V - 1; edgeCount++) {
        int u = -1, v = -1;
        int minEdge = -1;

        // a) Find the next valid edge (u,v) satisfying the conditions
        for (int i = 0; i < V; i++) {
            if (final[i]) { // Pick any vertex already in the MST
                for (int j = 0; j < V; j++) {
                    if (start[j] != -1 && graph[i][j] != 0) { 
                        // Ensure it's a valid edge
                        if (minEdge == -1 || graph[i][j] < graph[u][v]) {
                            u = i;
                            v = j;
                            minEdge = graph[i][j];
                        }
                    }
                }
            }
        }

        // b) Add the selected vertex to the final array (MST)
        final[v] = 1;
        start[v] = -1;  // Mark vertex v as used

        // c) Print the selected edge
        cout << u << " - " << v << " : " << graph[u][v] << endl;
    }

    // Step 4: Stop (all vertices are in the MST now)
}

int main() {
    int graph[V][V] = {
        {0, 2, 3},
        {2, 0, 1},
        {3, 1, 0}
    };

    primMST(graph);

    return 0;
}