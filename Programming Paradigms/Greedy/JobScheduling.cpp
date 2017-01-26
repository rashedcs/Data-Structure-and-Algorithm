//Job Scheduling
     #include<bits/stdc++.h>
     using namespace std;








    int main(string args[])
    {
      ios::sync_with_stdio(false);

      int n;
      int *job=new int[n];
      int *profit=new int[n];
      int *dead=new int[n];


      cout<<"Enter number of jobs : ";
      cin>>n;

      for(int i=0;i<n;i++)
      {
        printf("Enter job no.");
        cin>>job[i];
        cout<<"Profit of job " <<(i+1) << ":";
        cin>>profit[i];
        cout<<"Deadline of job " << (i+1) << ":";
        cin>>dead[i];
      }

      int temp;
     //Sorting in descending order of Profit (Bubble Sort)
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

    printf("\nSorted Jobs");
    for(int i=0; i<n; i++)
    {
       //System.out.println();
       cout<<job[i]<< "  ";
       cout<<profit[i]<< "  ";
       cout<<dead[i];
    }


    int count=0, total=0;
    for(int i=0; i<n; i++)
    {
        if(dead[i]>count)
        {
            total+=profit[i];
            printf("\n");
            cout<<"Job : " << job[i]<<"  ";
            cout<<"Profit : " << profit[i]<<"  ";
            cout<<"Deadline : " << dead[i]<<"  ";
            count++;
        }
    }
    cout<<"\nTotal Profit : " << total;

    return 0;
 }










































/*
#include<bits/stdc++.h>

int n,i,j,k,t;
int check(int s[],int p)
       {  int ptr=0;
           for(int i=0;i<n;i++)
           {
             if(s[i]==p)  ptr++;
           }
            if(ptr==0)
            return 1;
            else
            return 0;
        }

int main()
{
     printf("enter the no of jobs      : ");
     scanf("%d",&n);
     int slot[n],profit,p[n],d[n];
     for(i=0;i<n;i++)
       {printf("\n enter the profit of job #%d      :",i+1);
       scanf("%d",&p[i]);
       printf("\n enter the deadline of job #%d    :",i+1);
       scanf("%d",&d[i]);
       }

     for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
         if(p[i]<p[j])
            { t=p[i];
              p[i]=p[j];
              p[j]=t;
              t=d[i];
              d[i]=d[j];
              d[j]=t;
            }

       for(i=0;i<n;i++)
           slot[i]=0;

     for(i=0;i<n;i++)
         for(j=d[i];j>0;j--)
             {if(check(slot,j)==1)
                {slot[i]=j;
                break;}
             }

     printf("\n\n INDEX   PROFIT  DEADLINE  SLOT ALLOTTED ");
     for(i=0;i<n;i++)
     {if(slot[i])
     printf("\n\n   %d       %d        %d        [%d - %d]", i+1,p[i],d[i],(slot[i]-1),slot[i]);
     else
     printf("\n\n   %d       %d        %d       REJECTED", i+1,p[i],d[i]);
     }

       return 0;
}
*/
