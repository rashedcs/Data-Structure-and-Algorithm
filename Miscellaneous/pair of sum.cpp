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
	//Search in set
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

#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    unordered_set<int> comp;
    int n, k;
    cin>>n>>k;
    int arr[n];


    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++)
    {
        if(comp.find(arr[i]) != comp.end())
        {
           cout<<arr[i]<<" "<<k-arr[i]<<endl;
        }
        else
        {
            comp.insert(k - arr[i]);
        }
    }

    return 0;
}













import java.util.HashMap;
import java.util.Vector;


public class PairSum {

	public static void pairs(int sum, Integer[] arr) {
		HashMap<Integer, Boolean> seen = new HashMap<>();
		for (int i : arr) {
			int complement = sum - i;
			if ( seen.containsKey(complement)) {
				System.out.println(i + "," + complement);
			} else {
				seen.put(i, true);
			}
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		pairs(10, new Integer[]{3, 4, 5, 6, 7}); // [[6, 4], [7, 3]]
		pairs(8, new Integer[]{3, 4, 5, 4, 4}); // [[3, 5], [4, 4], [4, 4], [4, 4]]
		pairs(8, new Integer[]{4}); // []
		pairs(0, new Integer[]{4,-4}); // [[-4,4]]
	}

}
