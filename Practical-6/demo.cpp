#include <bits/stdc++.h>
using namespace std;

void knapsackProblem(map<float, pair<int, int>, greater<float>> &final, int object) {
    int M;
    cout << endl;
    cout << "Enter the Knapsack capacity: ";
    cin >> M;
    float totalProfit = 0;

    cout << "Items selected in the knapsack:" << endl;

    int itemNumber = 1;

    for (auto it : final) {
        if (M > 0 && (it.second.second <= M)) {
            float selectedProfit = it.second.first;
            int selectedWeight = it.second.second;

            M -= selectedWeight;
            totalProfit += selectedProfit;

            cout << itemNumber << ") pw_ratio = " << it.first << " is selected with profit = " << selectedProfit << " and weight = " << selectedWeight << " so remaining weight is M = " << M << ". Current total profit: " << totalProfit << endl;
            itemNumber++;
        } else {
            if (M > 0) {
                float selectedProfit = it.first * M;
                int selectedWeight = M;

                totalProfit += selectedProfit;

                cout << itemNumber << ") pw_ratio = " << it.first << " is selected with profit = " << selectedProfit << " and weight = " << selectedWeight << " so remaining M = 0. Current total profit: " << totalProfit << endl;
                break;
            }
        }
    }

    cout << "Total Profit = " << totalProfit << endl;
}

int main() {
    int object;
    cin >> object;
    vector<int> profit(object);
    vector<int> weight(object);
    vector<pair<int, int>> pw;
    vector<float> pw_ratio;
    map<float, pair<int, int>, greater<float>> final;

    for (int i = 0; i < object; i++) {
        cin >> profit[i];
        cin >> weight[i];
    }

    for (int i = 0; i < object; i++) {
        pw.push_back({profit[i], weight[i]});
    }

    cout << endl;

    for (int i = 0; i < object; i++) {
        float result = static_cast<float>(pw[i].first) / static_cast<float>(pw[i].second);
        pw_ratio.push_back(result);
    }

    for (int i = 0; i < object; i++) {
        final[pw_ratio[i]] = {pw[i].first, pw[i].second};
    }

    cout << "Knapsack Table is as follows : ";
    cout << endl;

    for (auto it : final) {
        cout << "[p/w: " << it.first << ", (Profit: " << it.second.first << ", Weight: " << it.second.second << ")]";
    }

    knapsackProblem(final, object);
    return 0;
}
