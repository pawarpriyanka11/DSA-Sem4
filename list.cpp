#include <iostream>
using namespace std;

class Node {
public:
    int dest, cost;
    Node* next;
    Node(int d, int c) {
        dest = d;
        cost = c;
        next = nullptr;
    }
};

class GRAPH {
public:
    int v, e;
    string cities[5];
    Node* adj[5] = {nullptr};
    
    GRAPH(int a, int b) {
        v = a;
        e = b;
    }

    void inputCities() {
        cout << "\nEnter city names:" << endl;
        for (int i = 0; i < v; i++) {
            cin >> cities[i];
        }
    }

    int getCityIndex(string city) {
        for (int i = 0; i < v; i++) {
            if (cities[i] == city) return i;
        }
        return -1;
    }

    void addEdge() {
        string cityA, cityB;
        int cost;
        cout << "\nEnter source city, destination city, and cost (time/fuel):" << endl;
        for (int i = 0; i < e; i++) {
            cin >> cityA >> cityB >> cost;
            int x = getCityIndex(cityA);
            int y = getCityIndex(cityB);
            if (x != -1 && y != -1) {
                Node* newNode1 = new Node(y, cost);
                newNode1->next = adj[x];
                adj[x] = newNode1;
                
                Node* newNode2 = new Node(x, cost);
                newNode2->next = adj[y];
                adj[y] = newNode2;
            }
        }
    }

    void display() {
        cout << "\nAdjacency List (Flight Costs):\n";
        for (int i = 0; i < v; i++) {
            cout << cities[i] << " -> ";
            Node* temp = adj[i];
            while (temp) {
                cout << "(" << cities[temp->dest] << ", " << temp->cost << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int n1, n2;
    cout << "\nEnter the number of cities:";
    cin >> n1;
    cout << "\nEnter the number of flights:";
    cin >> n2;
    
    GRAPH g(n1, n2);
    g.inputCities();
    g.addEdge();
    g.display();
    
    return 0;
}