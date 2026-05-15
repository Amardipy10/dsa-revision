#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            while(arr[i]%k<k){
                arr[i]=arr[i]%k;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==0){
                ans.push_back(i);
            }

        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]!=0){
                ans.push_back(i);
            }

        }
        for (int i = 0; i < n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    // Store pairs of {remainder, original_index}
    vector<pair<int, int>> arr(n);
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        
        val = val % k;
        if (val == 0) {
            val = k; // Multiples of k die at the end of their cycle, so they effectively have the highest remainder
        }
        
        // Trick: Store negative value so std::sort orders them descending by value, 
        // but ascending by index (since index is positive)
        arr[i] = {-val, i + 1}; 
    }
    
    // Sort based on the pairs
    sort(arr.begin(), arr.end());
    
    // Print the sorted indices (1-based indexing)
    for (int i = 0; i < n; i++) {
        cout << arr[i].second << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}