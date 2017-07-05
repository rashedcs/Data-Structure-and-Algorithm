#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    // Initializing vector with values
    vector<int> v1 = {4, 18, 9, 12, 33};
 
    // Declaring new vector
    vector<int> v2 = {5, 18, 9, 11, 33};
 
    // Using assignment operator to copy one
    // vector to other
   copy(v1.begin(), v1.end(), back_inserter(v2));
 
 
    cout << "New vector elements are : ";
    for (int i=0; i<v2.size(); i++)
        cout << v2[i] << " ";
    cout<< endl;
 
 
 
    return 0;
}
