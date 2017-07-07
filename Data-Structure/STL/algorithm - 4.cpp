
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
      ios::sync_with_stdio(false);
      int arr[] = {5, 2, 7, 9, 1, 10, 10, 12, 12, 15, 27};

      int n = sizeof(arr)/sizeof(arr[0]);
      int k = 2;


      /**copy of some range of elements that contains no consecutive duplicates **/
       cout<<"Unique Copy : ";
       vector<int>ar(arr, arr+n);
       vector<int> dest;

       unique_copy(ar.begin(), ar.end(), back_inserter(dest));
       copy(dest.begin(), dest.end(), ostream_iterator<int>(cout, " "));


       //Effiecient way
       cout<<"\nUnique Copy : ";
       unique_copy(ar.begin(), ar.end(), dest.begin());
       //unique_copy(ar.begin(), ar.end(), dest.begin(), equal_to<int>());
       copy(dest.begin(), dest.end(), ostream_iterator<int>(cout, " "));







      /** removes consecutive duplicate elements in a range  **/
       cout<<"\nUnique element : ";
       vector<int> v1(arr, arr+n);
       sort(v1.begin(), v1.end());
       auto t = unique(v1.begin(), v1.end());
       v1.erase(t, v1.end());
       copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));





      /** Reverse the array **/
      cout<<"\nReverse array : ";
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
     cout<<endl<<"Reverse copy : ";
     int destination[9];
     reverse_copy(arr, arr+9,destination);
     for(const auto& value : destination)
     {
         cout<<value<<" ";
     }


      /** Transform the array **/
       cout<<endl<<"Transform : ";
      transform (arr, arr+n, arr, calculation);
      /// for_each(arr, arr+6, calculation); instead of transform
      copy(arr, arr+6, ostream_iterator<int>(cout," "));
      cout<<endl;


      /** delete particular number **/
      cout<<"Remove element : ";
      remove(arr, arr+n, 1);
      for(int i=0; i<n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;


      /** delete particular index element  **/
      cout<<"Remove index element : ";
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
      int p = {1};
      generate(arr, arr+n, [&p]{ return p++;});
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));


      /**   rotates the order of elements in a range  **/
      cout<<"\nLeft Rotate : ";
      rotate(arr, arr+2, arr+n); //2nd to last
      copy(arr, arr+n, ostream_iterator<int>(cout, " "));


      cout<<"\nRight Rotate : ";
      vector<int>v(arr, arr+n);
      rotate(v.rbegin(), v.rbegin()+2, v.rend());
      copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));



      /** copies and rotate a range of elements  **/
      cout<<"\nRotate Copy : ";
      vector<int>myarr(9);
      rotate_copy(v.begin(), v.begin()+2, v.begin()+9, myarr.begin());
      copy(myarr.begin(), myarr.end(), ostream_iterator<int>(cout, " "));

      /*
      int sour[] = { 1,2,3,4,5,6,7,8,9 };
      int myarr[9];
      rotate_copy(sour, sour+2, sour+9, myarr);
      copy(myarr, myarr+9, ostream_iterator<int>(cout, " "));
      */


      return 0;
    }
