#include <iostream>
using namespace std;

int keys[10];


void printTree(int r[11][11], int i, int j) {
    if (i >= j) return;

    int root = r[i][j];
    cout << keys[root - 1] << " "; 

    printTree(r, i, root - 1); 
    printTree(r, root, j);     
}

int main() {
    int n;
    float p[10], q[11], w[11][11] = {0}, c[11][11] = {0};
    int r[11][11] = {0}; 

    cout << "\nEnter the number of keys: ";
    cin >> n;

    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "\nEnter the probabilities of successful search (p): ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "\nEnter the probabilities of unsuccessful search (q): ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    for (int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        c[i][i] = 0;
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            c[i][j] = 999999.0;
            for (int k = i + 1; k <= j; k++) {
                float cost = c[i][k - 1] + c[k][j] + w[i][j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;
                    r[i][j] = k;
                }
            }
        }
    }

    cout << "\nWeight matrix w[i][j]:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << "w[" << i << "][" << j << "] = " << w[i][j] << "\n";
            cout << "c[" << i << "][" << j << "] = " << c[i][j] << "\n";
        }
        cout << endl;
    }

    // cout << "\nCost matrix c[i][j]:\n";
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << "c[" << i << "][" << j << "] = " << c[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    cout << "\nMinimum cost of OBST is: " << c[0][n] << endl;

    cout << "\nOptimal Binary Search Tree Structure:\n";
    printTree(r, 0, n);

    return 0;
}
