//
// Created by AKSHAT on 11/2/2023.
//
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <cmath>
using namespace std::chrono;

int binarysearch(int arr[], int n, int key,  int *iterations){

    int start = 0;
    int end = n-1;



    while (start <= end)
    {
        int mid = floor((start + end) / 2);
        (*iterations)++;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }


    }

    return -1;
}

int main()
{
    cout<<"\n enter the size of array: ";
    int n;
    cin >> n;

    int arr[n];

    for (int i; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i; i < n; i++)
    {
        cout << " " << arr[i];
    }

    cout << "\nenter the key";

    int key;
    cin >> key;

    int iterations=0;

    auto started = high_resolution_clock::now();

    int result=binarysearch(arr, n, key, &iterations);

    auto done = high_resolution_clock::now();
    duration<double> time_taken = done - started;

    cout<<"\n index of key: "<<result;
    cout<<"\n itteration is: "<<iterations;

    cout <<"\ntime taken: " <<time_taken.count();

    return 0;
}