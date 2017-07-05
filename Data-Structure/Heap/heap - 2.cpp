#include<bits/stdc++.h>
using namespace std;


struct node
{
    string data;
    int key;
};



class minHeap
{
    int cap;
    int heap_size;
    node *arr;

  public:
    minHeap(int cap)
    {
        heap_size = 0;
        this->cap = cap;
        arr = new node[cap];
    }

    void minHeapify(int i)
    {
        int largest = i;

        int l = 2*i +1;
        int r = 2*i +2;

        if(l< heap_size && arr[l].key < arr[i].key)
            largest = l;
        if(r < heap_size && arr[r].key < arr[largest].key)
            largest = r;

        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            minHeapify(largest);
        }
    }

    void decreaseKey(int index, node n)
    {
        if(n.key > arr[index].key)
        {
            printf("Error\n");
            return;
        }
        else
        {
            arr[index] = n;
            while( index!=0 && arr[(index-1)/2].key>arr[index].key)
            {
                swap(arr[index], arr[(index-1)/2]);
                index = (index-1)/2;
            }
        }
    }

    node heapMinimum()
    {
        return arr[0];
    }


    void heapInsert(node n)
    {
        heap_size++;
        arr[heap_size - 1].key = INT_MAX;
        decreaseKey(heap_size-1, n);
    }

    node extractMin()
    {
        if(heap_size < 0)
            printf("Heap Underflow\n");

        node min = arr[0];
        arr[0] = arr[heap_size - 1];
        --heap_size;
        minHeapify(0);
        return min;
    }

    void getMin()
    {
      cout<<arr[0].data<<" "<<arr[0].key;
    }

    void printPriorityQueue()
    {
        printf("\nMain Output:\n");
        while(heap_size)
        {
            node ext = extractMin();
            cout<<ext.data<<" "<<ext.key<<endl;
        }
     }
 };



int main()
{
    ios::sync_with_stdio(false);

    minHeap h(2);

    h.heapInsert(node{"aishe", 100});
    h.heapInsert(node{"rashed" , 120});

    h.getMin();
    h.printPriorityQueue();
    //inputQueueItems();

    return 0;
}

//Reference :  https://quickgrid.wordpress.com

   
