#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// //brute force
int mostarea(vector<int>& v){
    int n=v.size();
    int max_area=0;
    for (int i = 0; i < n; i++)
    {
        int curr_area=0;
        for (int j = i+1; j < n; j++)
        {
            int min_height=min(v[i],v[j]);
            curr_area=min_height*(j-i);
            max_area=max(max_area,curr_area);
        }
        
    }
    return max_area;
    
}

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int ans=mostarea(height);
    cout<<ans;
    return 0;
}

//optimal
int mostareas(vector<int>& v){
    int n=v.size();
    int max_area=0;
    int left=0;
    int right=n-1;
    while(left<right){
        int height=min(v[right],v[left]);
        int area=height*(right-left);
        max_area=max(max_area,area);
        if(v[left]<v[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return max_area;
}
int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int ans=mostareas(height);
    cout<<ans;
    return 0;
}