class Solution {
public:
    int dp[101][101][2];
    int getMaxStones(int i,int m,int alice,vector<int>&p){
        
        if(i>=p.size())return 0;
        if(dp[i][m][alice]!=-1)return dp[i][m][alice];

        int result = alice?-1:INT_MAX;
        int sum=0;
        int n=p.size();
        for(int j=0;j<min(2*m,n-i);j++){
            sum=sum+p[i+j];
            if(alice){
                result=max(result,sum+
                            getMaxStones(i+j+1,max(j+1,m),0,p));
            }
            else{
                result=min(result,
                            getMaxStones(i+j+1,max(j+1,m),1,p));
            }
        }

        return dp[i][m][alice]=result;
    }
    int stoneGameII(vector<int>& piles) {

        // int sum = accumulate(piles.begin(),piles.end(),0);
        memset(dp,-1,sizeof(dp));
        return getMaxStones(0,1,1,piles);

    }
};