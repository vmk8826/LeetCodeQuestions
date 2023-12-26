class Solution {
public:
    int dp[101][101];
    int getMaxStones(int i,int m,vector<int>&p){
        
        if(i>=p.size())return 0;
        if(dp[i][m]!=-1)return dp[i][m];

        int sum=0,maxi=INT_MIN,n=p.size();
        
        for(int x=0;x<2*m;x++){
            if(i+x<p.size())sum+=p[i+x];
            maxi=max(maxi,sum-getMaxStones(i+x+1,max(m,x+1),p));
        }

        return dp[i][m]=maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int sum = accumulate(piles.begin(),piles.end(),0);
        memset(dp,-1,sizeof(dp));
        return (sum+getMaxStones(0,1,piles))/2;
    }
};