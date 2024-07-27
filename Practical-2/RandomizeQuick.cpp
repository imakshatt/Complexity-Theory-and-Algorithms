#include <bits/stdc++.h>
using namespace std;

void acending_array(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}
void descending_array(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1;
    }
}
void random_array(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}

// pivot low
int part(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = part(arr, low, high);
        quicksort(arr, low, pIndex - 1);
        quicksort(arr, pIndex + 1, high);
    }
}
// void quick_asc(vector<int> &arr, int n)
// {
//     acending_array(arr, n);
//     quicksort(arr, 0, n - 1);
//     for (int i = 0; i < 200; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
void quick_dsc(vector<int> &arr, int n)
{
    descending_array(arr, n);
    quicksort(arr, 0, n - 1);
    cout << endl;
    cout << "---------------------------------------------------------------------------";
    cout << endl;
    for (int i = 0; i < 200; i++)
    {
        cout << arr[i] << " ";
    }
}
// void quick_random(vector<int> &arr, int n)
// {
//     random_array(arr, n);
//     quicksort(arr, 0, n - 1);
//     cout << endl;
//     cout << "---------------------------------------------------------------------------";
//     cout << endl;
//     for (int i = 0; i < 200; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
int main()
{
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 1; i <= 3; i++)
    {
        if (i == 1)
        {
            // quick_asc(arr, n);
        }
        else if (i == 2)
        {
            quick_dsc(arr, n);
        }
        else
        {
            // quick_random(arr, n);
        }
    }
    return 0;
}