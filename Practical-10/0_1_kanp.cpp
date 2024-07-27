#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, int n, vector<int>& wt, vector<int>& val) {

    vector<vector<int>> B(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                if (val[i - 1] + B[i - 1][w - wt[i - 1]] > B[i - 1][w]) {
                    B[i][w] = val[i - 1] + B[i - 1][w - wt[i - 1]];
                } else {
                    B[i][w] = B[i - 1][w];
                }
            } else {
                B[i][w] = B[i - 1][w];
            }
        }
    }

    cout << "DP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; ++w) {
            cout << B[i][w] << " ";
        }
        cout << "\n";
    }

    int i = n, w = W;
    cout << "\nSelected items:\n";
    while (i > 0 && w > 0) {
        if (B[i][w] != B[i - 1][w]) {
            cout << "Item " << i << " (Weight: " << wt[i - 1] << ", Value: " << val[i - 1] << ")\n";
            w -= wt[i - 1];
        }
        i--;
    }

    return B[n][W];
}

int main() {
    int W = 8; // Knapsack capacity
    int n = 4; // Number of items

    vector<int> wt = {3, 4, 5, 6}; // Weight
    vector<int> val = {2, 3, 4, 1}; // Value

    int maxProfit = knapsack(W, n, wt, val);
    cout << "\nMaximum Profit: " << maxProfit << endl;

    return 0;
}
