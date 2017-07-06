    #include<bits/stdc++.h>
    using namespace std;


    int calculation(int x)
    {
       return x*x;
    }
    int comp(int x)
    {
       return x>100;
    }

    int main()
    {
      int arr[] = {5, 2, 7, 9, 1, 10, 12, 15, 28};
      int n = sizeof(arr)/sizeof(arr[0]);
      int k = 2;


      /** Reverse the string **/
      reverse(arr, arr+n);
      for(int i=0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;


      /** Transform the array **/
      transform (arr, arr+n, arr, calculation);
      // for_each(arr, arr+6, calculation); instead of transform
      copy(arr, arr+6, ostream_iterator<int>(cout," "));
      cout<<endl;


      /** delete particular number **/
      remove(arr, arr+n, 1);
      for(int i=0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;


      /** delete particular index element  **/
      n = remove(arr, arr+n, arr[k]) - arr;
      for(int i=0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<" \n ";




      /** copy-assigns the given value to every element in a range  **/
      fill(arr, arr+n, -1);
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));
      cout<<endl;



      /** copy-assigns the given value to N elements in a range  **/
      fill_n(arr, 3, 6);
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));
      cout<<endl;



       /**assigns the results of successive function calls to every element in a range **/
       //  generate(v.begin(), v.end(), rand); //random number
      int p = {0};
      generate(arr, arr+n, [&p]{ return p++;});
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));




     /** copies a range of elements omitting those that satisfy specific criteria  **/
      vector<int>Array(arr, arr+n);
      Array.erase(remove_if(Array.begin(), Array.end(), [](int n) { return n <100; }),
                 Array.end());
     // a.erase( remove_if(a.begin(), a.end(), comp, a.end());
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));
      cout<<"\nFill : ";









      return 0;
    }
