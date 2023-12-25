class Solution {
public:
    int dp[100005];
    bool isPossible(int i,vector<int>&nums){
        if(i==nums.size())return true;
        if(dp[i]!=-1)return dp[i];
        bool ans1=false,ans2=false,ans3=false;
        if(i<nums.size()-1&&nums[i]==nums[i+1])
            ans1=isPossible(i+2,nums);
        if(i<nums.size()-2&&nums[i+1]==nums[i+2]&&
            nums[i]==nums[i+1])
            ans2=isPossible(i+3,nums);
        if(i<nums.size()-2&&nums[i]+1==nums[i+1]&&
            nums[i+1]+1==nums[i+2])
            ans3=isPossible(i+3,nums);
        return dp[i]=ans1|ans2|ans3;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return isPossible(0,nums);
    }
};