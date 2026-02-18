class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank=0;
        int currTank=0;
        int stIndex=0;

        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            currTank+=diff;
            totalTank+=diff;

            if(currTank<0){
                stIndex=i+1;
                currTank=0;
            }
        }

        if(totalTank>=0){
            return stIndex;
        }
        else{
            return -1;
        }
        
    }
};