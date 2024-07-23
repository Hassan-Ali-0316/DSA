#include<iostream>
using namespace std;

bool isSafe(int arr[10][10], bool **vis, int i, int j, int n) {
    return (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && arr[i][j] != 0);
}

bool counti(int arr[10][10], bool **vis, int i, int j, int m, int n) {
    if (isSafe(arr, vis, i, j, m)) {
        vis[i][j] = true; // Mark current cell as visited
        // Explore adjacent cells
        counti(arr, vis, i, j + 1, m, n);
        counti(arr, vis, i - 1, j, m, n);
        counti(arr, vis, i + 1, j, m, n);
        counti(arr, vis, i, j - 1, m, n);
        counti(arr, vis, i + 1, j + 1, m, n);
        counti(arr, vis, i - 1, j + 1, m, n);
        counti(arr, vis, i + 1, j - 1, m, n);
        counti(arr, vis, i - 1, j - 1, m, n);
        return true;
    }
    return false;
}

int main() {
    int n = 10;
    int arr[10][10] = {{1,0,1,0,0,0,1,1,1,1},
                       {0,0,1,0,1,0,1,0,0,0},
                       {1,1,1,1,0,0,1,0,0,0},
                       {1,0,0,1,0,1,0,0,0,0},
                       {1,1,1,1,0,0,0,1,1,1},
                       {0,1,0,1,0,0,1,1,1,1},
                       {0,0,0,0,0,1,1,1,0,0},
                       {0,0,0,1,0,0,1,1,1,0},
                       {1,0,1,0,1,0,0,1,0,0},
                       {1,1,1,1,0,0,0,1,1,1}};

    bool **vis = new bool*[n];
    for(int i = 0; i < n; i++) {
        vis[i] = new bool[n];
        for(int j = 0; j < n; j++) {
            vis[i][j] = false; // Initialize all cells as not visited
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] != 0 && !vis[i][j]) {
                count++;
                counti(arr, vis, i, j, 10, 10);
            }
        }
    }

    cout << endl << "Number of islands: " << count << endl;

    // Free dynamically allocated memory
    for(int i = 0; i < n; i++) {
        delete[] vis[i];
    }
    delete[] vis;

    return 0;
}
