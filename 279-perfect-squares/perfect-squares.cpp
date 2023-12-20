class Solution {
public:
    // int dp[10005];
    // int getMinSteps(int n){
    //     if(n==0)return 0;
    //     if(n==1)return 1;
    //     if(dp[n]!=-1)return dp[n];
    //     int minSteps=1e9;
    //     for(int i=1;i*i<=n;i++){
    //         minSteps=min(minSteps,getMinSteps(n-(i*i))+1);
    //     }
    //     return dp[n]=minSteps;
    // }
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     // cout<<i<<" ";
        //     for(int j=1;j*j<=i;j++){
        //         // cout<<j<<",";
        //         dp[i]=min(dp[i],dp[i-j*j]+1);
        //     }
        //     // cout<<endl;
        // }
        // // for(int i=0;i<=n;i++){
        // //     cout<<dp[i]<<" ";
        // // }
        // // return dp[n];
        // memset(dp,-1,sizeof(dp));
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};