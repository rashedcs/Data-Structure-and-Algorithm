    #include<bits/stdc++.h>
    using namespace std;


    int main()
    {
       // int n;
        array<int,6> arr = {1, 2, 3, 4, 5, 6};
        array<int,6> brr = {7, 8, 9, 10, 11, 12};

        /*
        for(int i=0; i<n; i++)
        {
          cin>>arr[i];
        }
        */

        for(int i=0; i<6; i++)
        {
           cout<<arr.at(i)<< " ";
        }

        /** access the first element  **/
        cout<<arr.front()<<endl;

        /** access the last element  **/
        cout<<"1st Element : "<<arr.back()<<endl;


        /** returns the number of elements **/
        cout<<"Last Element : "<<arr.size() << endl;


        /** returns the maximum possible number of elements  **/
        cout<<"Maximum Size : "<< arr.max_size()<<endl;


        /** swaps the contents of two array **/
        arr.swap(brr);
        for(int item : brr)
        {
           cout<<item<< " ";
        }
         cout<<endl;

        /** checks whether the container is empty  **/
        cout<<arr.empty()<<endl;


        /** fill the container with specified value  **/
        arr.fill(0);
        for(int item : arr)
        {
           cout<<item<< " ";
        }

       // remove(arr, arr+n, 3);

        return 0;
    }

