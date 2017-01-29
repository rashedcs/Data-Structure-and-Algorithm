//Job Scheduling
 #include<bits/stdc++.h>
     using namespace std;
 
     int n;
 
    void jobScheduling(int job[], int profit[], int dead[])
    {
      int temp;
 
      for(int i=0; i<n-1; i++)
      {
         for(int j=0;j<n-1;j++)
         {
            if(profit[j+1]>profit[j])
            {
                temp=profit[j+1];
                profit[j+1]=profit[j];
                profit[j]=temp;
 
                temp=dead[j+1];
                dead[j+1]=dead[j];
                dead[j]=temp;
 
                temp=job[j+1];
                job[j+1]=job[j];
                job[j]=temp;
            }
         }
      }
 
     /*
      for(int i=0;i<n-1;i++)
      {
         for(int j=0;j<n-1;j++)
         {
            if(profit[j]==profit[j+1])
            {
                if(dead[j]<dead[j+1])
                {
                    temp=dead[j+1];
                    dead[j+1]=dead[j];
                    dead[j]=temp;
 
                    temp=job[j+1];
                    job[j+1]=job[j];
                    job[j]=temp;
                }
            }
         }
      }
    */
       cout<<"Sorting Jobs : \n";
       for(int i=0; i<n; i++)
       {
         cout<<job[i]<<"  ";
         cout<<profit[i]<<"  ";
         cout<<dead[i]<<" ";
         cout<<endl;
       }
 
 
 
 
      int count=0, total=0;
      for(int i=0; i<n; i++)
      {
          if(dead[i]>count)
          {
            total+=profit[i];
            cout<<"Job : " << job[i]<<"  ";
            cout<<"Profit : " << profit[i]<<"  ";
            cout<<"Deadline : " << dead[i]<<"  ";
            count++;
          }
          cout<<endl;
       }
       cout<<"\nTotal Profit : " << total<<endl;
    }
 
 
 
 
 
    int main(string args[])
    {
 
      ios::sync_with_stdio(false);
      cout<<"Enter number of jobs : ";
      cin>>n;
 
      int job[n];
      int profit[n];
      int dead[n];
 
      for(int i=0;i<n;i++)
      {
        //cout<<"Enter job no.";
        cin>>job[i];
        //cout<<"Profit of job " <<(i+1) << ":";
        cin>>profit[i];
        //cout<<"Deadline of job " << (i+1) << ":";
        cin>>dead[i];
      }
 
     //Sorting in descending order of Profit (Bubble Sort)
 
 
      jobScheduling(job, profit, dead);
 
      return 0;
 
 }
