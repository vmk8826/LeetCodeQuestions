class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>count(10005,0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int take=count[1],ntake=0;
        for(int i=2;i<10005;i++){
            int currtake=i*count[i]+ntake;
            int currntake=max(take,ntake);
            take=currtake;
            ntake=currntake;
        }
        return max(take,ntake);
    }

};