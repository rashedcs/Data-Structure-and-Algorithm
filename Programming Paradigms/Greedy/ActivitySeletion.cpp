    //Same  :     http://ideone.com/IPNKOj  ......  http://ideone.com/QGba6i ..... http://ideone.com/JuTsoI 
   #include<bits/stdc++.h>
   using namespace std;


   bool comp(const pair<int, int> &a, const pair<int, int> &b)
   {
      return  a.second<b.second;
	   // if (a.second == b.second) return  a.first<b.first ;
           //else                       return  a.second<b.second;

	
   }


   void activitySelection(pair<int, int>P[], int n)
   {
      sort(P,P+n,comp);
      cout<<"Sorting Activity : "<<endl;
      for(int i=0; i<n; i++)
      {
         cout<<P[i].first<<" "<<P[i].second<<endl;
      }

      int ans = 0, e =-1;
      cout<<"Selected Activity No : "<<endl;
      for(int i=0; i<n; i++)
       {
          if(P[i].first>= e)
          {
            e = P[i].second;
            ans++;
            cout<<P[i].first<<" "<<P[i].second<<endl;
          }
       }
       cout<<ans<<endl;
   }


   int main()
   {
        ios::sync_with_stdio(false);

        int tc, n, start, finish;

        cin>>n;
        pair <int,int> P[n+1];

        for(int i=0; i<n; i++)
        {
            cin>>start>>finish;
            P[i] = make_pair(start,finish);
        }

        activitySelection(P,n);

        return 0;
   }








  //Traditional Source Code: Get TLE
  #include<bits/stdc++.h>
   using namespace std;

   int n;

   void activitySelection(int s[], int f[], int job[])
   {
     //Sorting in descending order of Profit (Bubble Sort)

      for(int i=0; i<n-1; i++)
      {
         for(int j=0;j<n-1;j++)
          {
             if(f[j+1]<=f[j])
             {
                //temp=f[j+1];
               // f[j+1]=f[j];
               // f[j]=temp;
                swap(f[j],f[j+1]);

                //temp=s[j+1];
                //s[j+1]=s[j];
               // s[j]=temp;
                swap(s[j],s[j+1]);

                //temp=job[j+1];
                //job[j+1]=job[j];
                //job[j]=temp;
                swap(job[j],job[j+1]);
             }
          }
      }

      cout<<"Sorting Activity : "<<endl;

      for(int i=0; i<n; i++)
      {
        cout<<job[i]<<"  ";
        cout<<s[i]<<"  ";
        cout<<f[i]<<" ";
        cout<<endl;
      }

     int cnt = 0;

     cout<<"Selected Activity No : "<<job[cnt]<<" ";
	 for(int j=1; j<n; j++)
	 {
		if(s[j] >= f[cnt])
		{
			cout<<job[j]<<" ";//<<s[j]<<" "<<f[j]<<" ";
			cnt = j;
		}
     }

   }


   int main()
   {
     ios::sync_with_stdio(false);

     int job[]= {1, 2, 3, 4, 5, 6, 7, 8};
     int s[] =  {1, 0, 1, 4, 2, 5, 3, 4};
     int f[] =  {3, 4, 2, 6, 9, 8, 5, 5};

     n = sizeof(s)/sizeof(s[0]);
     activitySelection(s, f, job);

     return 0;
   }

/*


Sorted activities as per finish time (ascending order)
  Activity      Start     Finish
        a3          1          2
        a1          1          3
        a2          0          4
        a7          3          5
        a8          4          5
        a4          4          6
        a6          5          8
        a5          2          9
-----Selected Activities-----
  Activity      Start     Finish
        a3          1          2
        a7          3          5
        a6          5          8

*/











  
//Something Difference :     .....   http://ideone.com/Zr8QDT










