class Solution {
public:
    int captureForts(vector<int>& forts) {
        int maxCount=0;
        int n=forts.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(forts[i]==1){
                count++;
            }
        }
        if(count==0){
            return 0;
        }
        count=0;
        for(int i=0;i<n;i++){
            if(forts[i]==1||forts[i]==-1){
                for(int j=i+1;j<n;j++){
                    if(forts[j]==0){
                        count++;
                    }
                    
                    else if(forts[i]==-1 &&forts[j]==-1){
                        count=0;
                        break;
                    }
                    else if(forts[i]==1 &&forts[j]==1){
                        count=0;
                        break;
                    }
                    else{
                        maxCount=max(maxCount,count);
                        count=0;
                        break;
                    }
                }
            }

        }
        return maxCount;
        
    }
};