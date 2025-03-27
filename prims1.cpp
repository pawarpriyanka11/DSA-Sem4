#include <iostream>
using namespace std;

#define V 3

void primMST(int graph[V][V]) {
    int final[V] = {0};
    int start[V];

    for (int i = 0; i < V; i++) {
        start[i] = i;
    }

    final[0] = 1;
    start[0] = -1;

    cout << "Edges in the Minimum Spanning Tree (MST):\n";

    for (int edgeCount = 0; edgeCount < V - 1; edgeCount++) {
        int u = -1, v = -1;
        int minEdge = -1;

        for (int i = 0; i < V; i++) {
            if (final[i]) {
                for (int j = 0; j < V; j++) {
                    if (start[j] != -1 && graph[i][j] != 0) {
                        if (minEdge == -1 || graph[i][j] < graph[u][v]) {
                            u = i;
                            v = j;
                            minEdge = graph[i][j];
                        }
                    }
                }
            }
        }

        final[v] = 1;
        start[v] = -1;

        cout << u << " - " << v << " : " << graph[u][v] << endl;
    }
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
