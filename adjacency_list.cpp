#include <iostream>

using namespace std;

class Node {
public:
    int vertex, weight;
    Node* next;
    
    Node(int v, int w, Node* n = nullptr) {
        vertex = v;
        weight = w;
        next = n;
    }
};

class Graph {
public:
    int vertices;
    Node** adjList;
    
    Graph(int v) {
        vertices = v;
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = nullptr;
        }
    }
    
    void addEdge(int u, int v, int weight) {
        adjList[u] = new Node(v, weight, adjList[u]);
        adjList[v] = new Node(u, weight, adjList[v]); // Remove for a directed graph
    }
    
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            Node* temp = adjList[i];
            while (temp) {
                cout << "(" << temp->vertex << ", " << temp->weight << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
    
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            Node* temp = adjList[i];
            while (temp) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjList;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    Graph g(vertices);
    
    cout << "Enter initial vertex, terminal vertex, weight of all edges:\n";
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }
    
    g.printGraph();
    
    return 0;
}
