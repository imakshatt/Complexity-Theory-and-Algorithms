#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void acending(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}
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
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
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
void mergesort_a(vector<int> &arr, int n)
{
    acending(arr, n);
    auto start = high_resolution_clock::now();
    mergesort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();
    duration<double> total = end - start;
    for (int i = 0; i < 200; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total time taken by merge sort for " << n << " elements in Ascending order is: " << total.count() << endl;
    cout << "--------------------------------------------------------------------------------------------------------";
    cout << endl;
}
void mergesort_d(vector<int> &arr, int n)
{
    decending(arr, n);
    auto start = high_resolution_clock::now();
    mergesort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();
    duration<double> total = end - start;
    for (int i = 0; i < 200; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total time taken by merge sort for " << n << " elements in Decending order is: " << total.count() << endl;
    cout << "--------------------------------------------------------------------------------------------------------";
    cout << endl;
}
void mergesort_r(vector<int> &arr, int n)
{
    random(arr, n);
    auto start = high_resolution_clock::now();
    mergesort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();
    duration<double> total = end - start;
    for (int i = 0; i < 200; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total time taken by merge sort for " << n << " elements in random order is: " << total.count() << endl;
    cout << "--------------------------------------------------------------------------------------------------------";
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the size of an Array: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i <= 3; i++)
    {
        if (i == 1)
        {
            mergesort_a(arr, n);
        }
        if (i == 2)
        {
            mergesort_d(arr, n);
        }
        if (i == 3)
        {
            mergesort_r(arr, n);
        }
    }
}