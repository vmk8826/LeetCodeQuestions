class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>differ;
        int currGas=0,idx=0;
        for(int i=0;i<cost.size();i++){
            differ.push_back(gas[i]-cost[i]);
            currGas+=gas[i]-cost[i];
        }
        if(currGas<0)return -1;
        currGas=0;
        for(int i=0;i<differ.size();i++){
            currGas+=differ[i];
            // cout<<currGas<<" ";
            if(currGas<0)
            {
                idx=i+1;
                currGas=0;
            }
        }
        return idx;
    }
};