#include <bits/stdc++.h>
using namespace std;

void knapsackProblem(multimap<float, pair<int, int>, greater<float>> &final, int object)
{
    int M;
    cout << endl;
    cout << "Enter the Knapsack capacity : ";
    cin >> M;
    float p = 0;
    for (auto it : final)
    {
        if (M > 0 && (it.second.second <= M))
        {
            M -= it.second.second;
            p += it.second.first;
        }
        else
        {
            if (M > 0)
            {
                p += it.second.first * (static_cast<float>(M) / it.second.second);
            }
            break;
        }
    }
    cout << "------------------------------------------";
    cout << endl
         << "Maximum Profit : " << p;
}
int main()
{
    int object;
    cin >> object;
    vector<int> profit(object);
    vector<int> weight(object);
    vector<pair<int, int>> pw;
    vector<float> pw_ratio;
    multimap<float, pair<int, int>, greater<float>> final;
    for (int i = 0; i < object; i++)
    {
        cin >> profit[i];
        cin >> weight[i];
    }
    for (int i = 0; i < object; i++)
    {
        // for (int j = i; j < i + 1; j++)
        // {
        //     pw.push_back({profit[i], weight[i]});
        // }
        pw.push_back({profit[i], weight[i]});
    }
    cout << endl;
    //    for(auto it : pw){
    //        cout << "[profit: " << it.first << ", weight: " << it.second << "]";
    //    }
    for (int i = 0; i < object; i++)
    {
        float result = static_cast<float>(pw[i].first) / static_cast<float>(pw[i].second);
        pw_ratio.push_back(result);
    }
    //    for(auto it : pw_ratio){
    //        cout << it << ", ";
    //    }
    for (int i = 0; i < object; i++)
    {
        // final[pw_ratio[i]] = {pw[i].first, pw[i].second};
        final.insert({pw_ratio[i], {pw[i].first, pw[i].second}});
    }
    cout << "Knapsack Table is as follows : ";
    cout << endl;
    for (auto it : final)
    {
        cout << "[p/w: " << it.first << ", (Profit: " << it.second.first << ", Weight: " << it.second.second << ")]";
    }
    knapsackProblem(final, object);
    return 0;
}