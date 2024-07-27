#include <bits/stdc++.h>

using namespace std;

int partition_low(vector<int> &array, int low, int high)
{
    int pivot = array[low];
    int start = low + 1;
    int end = high;

    while (true)
    {
        while (start <= end && array[end] >= pivot)
        {
            end = end - 1;
        }
        while (start <= end && array[start] <= pivot)
        {
            start = start + 1;
        }
        if (start <= end)
        {
            swap(array[start], array[end]);
        }
        else
        {
            break;
        }
    }

    swap(array[low], array[end]);
    return end;
}

int partition_high(vector<int> &array, int low, int high)
{
    int pivot = array[high];
    int start = low;
    int end = high - 1;

    while (true)
    {
        while (start <= end && array[start] <= pivot)
        {
            start = start + 1;
        }
        while (start <= end && array[end] >= pivot)
        {
            end = end - 1;
        }
        if (start <= end)
        {
            swap(array[start], array[end]);
        }
        else
        {
            break;
        }
    }

    swap(array[start], array[high]);
    return start;
}

int partition_mid(vector<int> &array, int low, int high)
{
    int mid = (low + high) / 2;
    int pivot = array[mid];
    int start = low;
    int end = high;

    while (true)
    {
        while (array[start] < pivot)
        {
            start = start + 1;
        }
        while (array[end] > pivot)
        {
            end = end - 1;
        }
        if (start >= end)
        {
            return end;
        }
        swap(array[start], array[end]);
        start = start + 1;
        end = end - 1;
    }
}

int partition_random(vector<int> &array, int low, int high)
{
    int pivot_index = low + rand() % (high - low + 1);
    int pivot = array[pivot_index];
    swap(array[pivot_index], array[high]);

    int start = low;
    int end = high - 1;

    while (true)
    {
        while (start <= end && array[start] <= pivot)
        {
            start = start + 1;
        }
        while (start <= end && array[end] >= pivot)
        {
            end = end - 1;
        }
        if (start <= end)
        {
            swap(array[start], array[end]);
        }
        else
        {
            break;
        }
    }

    swap(array[start], array[high]);
    return start;
}

void quick_sort(vector<int> &array, int start, int end, int pivot_choice)
{
    while (start < end)
    {
        int idx;

        switch (pivot_choice)
        {
        case 0: // Low
            idx = partition_low(array, start, end);
            break;
        case 1: // High
            idx = partition_high(array, start, end);
            break;
        case 2: // Mid
            idx = partition_mid(array, start, end);
            break;
        case 3: // Random
            idx = partition_random(array, start, end);
            break;
        }

        if (idx - start < end - idx)
        {
            quick_sort(array, start, idx - 1, pivot_choice);
            start = idx + 1;
        }
        else
        {
            quick_sort(array, idx + 1, end, pivot_choice);
            end = idx - 1;
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> sizes = {10000, 50000, 100000};

    for (int size : sizes)
    {
        vector<int> ascending(size);
        vector<int> descending(size);
        vector<int> random(size);

        // Generate ascending order array
        for (int i = 0; i < size; ++i)
        {
            ascending[i] = i + 1;
        }

        // Generate descending order array
        for (int i = 0; i < size; ++i)
        {
            descending[i] = size - i;
        }

        // Generate random order array
        for (int i = 0; i < size; ++i)
        {
            random[i] = rand() % size + 1;
        }

        // Sort with different pivot choices
        for (int pivot_choice = 0; pivot_choice < 4; ++pivot_choice)
        {
            vector<int> ascending_copy = ascending;
            vector<int> descending_copy = descending;
            vector<int> random_copy = random;

            // Sort ascending order array
            clock_t start_time = clock();
            quick_sort(ascending_copy, 0, ascending_copy.size() - 1, pivot_choice);
            clock_t end_time = clock();
            double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

            cout << "Array Size: " << size << ", Pivot Choice: ";
            switch (pivot_choice)
            {
            case 0:
                cout << "Low";
                break;
            case 1:
                cout << "High";
                break;
            case 2:
                cout << "Mid";
                break;
            case 3:
                cout << "Random";
                break;
            }
            cout << "\nAscending Order, Time Taken: " << elapsed_time << " seconds" << endl;

            // Print the first 200 sorted elements
            cout << "First 200 Sorted Elements: ";
            for (int i = 0; i < min(200, size); ++i)
            {
                cout << ascending_copy[i] << " ";
            }
            cout << "\n\n";

            // Sort descending order array
            start_time = clock();
            quick_sort(descending_copy, 0, descending_copy.size() - 1, pivot_choice);
            end_time = clock();
            elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

            cout << "Array Size: " << size << ", Pivot Choice: ";
            switch (pivot_choice)
            {
            case 0:
                cout << "Low";
                break;
            case 1:
                cout << "High";
                break;
            case 2:
                cout << "Mid";
                break;
            case 3:
                cout << "Random";
                break;
            }
            cout << "\nDescending Order, Time Taken: " << elapsed_time << " seconds" << endl;

            // Print the first 200 sorted elements
            cout << "First 200 Sorted Elements: ";
            for (int i = 0; i < min(200, size); ++i)
            {
                cout << descending_copy[i] << " ";
            }
            cout << "\n\n";

            // Sort random order array
            start_time = clock();
            quick_sort(random_copy, 0, random_copy.size() - 1, pivot_choice);
            end_time = clock();
            elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

            cout << "Array Size: " << size << ", Pivot Choice: ";
            switch (pivot_choice)
            {
            case 0:
                cout << "Low";
                break;
            case 1:
                cout << "High";
                break;
            case 2:
                cout << "Mid";
                break;
            case 3:
                cout << "Random";
                break;
            }
            cout << "\nRandom Order, Time Taken: " << elapsed_time << " seconds" << endl;

            // Print the first 200 sorted elements
            cout << "First 200 Sorted Elements: ";
            for (int i = 0; i < min(200, size); ++i)
            {
                cout << random_copy[i] << " ";
            }
            cout << "\n\n";
        }
    }

    return 0;
}
