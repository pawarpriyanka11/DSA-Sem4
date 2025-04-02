#include <iostream>
#include <climits>

using namespace std;

#define N 4  // Number of nodes

int findMinDistance(int distance[], bool visited[]) {
    int minIndex = -1, minValue = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[N][N], int start) {
    int distance[N];
    bool visited[N] = {false};

    for (int i = 0; i < N; i++)
        distance[i] = INT_MAX;

    distance[start] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = findMinDistance(distance, visited);
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < N; i++)
        cout << "To " << i << " = " << distance[i] << endl;
}

int main() {
    int graph[N][N] = {
        {0, 1, 4, 0},
        {1, 0, 2, 5},
        {4, 2, 0, 1},
        {0, 5, 1, 0}
    };

    dijkstra(graph, 0);  // Start from node 0
    return 0;
}
