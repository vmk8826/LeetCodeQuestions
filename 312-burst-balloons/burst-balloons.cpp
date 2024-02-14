class Solution {
public:
    int dp[301][301];
    int getBurst(int i,int j,vector<int>&arr){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long ans=INT_MIN;
        for(int k=i;k<=j;k++){
            // cout<<arr[k-1]<<" "<<arr[k]<<" "<<arr[k+1]<<endl;
           long long curr=(arr[i-1]*arr[k]*arr[j+1])+getBurst(i,k-1,arr)+
                    getBurst(k+1,j,arr);
            ans=max(ans,curr);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return getBurst(1,n,nums);
    }
};