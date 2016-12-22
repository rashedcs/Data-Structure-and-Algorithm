#include<bits/stdc++.h>
using namespace std;


int maxSubArraySum(int arr[], int n)
{
  int sum = 0, ans = 0;
  for (int i=0; i<n; i++)
  {                                       // O(n)
    if (sum + arr[i] >= 0)
    {
      sum += arr[i];
      ans = max(ans, sum);
    }
    else        sum = 0;
  }
  return sum;
}



int main()
{
  int n = 7;
  int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
  printf("Max 1D Range Sum = %d\n", maxSubArraySum(arr,n));
  return 0;
}
