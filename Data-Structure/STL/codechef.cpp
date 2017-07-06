        #include<bits/stdc++.h>
        using namespace std;


        int main()
        {
            ios::sync_with_stdio(false);

            array<int, 10>arr;
            int n;

            cin>>n;
            for(int i=0; i<n; i++)
            {
              cin>>arr[i];
            }

            for(auto item : arr)
            {
              cout<<item<<" ";
            }

            return 0;
        }
