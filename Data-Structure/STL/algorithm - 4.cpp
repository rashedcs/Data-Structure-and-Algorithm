
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



      /** Reverse the array **/
      cout<<"Reverse array : ";
      reverse(arr, arr+n);
      for(int i=0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }




     /** creates a copy of a range that is reversed  **/
     /*
     vector<int> destination(3);
     reverse_copy(begin(v), end(v), begin(destination));
     for(const auto& value : destination)
     {
         cout<<value<<" ";
     }
     */
     cout<<endl<<" reverse copy : ";
     int destination[9];
     reverse_copy(arr, arr+9,destination);
     for(const auto& value : destination)
     {
         cout<<value<<" ";
     }


      /** Transform the array **/
       cout<<endl<<" Transform : ";
      transform (arr, arr+n, arr, calculation);
      /// for_each(arr, arr+6, calculation); instead of transform
      copy(arr, arr+6, ostream_iterator<int>(cout," "));
      cout<<endl;


      /** delete particular number **/
      cout<<"Delete particular element : ";
      remove(arr, arr+n, 1);
      for(int i=0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;


      /** delete particular index element  **/
      cout<<"Delete particular index element : ";
      n = remove(arr, arr+n, arr[k]) - arr;
      for(int i=0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }



     /** copies a range of elements omitting those that satisfy specific criteria  **/
     cout<<" \nRemove _if: ";
      vector<int>Array(arr, arr+n);
      Array.erase(remove_if(Array.begin(), Array.end(), [](int n){ return n>100;}),Array.end());
    //  Array.erase( remove_if(Array.begin(), Array.end(), comp), Array.end());
      copy(Array.begin(), Array.end(), ostream_iterator<int>(cout, " "));



      /** fills a range with successive increments of the starting value **/
        cout<<"\nFill increament : ";
        iota(Array.begin(), Array.end(), -4);
        for(auto i: Array)
        {
          cout<<i<<" ";
        }



      /** copy-assigns the given value to every element in a range  **/
      cout<<"\nFill : ";
      fill(arr, arr+n, -1);
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));



      /** copy-assigns the given value to N elements in a range  **/
      cout<<"\nFill Range: ";
      fill_n(arr, 3, 6);
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));



       /**assigns the results of successive function calls to every element in a range **/
       //  generate(v.begin(), v.end(), rand); //random number
       cout<<"\nGenerate : ";
      int p = {0};
      generate(arr, arr+n, [&p]{ return p++;});
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));


      return 0;
    }
