class Solution {
public:
    int dp[105][105];
    int getCost(int i,int j,vector<int>&cost){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            ans=min(ans,cost[j+1]-cost[i-1]+getCost(i,k-1,cost)
                                +getCost(k+1,j,cost));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int k=cuts.size();
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return getCost(1,k,cuts);
    }
};