 //DP approach : Time Complexity 0(n)  Source : http://www.programcreek.com/2013/02/leetcode-maximum-subarray-java/
// Source : http://www.algoqueue.com/algoqueue/default/view/9568256/find-maximum-sum-subarray-non-contiguous-
 int maxSubArraySum(int arr[], int n)
 {
     int m = arr[0];
     int *sum = new int[n];
     sum[0] = arr[0];

     for (int i=1; i<n; i++)
     {
	sum[i] =  max(arr[i], sum[i-1] + arr[i]);
	m      =  max(m, sum[i]);
     }
     return m;
 }




//Best approach:  Time Complexity O(n)

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












//Another approach : But it does not calcualte negativ numbers Time Complexity O(n)

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

