#include <iostream>
#include <unordered_set>
using namespace std;
 
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    bool is_pair = false;
    unordered_set<int> comp;
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++) {
        if(comp.find(arr[i]) != comp.end()) {
            is_pair = true;
            break;
        } else {
            comp.insert(k - arr[i]);
        }
    }
    
    if(is_pair == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;    
        
        return 0;
}
