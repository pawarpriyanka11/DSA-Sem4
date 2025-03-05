#include <iostream>
using namespace std;

class GRAPH {
public:
    int v, e;
    string cities[5]; 
    int m[5][5] = {0};
    
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

    void edge() {
        string cityA, cityB;
        int cost;
        cout << "\nEnter source city, destination city, and cost (time/fuel):" << endl;
        for (int i = 0; i < e; i++) {
            cin >> cityA >> cityB >> cost;
            int x = getCityIndex(cityA);
            int y = getCityIndex(cityB);
            m[x][y] = cost;
            m[y][x] = cost;
           
        }
    }

    void display() {
        cout << "\nAdjacency Matrix (Flight Costs):\n";
        
        
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << m[i][j] << " ";
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
    g.edge();
    g.display();
    
    return 0;
}
