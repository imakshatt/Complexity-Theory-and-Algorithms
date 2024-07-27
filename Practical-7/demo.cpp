#include<bits/stdc++.h>

using namespace std;

void printStations(vector<vector<int>>& l, int n, int l_star) {
    int i = l_star;
    cout << "Line " << i << ", Station " << n << endl;
    for (int j = n; j >= 2; j--) {
        i = l[i - 1][j - 1];
        cout << "Line " << i << ", Station " << j - 1 << endl;
    }
}

void assemblyLineScheduling(int n) {
    vector<vector<int>> a(2, vector<int>(n));
    vector<vector<int>> t(2, vector<int>(n));
    vector<int> e(2);
    vector<int> x(2);

    cout << "Enter processing times for Line 1: ";
    for (int j = 0; j < n; j++) {
        cin >> a[0][j];
    }

    cout << "Enter processing times for Line 2: ";
    for (int j = 0; j < n; j++) {
        cin >> a[1][j];
    }

    cout << "Enter transfer times from Line 1 to Line 2: ";
    for (int j = 0; j < n - 1; j++) {
        cin >> t[0][j];
    }

    cout << "Enter transfer times from Line 2 to Line 1: ";
    for (int j = 0; j < n - 1; j++) {
        cin >> t[1][j];
    }

    cout << "Enter entry times for Line 1 and Line 2: ";
    cin >> e[0] >> e[1];

    cout << "Enter exit times for Line 1 and Line 2: ";
    cin >> x[0] >> x[1];

    vector<vector<int>> f(2, vector<int>(n));
    vector<vector<int>> l(2, vector<int>(n));

    // Initial values
    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];

    for (int j = 1; j < n; j++) {
        //cost for Line 1
        if (f[0][j - 1] + a[0][j] <= f[1][j - 1] + t[1][j - 1] + a[0][j]) {
            f[0][j] = f[0][j - 1] + a[0][j];
            l[0][j] = 1;
            cout << f[0][j] << " ";
        } else {
            f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
            l[0][j] = 2;
            cout << f[0][j] << " ";
        }

        // cosr for Line 2
        if (f[1][j - 1] + a[1][j] <= f[0][j - 1] + t[0][j - 1] + a[1][j]) {
            f[1][j] = f[1][j - 1] + a[1][j];
            l[1][j] = 2;
            cout << f[1][j] << " ";
        } else {
            f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
            l[1][j] = 1;
            cout << f[1][j] << " ";
        }
    }

    int f_star, l_star;

    //f* and l*
    if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1]) {
        f_star = f[0][n - 1] + x[0];
        l_star = 1;
    } else {
        f_star = f[1][n - 1] + x[1];
        l_star = 2;
    }

    cout << "Optimal Cost: " << f_star << endl;
    cout << "Optimal Path: Line " << l_star << " -> Station " << n << endl;

    // Print all stations in the optimal path
    printStations(l, n, l_star);
}

int main() {
    int n;
    cout << "Enter the number of stations: ";
    cin >> n;

    assemblyLineScheduling(n);

    return 0;
}
