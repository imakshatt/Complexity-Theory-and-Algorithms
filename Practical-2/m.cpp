#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void decending(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1;
    }
}
void random(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
}
void mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = floor((low + high) / 2);
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main()
{
    int n = 10;
    vector<int> arr(n);

    random(arr, n);
    auto start_time = high_resolution_clock::now();
    mergesort(arr, 0, n - 1);
    auto end_time = high_resolution_clock::now();
    duration<double> total = end_time - start_time;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time Taken By merge Sort is: " << total.count() << endl;
    return 0;
}