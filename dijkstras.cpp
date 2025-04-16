#include <iostream>
#include <string>
using namespace std;

class Graph {
public:
    int v;
    int a[10][10] = {0}; // adjacency matrix
    string city[10];     // array to store city names

    Graph(int v1) {
        v = v1;
    }

    int getIndex(string name) {
        for (int i = 0; i < v; i++) {
            if (city[i] == name) {
                return i;
            }
        }
        return -1; // not found
    }

    void inputCities() {
        cout << "\nEnter names of " << v << " cities:\n";
        for (int i = 0; i < v; i++) {
            cin >> city[i];
        }
    }

    void addEdge() {
        int edges;
        cout << "\nEnter the number of edges: ";
        cin >> edges;

        for (int i = 0; i < edges; i++) {
            string src, dest;
            int weight;
            cout << "\nEnter source, destination, and weight: ";
            cin >> src >> dest >> weight;

            int p = getIndex(src);
            int q = getIndex(dest);

            if (p != -1 && q != -1) {
                a[p][q] = weight;
                a[q][p] = weight;
            } else {
                cout << "Invalid city name. Try again.\n";
                i--; // retry this edge
            }
        }
    }

    void printGraph() {
        cout << "\nAdjacency Matrix:\n   ";
        for (int i = 0; i < v; i++) {
            cout << city[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < v; i++) {
            cout << city[i] << " ";
            for (int j = 0; j < v; j++) {
                cout << a[i][j] << "   ";
            }
            cout << endl;
        }
    }

    void shortpath(string srcName) {
        int d[10], visited[10] = {0};
        int src = getIndex(srcName);

        if (src == -1) {
            cout << "Invalid source city.\n";
            return;
        }

        for (int i = 0; i < v; i++) {
            d[i] = 9999;
        }
        d[src] = 0;

        for (int cnt = 0; cnt < v - 1; cnt++) {
            int u = -1, min = 9999;
            for (int i = 0; i < v; i++) {
                if (!visited[i] && d[i] < min) {
                    min = d[i];
                    u = i;
                }
            }

            if (u == -1) break;
            visited[u] = 1;

            for (int i = 0; i < v; i++) {
                if (!visited[i] && a[u][i]) {
                    int temp = d[u] + a[u][i];
                    if (temp < d[i]) {
                        d[i] = temp;
                    }
                }
            }
        }

        cout << "\nShortest distances from " << srcName << ":\n";
        for (int i = 0; i < v; i++) {
            cout << "To " << city[i] << ": " << d[i] << endl;
        }
    }
};

int main() {
    int vx;
    cout << "Enter the number of cities: ";
    cin >> vx;

    Graph g(vx);
    g.inputCities();
    g.addEdge();
    g.printGraph();

    string src;
    cout << "\nEnter source city to find shortest paths: ";
    cin >> src;
    g.shortpath(src);

    return 0;
}

