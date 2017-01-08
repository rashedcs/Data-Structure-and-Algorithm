
// A C++ program to find the number of digits in 
//Source : http://www.geeksforgeeks.org/count-digits-factorial-set-1/
#include <bits/stdc++.h>
using namespace std;
 
// This function receives an integer n, and returns
// the number of digits present in n!
int findDigits(int n)
{
    // factorial exists only for n>=0
    if (n < 0)
        return 0;
 
    // base case
    if (n <= 1)
        return 1;
 
    // else iterate through n and calculate the
    // value
    double digits = 0;
    for (int i=2; i<=n; i++)
        digits += log10(i);
 
    return floor(digits) + 1;
}
 
// Driver code 
int main()
{
    cout << findDigits(1) << endl;
    cout << findDigits(5) << endl;
    cout << findDigits(10) << endl;
    cout << findDigits(120) << endl;
    return 0;
}
