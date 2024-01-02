class Solution {
public:
    int dp[10005];
    int getMax(int i,vector<int>&nums,map<int,int>&mp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]*mp[nums[i]];
        if(i+1<nums.size()&&nums[i+1]!=nums[i]+1)take+=getMax(i+1,nums,mp);
        else take+=getMax(i+2,nums,mp);
        int ntake=getMax(i+1,nums,mp);
        return dp[i]=max(ntake,take);
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        memset(dp,-1,sizeof(dp));
        vector<int>store;
        for(auto it:mp){
            store.push_back(it.first);
        }
        return getMax(0,store,mp);
    }
};