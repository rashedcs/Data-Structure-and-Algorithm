Best approach: 

int kadane(int arr[], int size)
{
    int curMax,gMax;
    curMax = arr[0];
    gMax   = arr[0];
    for(int i=1;i<size;i++)
    {
        curMax=max(arr[i],curMax+arr[i]);
        gMax=max(curMax,gMax);
    }
    return gMax;
}












Another approach : But it does not calcualte negativ numbers
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

