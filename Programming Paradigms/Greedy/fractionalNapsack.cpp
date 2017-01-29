   //Article : http://thecodersportal.com/knapsack-greedy/
    #include<bits/stdc++.h>
    using namespace std;

    int n;


    bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
       return (double)(a.first/a.second) > (double)(b.first/b.second);
       /*
          double r1 =  (double)a.first / a.second;
          double r2 =  (double)b.first / b.second;
          return r1 > r2;
       */
    }



    void activitySelection(pair<int, int>P[], int W)
    {
        sort(P, P+n, comp);

       //double curWeight = 0.0;  // Current weight in knapsack
       float pro = 0.0; // Result (value in Knapsack)

       // Looping through all Items
       for (int i=0; i<n; i++)
       {
         // If adding Item won't overflow, add it completely
          if(P[i].second <= W)
          {
             pro += P[i].first;
             W   -= P[i].second;
          }

          // If we can't add current Item, add fractional part of it
          else
          {
             cout<<pro<<endl;
             pro += P[i].first* ((double) (W) / P[i].second);
             break;
          }
       }
       printf("Maximize profit is : %lf\n",pro);
    }








   int main()
   {
          //ios::sync_with_stdio(false);

          int  weight, profit;
          int W;

          cin>>n>>W;

          pair <int, int> P[n+1];

          for(int i=0; i<n; i++)
          {
            cin>>profit>>weight;
            P[i] = make_pair(profit, weight);
          }


          //sort(C,C+n,comp);
         activitySelection(P,W);



          return 0;
   }








//Traditional approach :

/* Fraction Knapsack- Greedy Approach by TheCodersPortal */
#include <iostream>
using namespace std;

//This code available in : http://ideone.com/cmYtTV
/* arrange function will arrange the list val and wt with respect to non-decreasing order in vlwt */
void sorting(float val[],float wt[],float vlwt[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(vlwt[i]<vlwt[j])
            {
                float temp=vlwt[i];
                vlwt[i]=vlwt[j];
                vlwt[j]=temp;
                int tmp=wt[i];
                wt[i]=wt[j];
                wt[j]=tmp;
                tmp=val[i];
                val[i]=val[j];
                val[j]=tmp;
            }
        }
    }
}

/*knapsack is the function which takes the val and wt arrays,
    W and n and returns the max value using greedy approach */
float knapsack(float val[],float wt[],int W,int n)
{
    float V=0;
    /* vlwt is the array which will store the val/wt ratio of the items */
    float vlwt[n];

    /* Assigning the values in vlwt list */
    for(int i=0;i<n;i++)
    {
        vlwt[i]=val[i]/wt[i];
    }
    sorting(val,wt,vlwt,n);

    /* Calculating the max value */
    for(int i=0; i<n; i++)
    {
        /* If item can put in the knapsack as whole */
        if(wt[i]<=W)
        {
            V+=val[i];
            W-=wt[i];
        }

        /* When item need to be broken to put it in knapsack */
        else
        {
            V+=(val[i]*(W/wt[i]));
            break;
        }
    }
    return V;
}

/* Driver program to test the above function */
int main()
{
    float wt[]={1,2,8,5};
    float val[]={2,7,4,2};
    int W=9;
    int n=sizeof(val)/sizeof(val[0]);
    cout<<knapsack(val,wt,W,n)<<endl;
    return 0;
}

















































//Daught : http://ideone.com/376UYt




















