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
// For Quick Sort
void random(vector<int> &array, int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % n;
    }
}
void acending_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}
// For Quick Sort
void acending(vector<int> &array, int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = i;
    }
}
void decending_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1;
    }
}
// For Quick Sort
void decending(vector<int> &array, int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = n - i - 1;
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
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Bubble sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void bubblesortcode_d(int *arr, int n)
{
    decending_array(arr, n);
    auto start = high_resolution_clock::now();
    bubblesort(arr, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Bubble sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void bubblesortcode_r(int *arr, int n)
{
    random_array(arr, n);
    auto start = high_resolution_clock::now();
    bubblesort(arr, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Bubble sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
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
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Insertion sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void insertionsort_d(int *arr, int n)
{
    decending_array(arr, n);
    auto start = high_resolution_clock::now();
    insertionsort(arr, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Insertion sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void insertionsort_r(int *arr, int n)
{
    random_array(arr, n);
    auto start = high_resolution_clock::now();
    insertionsort(arr, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Insertion sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
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
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Selection sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void selectionsort_d(int *arr, int n)
{
    decending_array(arr, n);
    auto start = high_resolution_clock::now();
    selectionsort(arr, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Selection sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void selectionsort_r(int *arr, int n)
{
    random_array(arr, n);
    auto start = high_resolution_clock::now();
    selectionsort(arr, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Selection sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}

// Quicksort Algorithm
int part(vector<int> &arr, int low, int high)
{
    int midIndex = low + (high - low) / 2;
    int pivot = arr[midIndex];
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
            // swap(arr[i], arr[j]);
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // swap(arr[midIndex], arr[j]);
    int temp = arr[midIndex];
    arr[midIndex] = arr[j];
    arr[j] = temp;
    return j;
}

void qs(vector<int> &array, int low, int high)
{
    if (low < high)
    {
        int pIndex = part(array, low, high);
        qs(array, low, pIndex - 1);
        qs(array, pIndex + 1, high);
    }
}
vector<int> quicksort(vector<int> array, int n)
{
    qs(array, 0, n - 1);
    return array;
}
void quicksort_a(vector<int> &array, int n)
{
    acending(array, n);
    auto start = high_resolution_clock::now();
    quicksort(array, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Quick sort for " << n << " elements in "
         << "Acending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void quicksort_d(vector<int> &array, int n)
{
    decending(array, n);
    auto start = high_resolution_clock::now();
    quicksort(array, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Quick sort for " << n << " elements in "
         << "Decending Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}
void quicksort_r(vector<int> &array, int n)
{
    random(array, n);
    auto start = high_resolution_clock::now();
    quicksort(array, n);
    auto end = high_resolution_clock::now();
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    duration<double> total_time = end - start;
    cout << endl
         << "Total Time taken by Quick sort for " << n << " elements in "
         << "Random Order is: " << total_time.count() << endl;
    cout << "_______________________________________________________________________________________________";
}

// Main Function
int main()
{
    int n;
    cout << "Enter the Array Size: ";
    cin >> n;
    int *arr = new int[n];
    // For QUickSort
    vector<int> array(n);
    for (int i = 1; i <= 3; i++)
    {
        if (i == 1)
        {
            bubblesortcode_a(arr, n);
            insertionsort_a(arr, n);
            selectionsort_a(arr, n);
            quicksort_a(array, n);
        }
        else if (i == 2)
        {
            bubblesortcode_d(arr, n);
            insertionsort_d(arr, n);
            selectionsort_d(arr, n);
            quicksort_d(array, n);
        }
        else if (i == 3)
        {
            bubblesortcode_r(arr, n);
            insertionsort_r(arr, n);
            selectionsort_r(arr, n);
            quicksort_r(array, n);
        }
    }
    return 0;
}