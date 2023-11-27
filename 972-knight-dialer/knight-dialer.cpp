class Solution {
public:
    long long mod = 1e9+7;
    long long waysDial(int i,int j,int n,vector<int>&movx,vector<int>&movy,
        vector<vector<vector<long long>>>&dp){
        if(n==0)return 1;
        if(dp[i][j][n]!=-1)return dp[i][j][n]%mod;
        long long ans=0;
        for(int k=0;k<movx.size();k++){
            int nx = i+movx[k];
            int ny = j+movy[k];
            if(nx>=1&&nx<=3&&ny>=1&&ny<=4&&!(nx==1&&ny==4)
            &&!(nx==3&&ny==4)){
                ans=ans%mod+waysDial(nx,ny,n-1,movx,movy,dp)%mod;
            }
        }
        return dp[i][j][n]=ans%mod;
    }
    int knightDialer(int n) {
        vector<int> movx={1,-1,2,-2,2,-2,1,-1},movy={2,2,1,1,-1,-1,-2,-2};
        vector<vector<vector<long long>>>dp(4,vector<vector<long long>>(
            5,vector<long long>(n,-1)));
        long long ans=0;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=4;j++){
                if(!(i==1&&j==4)&&!(i==3&&j==4)){
                    ans=ans%mod+waysDial(i,j,n-1,movx,movy,dp)%mod;
                }
            }
        }
        return ans%mod;
    }
};