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































