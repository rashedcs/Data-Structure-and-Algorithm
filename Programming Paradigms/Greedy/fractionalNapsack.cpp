//Source : http://ideone.com/yQ6Nhx
   //Article : http://thecodersportal.com/knapsack-greedy/
    #include<bits/stdc++.h>
    using namespace std;

    int n;


    bool comp(const pair<double,double> &a, const pair<double,double> &b)
    {
       return (double)(a.first/a.second) > (double)(b.first/b.first);
    }



    void activitySelection(pair<double, double>P[], int W)
    {
       sort(P, P+n, comp);

       double pro = 0.0;

       for(int i=0; i<n&&W!=0.0; i++)
       {
         if(P[i].second<=W)
         {
            W-=P[i].second; // Take the item .
            pro+=P[i].first;
         }

         else
         {
             pro+=(P[i].first * (W/P[i].second));
             W=0.0;
         }
       }
       printf("Maximize profit is : %lf\n",pro);
    }








   int main()
   {

          //ios::sync_with_stdio(false);

          double  weight, profit, W;

          cin>>n>>W;

          pair <double, double> P[n+1];

          for(int i=0; i<n; i++)
          {
            cin>>profit>>weight;
            P[i] = make_pair(profit, weight);
          }


          //sort(C,C+n,comp);
         activitySelection(P,W);



          return 0;
   }




















































#include<bits/stdc++.h>
using namespace std;

void knapsack(int n, float weight[], float profit[], float capacity)
{
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   memset(x,0.0,sizeof(x));

   for (i=0; i<n; i++)
   {
      if(weight[i]>u)  break;
      else
      {
         x[i] = 1.0;
         tp = tp + profit[i];
         u  = u  - weight[i];
      }
   }

   if(i<n)  x[i] = u/weight[i];
   tp = tp + (x[i] * profit[i]);

   printf("\nThe result vector is: ");
   for (i=0; i<n; i++)
   {
      printf("%f\t", x[i]);
   }
   printf("\nMaximum profit is: %f", tp);
}


int main()
{
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   cin>>num>>capacity;

   for (i=0; i<num; i++)
   {
      cin>>weight[i]>>profit[i];
   }

   for (i=0; i<num; i++)
   {
      ratio[i] = profit[i]/weight[i];
   }


   ///arrange the data maximum->minimum
   for (i=0; i<num; i++)
   {
      for (j=i+1; j<num; j++)
      {
         if(ratio[i]<ratio[j])
         {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

           //swap(ratio[i],ratio[j]);

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

           //swap(weight[i],weight[j]);

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;

           //swap(profit[i],profit[j]);
         }
      }
   }

   knapsack(num, weight, profit, capacity);
   return(0);
}






























    #include<bits/stdc++.h>
    using namespace std;

    int n;


    bool comp(const pair<int,int> &a, const pair<int,int> &b)
    {
      double r1 =  (double)a.first / a.second;
      double r2 =  (double)b.first / b.first;
      return r1 > r2;
    }



   double activitySelection(pair<int, int>P[], int W)
   {
       sort(P, P+n, comp);

       int curWeight = 0;  // Current weight in knapsack
       double finalvalue = 0.0; // Result (value in Knapsack)

       // Looping through all Items
       for (int i=0; i<n; i++)
       {
         // If adding Item won't overflow, add it completely
         if(curWeight + P[i].second <= W)
         {
            curWeight += P[i].second;
            finalvalue += P[i].first;
         }

         // If we can't add current Item, add fractional part of it
         else
         {
            int remain = W - curWeight;
            finalvalue += P[i].first * ((double) remain / P[i].second);
            break;
         }
      }

      return finalvalue;

   }








   int main()
   {

          ios::sync_with_stdio(false);

          int  weight, profit, W;

          cin>>n;

          pair <int,int> P[n+1];

          for(int i=0; i<n; i++)
          {
            cin>>profit>>weight;
            P[i] = make_pair(profit, weight);
          }

          cin>>W;
          //sort(C,C+n,comp);
         cout<< activitySelection(P,W)<<endl;


          return 0;
   }





//Knas variant : http://ideone.com/vBiQRY



















