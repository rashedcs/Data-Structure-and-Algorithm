        #include<bits/stdc++.h>
        using namespace std;



        int main()
        {
           int arr[] = {2, 3, 8, 6, 7};
           int n = sizeof(arr)/sizeof(arr[0]);

           /** check if the elements in range [first, last) are sorted in non-descending order **/
           cout<<"is_sorted: "<<boolalpha<<is_sorted(arr, arr+n)<<endl; // boolalpha convert 0 to false and 1 to true



           /** sorts the first N elements of a range **/
           /* array not support partial_sort  sort convert it to vector*/
           vector<int> v(arr, arr+n);
           partial_sort(v.begin(), v.begin()+4, v.end());
           for(auto item: v)
           {
             cout<<item<<" ";
           }
           cout<<endl;



           /** copies and partially sorts a range of elements **/
            vector<int> v1 = {10, 11, 12};
            partial_sort_copy(v.begin(), v.end(), v1.begin(), v1.end());
            for(auto item: v1)
            {
              cout<<item<<" ";
            }
            cout<<endl;



           /**partially sorts the given range making sure that it is partitioned by the given element **/
            nth_element(v.begin(), v.begin() + v.size()/2, v.end());
            cout<<"The median is : "<<v[v.size()/2]<<endl;
            ///nth_element(v.begin(), v.begin() + v.size()/2, v.end(), less<int>();

            nth_element(v.begin(), v.begin()+1,  v.end(), greater<int>());
            cout<<"The second largest element is : "<< v[1] <<endl;



           /** sort the array **/
           sort(arr, arr+n);
           for(auto item: arr)
           {
             cout<<item<<" ";
           }
           cout<<endl;

          /** sorts a range of elements while preserving order between equal elements  **/
          // http://en.cppreference.com/w/cpp/algorithm/stable_sort


           return 0;
        }
