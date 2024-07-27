#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void random_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}
void acending_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

void decending_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1;
    }
}
// BubbleSort Algorithm
void bubblesort(int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void bubblesortcode_a(int *arr, int n)
{
    acending_array(arr, n);
    auto start = high_resolution_clock::now();
    bubblesort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl
         << "Total Time taken by Bubble sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
}
void bubblesortcode_d(int *arr, int n)
{
    decending_array(arr, n);
    auto start = high_resolution_clock::now();
    bubblesort(arr, n);
    auto end = high_resolution_clock::now();
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Bubble sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
}
void bubblesortcode_r(int *arr, int n)
{
    random_array(arr, n);
    auto start = high_resolution_clock::now();
    bubblesort(arr, n);
    auto end = high_resolution_clock::now();
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Bubble sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
}

// InsertionSort Algorithm
void insertionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
void insertionsort_a(int *arr, int n)
{
    acending_array(arr, n);
    auto start = high_resolution_clock::now();
    insertionsort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Insertion sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
}
void insertionsort_d(int *arr, int n)
{
    decending_array(arr, n);
    auto start = high_resolution_clock::now();
    insertionsort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Insertion sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
}
void insertionsort_r(int *arr, int n)
{
    random_array(arr, n);
    auto start = high_resolution_clock::now();
    insertionsort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Insertion sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
}

// Selection Sort Algorithm
void selectionsort(int *arr, int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
void selectionsort_a(int *arr, int n)
{
    acending_array(arr, n);
    auto start = high_resolution_clock::now();
    selectionsort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Selection sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
}
void selectionsort_d(int *arr, int n)
{
    decending_array(arr, n);
    auto start = high_resolution_clock::now();
    selectionsort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Selection sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
}
void selectionsort_r(int *arr, int n)
{
    random_array(arr, n);
    auto start = high_resolution_clock::now();
    selectionsort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Selection sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
}

// Quicksort Algorithm
int part(int *arr, int low, int high)
{
    int pivot = arr[high];
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

void qs(int *arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = part(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}
int *quicksort(int *arr, int n)
{
    qs(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    return arr;
}
void quicksort_a(int *arr, int n)
{
    acending_array(arr, n);
    auto start = high_resolution_clock::now();
    quicksort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Quick sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
}
void quicksort_d(int *arr, int n)
{
    decending_array(arr, n);
    auto start = high_resolution_clock::now();
    quicksort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Quick sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
}
void quicksort_r(int *arr, int n)
{
    random_array(arr, n);
    auto start = high_resolution_clock::now();
    quicksort(arr, n);
    auto end = high_resolution_clock::now();

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Quick sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
}

// Main Function
int main()
{
    int n;
    cout << "Enter the Array Size: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 1; i <= 3; i++)
    {
        if (i == 1)
        {
            bubblesortcode_a(arr, n);
            insertionsort_a(arr, n);
            selectionsort_a(arr, n);
            quicksort_a(arr, n);
        }
        else if (i == 2)
        {
            bubblesortcode_d(arr, n);
            insertionsort_d(arr, n);
            selectionsort_d(arr, n);
            quicksort_d(arr, n);
        }
        else if (i == 3)
        {
            bubblesortcode_r(arr, n);
            insertionsort_r(arr, n);
            selectionsort_r(arr, n);
            quicksort_r(arr, n);
        }
    }
    return 0;
}