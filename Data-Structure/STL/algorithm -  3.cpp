    #include<bits/stdc++.h>
    using namespace std;


    int main()
    {
        ios::sync_with_stdio(false);

        int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
        int n = sizeof(arr)/sizeof(arr[0]);

        sort(arr, arr+n);

        /** Returns whether the range contains an element **/
        cout<<"Binary Search : "<<boolalpha<<binary_search(arr, arr+n, 3)<<endl;


       /** Finds the first element greater than or equal to a given value **/
        auto lo = lower_bound(arr, arr+n, 20); //20 or greater than 20
        cout<<"The lower bound of : 20 is "<<*lo<<endl;
        cout<<"The lower bound of 20 index : "<<lo-arr<<endl;


        /** Finds the first element greater than a given value **/
        auto up = upper_bound(arr, arr+n, 20); // greater bthan 20
        cout<<"The upper bound of : 20 is "<<*up<<endl;
        cout<<"The upper bound of 20 index : "<<up-arr<<endl;




        /** Returns the range of elements equal to a given value **/
         vector<int> v(arr, arr+n);
         pair<vector<int>::iterator,vector<int>::iterator> bounds = equal_range(v.begin(), v.end(),3);
         cout <<"\nLower bound of 3 in v = "<<*bounds.first;
         cout <<"\nUpper bound of 3 in v = "<<*bounds.second;

         cout<<"bounds at positions "<<int(bounds.first - v.begin());
         cout<<" and "<<int(bounds.second - v.begin()) << endl;



        return 0;
    }
