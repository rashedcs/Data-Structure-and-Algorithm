        #include<bits/stdc++.h>
        using namespace std;



        int main()
        {
            int arr[] = {2, 3, 8, 6, 7};
            int n = sizeof(arr)/sizeof(arr[0]);

            int brr[] = {4, 6, 16, 12, 14};
            int m = sizeof(brr)/sizeof(brr[0]);



           /** returns the smaller of the given values **/
            int mn = min(arr[0], arr[3]);
            cout<<mn<<endl;

            /** returns the greater of the given values **/
            int mx = max(arr[0], arr[3]);
            cout<<mx<<endl;


            /** returns the snallest element in a range  **/
            int minn = *min_element(arr, arr+n);
            cout<<minn<<endl;


            /** returns the largest element in a range  **/
            int maxn = *max_element(arr, arr+n);
            cout<<maxn<<endl;


            /** returns the smallest element index  **/
            int indexMin = min_element(arr, arr + n) - arr;
            cout<<"Min Index : "<<indexMin<<endl;


           /** returns the largest element index  **/
            int indexMax = max_element(arr, arr + n) - arr;
            cout<<"Max Index : "<<indexMax<<endl;



           /** returns the largest and smallest element in a range **/
            auto result = minmax_element(arr, arr+n);
            cout<<"Min Max : "<<*result.first<<" "<< *result.second<<endl;



            /** returns the smallest and largest element index in a range **/
            auto temp = minmax_element(arr, arr+n);
            cout<<"Min Max Index : "<<temp.first-arr<<" "<<temp.second-arr<<endl;


            /** determines if a sequence is a permutation of another sequence  **/
            cout<<"Check permutation : "<<boolalpha<<is_permutation(arr, arr+n, brr)<<endl;



            /** generates the next greater lexicographic permutation of a range of elements  **/
            string s = "aba";
            sort(s.begin(), s.end());
            //sort(s.begin(), s.end(), less<char>());
            do
            {
              cout<<s<<" ";
            }
            while(next_permutation(s.begin(), s.end()));


            /** Returns whether a range is lexicographically less than another range. **/
            bool equ = lexicographical_compare(arr, arr+n, brr, brr+m, equal_to <int>());
            cout<<"\nisEqual : "<<boolalpha<<equ<<endl;


            bool les = lexicographical_compare(arr, arr+n, brr, brr+m); //lexicographical_compare(arr, arr+n, brr, brr+m, func)
            (les==1)? cout<<"arr is less\n" : cout<<"brr is less\n";


            return 0;
        }
