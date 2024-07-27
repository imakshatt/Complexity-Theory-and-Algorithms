#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int CHUNK_SIZE = 1000;

// Function to generate a random input file with n elements
void generateAscendingInput(const string &inputFile, int n)
{
    ofstream outFile(inputFile);
    if (!outFile)
    {
        cerr << "Error: Cannot open output file for writing." << endl;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        outFile << i << endl;
    }

    outFile.close();    
}

void generateDescendingInput(const string &inputFile, int n)
{
    ofstream outFile(inputFile);
    if (!outFile)
    {
        cerr << "Error: Cannot open output file for writing." << endl;
        return;
    }

    for (int i = n; i >= 1; --i)
    {
        outFile << i << endl;
    }

    outFile.close();
}

void generateRandomInput(const string &inputFile, int n)
{
    ofstream outFile(inputFile);
    if (!outFile)
    {
        cerr << "Error: Cannot open output file for writing." << endl;
        return;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < n; ++i)
    {
        int value = rand() % 10000; // Adjust the range as needed
        outFile << value << endl;
    }

    outFile.close();
}

// Function to merge sorted chunks
void 2mergeChunks(const vector<string> &chunkFiles, const string &outputFile)
{
    vector<ifstream> chunkStreams;
    for (const auto &chunkFile : chunkFiles)
    {
        chunkStreams.emplace_back(chunkFile);
    }

    vector<int> currentValues(chunkStreams.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    // Initialize currentValues with the first element from each chunk
    for (int i = 0; i < chunkStreams.size(); ++i)
    {
        if (chunkStreams[i] >> currentValues[i])
        {
            minHeap.emplace(currentValues[i], i);
        }
    }

    ofstream outFile(outputFile);

    while (!minHeap.empty())
    {
        auto [value, chunkIndex] = minHeap.top();
        minHeap.pop();
        outFile << value << endl;

        if (chunkStreams[chunkIndex] >> currentValues[chunkIndex])
        {
            minHeap.emplace(currentValues[chunkIndex], chunkIndex);
        }
    }

    for (const auto &chunkFile : chunkFiles)
    {
        remove(chunkFile.c_str()); // Clean up temporary chunk files
    }
}

// Function to perform external merge sort
double externalMergeSort(const string &inputFile, const string &outputFile, int maxElementsPerChunk)
{
    ifstream inFile(inputFile);
    if (!inFile)
    {
        cerr << "Error: Cannot open input file." << endl;
        return -1.0;
    }

    int chunkNumber = 0;
    vector<string> chunkFiles;

    auto start_time = high_resolution_clock::now(); // Start measuring time

    while (!inFile.eof())
    {
        vector<int> chunkData;
        chunkData.reserve(maxElementsPerChunk);

        for (int i = 0; i < maxElementsPerChunk; ++i)
        {
            int value;
            if (inFile >> value)
            {
                chunkData.push_back(value);
            }
            else
            {
                break;
            }
        }

        sort(chunkData.begin(), chunkData.end());
        string chunkFile = "chunk_" + to_string(chunkNumber) + ".tmp";
        ofstream chunkOutFile(chunkFile);

        for (int value : chunkData)
        {
            chunkOutFile << value << endl;
        }

        chunkFiles.push_back(chunkFile);
        ++chunkNumber;
    }

    inFile.close();

    // Merge sorted chunks
    mergeChunks(chunkFiles, outputFile);

    auto end_time = high_resolution_clock::now(); // Stop measuring time
    auto total_time = duration<double>(end_time - start_time);

    return total_time.count();
}

int main()
{
    int maxElementsPerChunk = CHUNK_SIZE;
    int totalElements;
    cout << "Number of elements in the input file : ";
    cin >> totalElements;

    cout << "Choose the input order:" << endl;
    cout << "1. Ascending Order" << endl;
    cout << "2. Descending Order" << endl;
    cout << "3. Random Order" << endl;
    int choice;
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    string inputFile, outputFile;
    switch (choice)
    {
    case 1:
        inputFile = "input_ascending.txt";
        outputFile = "output_ascending.txt";
        generateAscendingInput(inputFile, totalElements);
        break;
    case 2:
        inputFile = "input_descending.txt";
        outputFile = "output_descending.txt";
        generateDescendingInput(inputFile, totalElements);
        break;
    case 3:
        inputFile = "input_random.txt";
        outputFile = "output_random.txt";
        generateRandomInput(inputFile, totalElements);
        break;
    default:
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }

    double elapsedTime = externalMergeSort(inputFile, outputFile, maxElementsPerChunk);

    cout << endl
         << "Total Time taken by External Merge sort for " << totalElements << " elements is: " << elapsedTime << " seconds" << endl;
    cout << endl
         << "External merge sort complete. Sorted data is stored in " << outputFile << endl;

    return 0;
}
