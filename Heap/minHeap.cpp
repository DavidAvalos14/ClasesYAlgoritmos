// Angel David Avalos Carrillo
// Heap for min

#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>& heap, int value)
{
    // Add the new element to the end of the heap
    heap.push_back(value);
    
    // Get the index of the last element
    int index = heap.size() - 1;
    
    // Compare the new element with
    //its parent and swap if necessary
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        
        // Move up the tree to the
        //parent of the current element
        index = (index - 1) / 2;
    }
}

void heapify(vector<int> &arr, int i, int n) {
    int smallest = i;        
    int l = 2 * i + 1;      
    int r = 2 * i + 2;  
     
    // If left child exists and is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // If right child exists and is smaller than smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If smallest is not root, 
    //swap and continue heapifying
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
         // Recursively heapify 
        heapify(arr, smallest, n);
    }
}

int main() {
    vector<int> heap;
    vector<int> arr = {5, 10, 7, 3, 15, 12};

    for(int i = arr.size() / 2 - 1; i >= 0; i--) {
        heapify(arr, i, arr.size());
    }

    for(int a: arr) cout << a << " ";

    

    return 0;
}