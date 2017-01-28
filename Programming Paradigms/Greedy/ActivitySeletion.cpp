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


//Accepted Code : http://ideone.com/QGba6i     ......... http://ideone.com/JuTsoI








//N.B : Intervel Scheduling is the variant of Activity Selection Algo ...Source : http://ideone.com/Zr8QDT


