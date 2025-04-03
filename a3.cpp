#include<iostream>
using namespace std;

class Graph_Matrix
{
   public:

   int v,e;
   string cities[5];
   int m[5][5]={0};

   Graph_Matrix(int a,int b)
   {
     v=a;
     e=b;
   }

   void inputCities()
   {
    cout<<"\nEnter city names: ";
    for(int i=0;i<v;i++)
    {
        cin>>cities[i];
    }
   }

   int getIndex(string city)
   {
    for(int i=0;i<v;i++)
    {
        if(cities[i]==city)return i;
    }
    return -1;
   }


   void display()
   {
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
   }

   void edge()
   {
    string ca,cb;
    int cost;

    cout<<"\nEnter city1-city2-weight: ";
    for(int i=0;i<v;i++)
    {
        cin>>ca>>cb>>cost;

        int x=getIndex(ca);
        int y=getIndex(cb);

        m[x][y]=cost;
        m[y][x]=cost;
    }
   }
};

class Node {
    public:
        int vertex, weight;
        Node* next;
    
        Node(int v1, int w, Node* n = nullptr) {
            vertex = v1;
            weight = w;
            next = n;
        }
    };
    
    class Graph {
    public:
        int v, e;
        Node** adjList;
        string* cities;  // Dynamic array for city names
    
        Graph(int x, int y) {
            v = x;
            e = y;
            cities = new string[v];
            adjList = new Node*[v]();
        }
    
        void inputCities() {
            cout << "\nEnter city names: ";
            for (int i = 0; i < v; i++) {
                cin >> cities[i];
            }
        }
    
        int getIndex(string city) {
            for (int i = 0; i < v; i++) {
                if (cities[i] == city) return i;
            }
            return -1;
        }
    
        void addEdge(string city1, string city2, int weight) {
            int u = getIndex(city1);
            int v = getIndex(city2);
    
            if (u != -1 && v != -1) {
                adjList[u] = new Node(v, weight, adjList[u]);
                adjList[v] = new Node(u, weight, adjList[v]);
            } else {
                cout << "Invalid city name!\n";
            }
        }
    
        void printGraph() {
            cout << "\nAdjacency List Representation:\n";
            for (int i = 0; i < v; i++) {
                cout << cities[i] << " -> ";
                for (Node* temp = adjList[i]; temp; temp = temp->next) {
                    cout << cities[temp->vertex] << "(" << temp->weight << ") -> ";
                }
                cout << "NULL\n";
            }
        }
    };
int main()
{

    int n1,n2;
    cout<<"\nEnter no of cities,edges: ";
    cin>>n1>>n2;
    // Graph_Matrix g1(n1,n2);
//using matrix
    // g1.inputCities();
    // g1.edge();
    // g1.display();

//using list
Graph g(n1, n2);
g.inputCities();

    cout << "\nEnter initial city, terminal city, and weight of all edges:\n";
    for (int i = 0; i < n2; i++) {
        string city1, city2;
        int weight;
        cin >> city1 >> city2 >> weight;
        g.addEdge(city1, city2, weight);
    }

    g.printGraph();
    return 0;
}