#include<bits/stdc++.h>
using namespace std;


struct node
{
	char character;
	int freq;
    node *left;
	node *right;
	node(char chas, int fr)
	{
	  character= chas;
	  freq=fr;
	  left=NULL;
	  right = NULL;
    };
};


struct comp
{
    bool operator() (node *a, node *b)
    {
      return (a->freq > b->freq);
    }
};





//print heap and codes
void print_heap(node *head, string path)
{
	if(head->character !=NULL)
	{
		cout<< head->character << " code is " << path<<"\n";
    }
    else
    {
	   print_heap(head->left, path+"0");
	   print_heap(head->right, path+"1");
    }
}




// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
   node *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
   priority_queue<node*, vector<node*>, comp> minHeap;
   //priority_queue<node*, vector<node*>, greater<node*> > minHeap;

    for (int i = 0; i < size; ++i)
    {
        minHeap.push(new node(data[i], freq[i]));
    }

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new node(NULL, left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    print_heap(minHeap.top()," ");
}

// Driver program to test above functions
int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}















































//Daught program
//Daught code
//Source: http://ideone.com/jlmurQ
//Priority queue : https://www.quora.com/How-can-I-find-minimum-element-from-a-priority-queue-in-C-C++
#include<bits/stdc++.h>
using namespace std;


struct node
{
	char character;
	int freq;
        node *left;
	node *right;
	node(char chas, int fr)
	{
	  character= chas; freq=fr;left=NULL; right = NULL;
    };
};


//priority_queue<node *, vector<node *>, nodeCompare> minHeap;
struct nodeCompare
{
    bool operator() (node *a, node *b)
    {
      return (a->freq > b->freq);
    }
};



//print heap and codes
void print_heap(node *head, string path)
{
	if(!head)  return;

	if(head->character !=NULL)
		cout<< head->character << " code is " << path<<"\n";

	print_heap(head->left, path+"0");
	print_heap(head->right, path+"1");
}



	//priority_queue< node*, vector<node*>, greater<node*>  >minHeap;

int main()
{

	priority_queue< node *, vector<node *>, nodeCompare >minHeap;
   //priority_queue<node*, vector<node*>, greater<node*> > minHeap;

	//fill queue
	minHeap.push(new node('a',5));
	minHeap.push(new node('b',9));
	minHeap.push(new node('c',12));
	minHeap.push(new node('d',13));
	minHeap.push(new node('e',16));
	minHeap.push(new node('f',45));

	//iterate till heapsie is 1
	while(minHeap.size()>1)
	{
		//remove 1
		node *min1= minHeap.top();
		minHeap.pop();
		//remove 2
		node *min2= minHeap.top();
		minHeap.pop();
		//merge both
		node * new_node= new node(NULL, min1->freq + min2->freq);
		new_node->left= min1;
		new_node->right= min2;
		//push back in minHeap
		minHeap.push(new_node);
	}
	print_heap(minHeap.top(), "");
	return 0;
}
