class Solution {
public:
    int dp[301][301];
    int getMaxCoins(int i,int j,vector<int>&arr){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            ans=max(ans,arr[k]*arr[i-1]*arr[j+1]+
            getMaxCoins(i,k-1,arr)+getMaxCoins(k+1,j,arr));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return getMaxCoins(1,n,nums);
    }
};