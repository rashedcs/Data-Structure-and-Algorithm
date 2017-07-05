
http://practice.geeksforgeeks.org/viewSol.php?subId=2490829&pid=700240
https://www.codechef.com/viewsolution/7303604
http://www.sanfoundry.com/cpp-program-implement-binary-heap/

 

//Source : geeksforgeeks
#include<bits/stdc++.h>
using namespace std;


// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with root at given index
    void heapify(int );

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}



void MinHeap ::insertKey(int x)
{
    if(heap_size>=capacity-1)  return;
    else
    {
       heap_size++;
       harr[heap_size-1]=x;
       int i;
       for(i=(heap_size-1)/2;i>=0;i--)
       {
         heapify(i);
       }
    }
}


// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap :: decreaseKey(int index, int val)
{
    harr[index] = val;
    while (index != 0 && harr[(index-1)/2] > harr[index])
    {
       swap(harr[index], harr[(index-1)/2]);

       index = (index-1)/2;
    }
}
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if(heap_size <= 0)  return INT_MAX;
    else if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    else
    {
       // Store the minimum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        heapify(0);
        return root;
    }
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int index)
{
    if(heap_size==0)  return;

    else if(index < heap_size)
    {
        swap(harr[index],harr[heap_size-1]);
        heap_size--;
        heapify(index);
    }
}


// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        heapify(smallest);
    }
}


// Driver program to test above functions
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
