#include<bits/stdc++.h>
using namespace std;

int myfun(int x, int y)
{
    return x+y;
}


int main()
{
    vector<int> v = {1, 2, 3, 4, 5}; // or std::vector<int>v(10, 2);

    cout << "The first 10 even numbers are: ";
    partial_sum(v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout <<endl;
    partial_sum(v.begin(), v.end(), v.begin(), myfun);
    //std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
    std::cout << "The first 10 powers of 2 are: ";
    for (auto n : v)
    {
        cout << n << " ";
    }
    return 0
}


source : http://www.geeksforgeeks.org/numeric-header-in-c-stl-set-1-accumulate-and-partial_sum/
