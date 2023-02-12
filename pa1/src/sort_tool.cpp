// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2021-10-23 HsuanYu CHOU]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>

// Constructor
SortTool::SortTool() {}

// void monitor(vector<int> &data)
// {
//     for (int i = 0; i < data.size() && i < 10; ++i)
//         cout << data[i] << ", ";
//     cout << endl;
// }

// Insertsion sort method
void SortTool::InsertionSort(vector<int> &data)
{
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here

    for (int i = 1; i < data.size(); ++i)
    {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j -= 1;
        }
        data[j + 1] = key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int> &data)
{
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed

    if (low < high)
    {
        int mid = Partition(data, low, high);
        QuickSortSubVector(data, low, mid - 1);
        QuickSortSubVector(data, mid + 1, high);
    }
}
int SortTool::Partition(vector<int> &data, int low, int high)
{
    // Function : Partition the vector
    // TODO : Please complete the function
    // Hint : Textbook page 171

    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (data[j] <= pivot)
        {
            i += 1;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);

    return (i + 1);
}

// Merge sort method
void SortTool::MergeSort(vector<int> &data)
{
    MergeSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed

    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSortSubVector(data, low, mid);
        MergeSortSubVector(data, mid + 1, high);
        Merge(data, low, mid, mid + 1, high);
    }
}
// Merge
void SortTool::Merge(vector<int> &data, int low, int middle1, int middle2, int high)
{
    // Function : Merge two sorted subvector
    // TODO : Please complete the function

    vector<int> dataL;
    vector<int> dataR;

    for (int i = low; i <= middle1; ++i)
        dataL.push_back(data[i]);
    for (int i = middle1 + 1; i <= high; ++i)
        dataR.push_back(data[i]);

    int i = 0;
    int j = 0;
    for (int k = low; k <= high; ++k)
    {
        if (i < dataL.size() && j < dataR.size())
        {
            if (dataL[i] <= dataR[j])
            {
                data[k] = dataL[i];
                ++i;
            }
            else
            {
                data[k] = dataR[j];
                ++j;
            }
        }
        else
        {
            if (i < dataL.size())
            {
                data[k] = dataL[i];
                ++i;
            }
            if (j < dataR.size())
            {
                data[k] = dataR[j];
                ++j;
            }
        }
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int> &data)
{
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--)
    {
        swap(data[0], data[i]);
        heapSize--;
        MaxHeapify(data, 0);
    }
}
// Max heapify
void SortTool::MaxHeapify(vector<int> &data, int root)
{
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here

    int l = 2 * (root + 1) - 1;
    int r = 2 * (root + 1);
    int largest = root;

    if (l < heapSize && data[l] > data[largest])
        largest = l;
    if (r < heapSize && data[r] > data[largest])
        largest = r;
    if (largest != root)
    {
        swap(data[root], data[largest]);
        MaxHeapify(data, largest);
    }
}
// Build max heap
void SortTool::BuildMaxHeap(vector<int> &data)
{
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here

    for (int i = data.size() / 2; i >= 0; --i)
        MaxHeapify(data, i);
}
