//
// Created by AKSHAT on 11/1/2023.
//
#include <iostream>
#include <vector>

using namespace std;

void printStations(vector<vector<int>>& l, int n, int l_star) {
    int i = l_star;
    cout << "Line " << i << ", Station " << n << endl;

    for (int j = n; j >= 2; j--) {
        i = l[i - 1][j - 1];
        cout << "Line " << i << ", Station " << j - 1 << endl;
    }
}

void assemblyLineScheduling(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x, int n) {
    vector<vector<int>> f(2, vector<int>(n));
    vector<vector<int>> l(2, vector<int>(n));

    // Initialize the first station costs
    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];

    // Dynamic programming loop
    for (int j = 1; j < n; j++) {
        // Calculate costs and paths for line 1
        if (f[0][j - 1] + a[0][j] <= f[1][j - 1] + t[1][j - 1] + a[0][j]) {
            f[0][j] = f[0][j - 1] + a[0][j];
            l[0][j] = 1;
        } else {
            f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
            l[0][j] = 2;
        }

        // Calculate costs and paths for line 2
        if (f[1][j - 1] + a[1][j] <= f[0][j - 1] + t[0][j - 1] + a[1][j]) {
            f[1][j] = f[1][j - 1] + a[1][j];
            l[1][j] = 2;
        } else {
            f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
            l[1][j] = 1;
        }
    }

    int f_star, l_star;

    // Calculate the final costs and paths for the end stations
    if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1]) {
        f_star = f[0][n - 1] + x[0];
        l_star = 1;
    } else {
        f_star = f[1][n - 1] + x[1];
        l_star = 2;
    }

    cout << "Optimal Time: " << f_star << endl;
    cout << "Optimal Path: Line " << l_star << " -> Station " << n << endl;

    // Print all stations in the optimal path
    printStations(l, n, l_star);
}

int main() {
    int n = 5; // Number of stations
    vector<vector<int>> a = {{7, 9, 3, 4, 8}, {8, 5, 6, 4, 5}}; // Processing times for two lines
    vector<vector<int>> t = {{2, 3, 1, 3}, {2, 1, 2, 2}}; // Transfer times between stations
    vector<int> e = {2, 4}; // Entry times for the two lines
    vector<int> x = {3, 6}; // Exit times for the two lines

    assemblyLineScheduling(a, t, e, x, n);

    return 0;
}
