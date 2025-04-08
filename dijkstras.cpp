#include<iostream>
using namespace std;

class Graph{
public:
 int v;
 int a[3][3]={0};
 Graph(int v1)
 {
   v=v1;

 }


 void addEdge()
 {
    int p,q,r;
    

    for(int i=0;i<v;i++)
    {
    cout<<"\nEnter the src , desti, weight: ";
    cin>>p>>q>>r;
        a[p][q]=r;
        a[q][p]=r;
    }
 }

 void printGraph()
 {
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

 }


 void shortpath(int src) {
    int d[10], visited[10] = {0};

    // Step 1: Initialize distances
    for (int i = 0; i < v; i++) {
        d[i] = 9999;
    }
    d[src] = 0;

    // Step 2: Loop to process all vertices
    for (int cnt = 0; cnt < v - 1; cnt++) {
        int u = -1, min = 9999;

        // Step 3: Find unvisited vertex with minimum distance
        for (int i = 0; i < v; i++) {
            if (!visited[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1) break;

        // Step 4: Mark the selected vertex as visited
        visited[u] = 1;

        // Step 5: Update distance values
        for (int i = 0; i < v; i++) {
            int temp = d[u] + a[u][i];
            if (!visited[i] && a[u][i] && temp < d[i]) {
                d[i] = temp;
            }
        }
    }

    // Step 6: Output shortest distances
    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "To " << i << ": " << d[i] << endl;
    }
}


 



};

int main()
{
    int vx;

    cout<<"\nEnter the number of vertices: ";
    cin>>vx;
    Graph g(vx);

    g.addEdge();
    g.printGraph();
    g.shortpath(0);
     return 0;
}

