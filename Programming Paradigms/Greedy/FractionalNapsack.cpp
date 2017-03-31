   //Article : http://thecodersportal.com/knapsack-greedy/
    #include<bits/stdc++.h>
    using namespace std;

    int n;


    bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        //return (double)(a.first/a.second) > (double)(b.first/b.second);
          double r1 =  (double)a.first / a.second;
          double r2 =  (double)b.first / b.second;
          return r1 > r2;
    }



    void fractionalKnapsack(pair<int, int>P[], int W)
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
         fractionalKnapsack(P,W);



          return 0;
   }


//Using structure : http://ideone.com/xmkIoy

//Traditional  : http://ideone.com/cmYtTV
















