#include<bits/stdc++.h>
using namespace std;


class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    
    
    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }

    int right(int i) { return (2*i + 2); }

    int getMin() { return harr[0]; }

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size &&  harr[l] < harr[i])        smallest = l;
        if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
        if(smallest != i)
        {
            swap(harr[i], harr[smallest]);
            heapify(smallest);
        }
    }

    void insertKey(int x)
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

    void decreaseKey(int index, int val)
    {
        harr[index] = val;
        while (index != 0 && harr[(index-1)/2] > harr[index])
        {
           swap(harr[index], harr[(index-1)/2]);
           index = (index-1)/2;
        }
    }

    int extractMin()
    {
        if(heap_size <= 0)  return INT_MAX;
        else if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }
        else
        {
            int root = harr[0];
            harr[0] = harr[heap_size-1];
            heap_size--;
            heapify(0);
            return root;
        }
    }

    void deleteKey(int index)
    {
        if(heap_size==0)  return;

        else if(index < heap_size)
        {
            swap(harr[index],harr[heap_size-1]);
            heap_size--;
            heapify(index);
        }
    }
};



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




/*
Reference : 
   http://www.geeksforgeeks.org/binary-heap/
   http://www.techiedelight.com/introduction-priority-queues-using-binary-heaps/
   codechef.com/viewsolution/7303604#include<bits/stdc++.h>
   http://ideone.com/3lABiO
 */
