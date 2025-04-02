#include <iostream>
using namespace std;

#define V 3  

int graph[V][V] = {0};  
string cities[V];  

void display() {
    cout << "\nAdjacency Matrix :\n";
    
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        cout <<graph[i][j] << " ";
      }
    cout<<endl;
  }
}



void prims() {
    int visited[V] = {0}; //visited array(to keep track if city has been included in MST or not) 
    visited[0] = 1;  //set src vertex as 0


    int totalWeight = 0;  

    cout << "\nMinimum Spanning Tree Edges:\n";
    
    for (int e= 0; e< V - 1; e++) {  //contine to add vertex in MST until (edge-1)
        int min = 9999, u = -1, v = -1;  //no valid edge

        for (int i = 0; i < V; i++) {
            if (visited[i]) {  //vertex in MST
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < min) {  //j is unseleteced & edge between i,j & edge between i,j is <min (update min)
                        min = graph[i][j];  
                        u = i;  //visited vetrex
                        v = j;  //newly stotred vertex
                    }
                }
            }
        }


        if (u != -1 && v != -1) {//valid edge is teher
            cout << cities[u] << " - " << cities[v] << " : " << min << endl;
            visited[v] = 1;//mark it as visited  
            totalWeight += min;  
        }
    }
    
    cout << "\nTotal Minimum Spanning Tree-distance minimum: " << totalWeight << endl;
}

int main() {
    int edges, weight;
    string city1, city2;

    cout << "Enter city names:\n";
    for (int i = 0; i < V; i++) {
        cin >> cities[i];  
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (city1 city2 weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> city1 >> city2 >> weight;
        
        int u = -1, v = -1;
        for (int j = 0; j < V; j++) {
            if (cities[j] == city1) {  
                u = j;
            }
            if (cities[j] == city2) {  
                v = j;
            }
        }
        
        if (u != -1 && v != -1) {
            graph[u][v] = weight;
            graph[v][u] = weight;  
        }
    }

    display();  
    prims();  

    return 0;
}
