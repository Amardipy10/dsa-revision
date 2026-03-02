class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int maxEle=arr[0];
        int n=arr.size();
        int pivot=0;
        for(int i=1;i<n;i++){
            if (maxEle<arr[i]){
                maxEle=arr[i];
                pivot=i;
            }
            if(arr[i-1]==arr[i]){
                return false;
            }
        }
        if (maxEle==arr[0]){
            return false;
        }
        if(maxEle==arr[n-1]){
            return false;
        }
        for(int i=0;i<pivot;i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
        }
        for(int i=pivot+1;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                return false;
            }
        }

        return true;
    }
};