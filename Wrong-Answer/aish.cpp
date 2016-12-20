//It is inot wrong answer ...... It explain recursion and screen sort available.
Source : http://www.java-samples.com/showtutorial.php?tutorialid=257

#include<bits/stdc++.h>
using namespace std;


    int fib (int n)
    {
      cout << "Processing fib(" << n << ")... ";

      if (n < 3 )
      {
         cout << "Return 1!\n";
         return (1);
      }
      else
      {
       cout << "Call fib(" << n-2 << ") and fib(" << n-1 << ").\n";
       return fib(n-2) + fib(n-1);
      }
   }


    int main()
    {

      int n, answer;
      cout << "Enter number to find: ";
      cin >> n;

      cout << "\n\n";

      answer = fib(n);
      cout << answer << " is the " << n << "th Fibonacci number\n";
         return 0;
    }




