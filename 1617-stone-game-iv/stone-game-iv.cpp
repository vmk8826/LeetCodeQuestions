class Solution {
public:
    int dp[100005];
    bool getAns(int n){
        if((int)sqrt(n)*(int)sqrt(n)==n){
            // cout<<sqrt(n)<<" "<<n<<endl;
            return true;
        }
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i*i<=n;i++){
            if(!getAns(n-i*i))return dp[n]=true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return getAns(n);
    }
};