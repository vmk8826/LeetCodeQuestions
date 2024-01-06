// class Solution {
// public:
//     // int dp[10005][105];
//     // int getMinDrops(int f,int e){
//     //     if(f==1||f==0)return f;
//     //     if(e==1)return f;
//     //     if(dp[f][e]!=-1)return dp[f][e];
//     //     int ans=1e9;
//     //     for(int i=1;i<=f;i++){
//     //         ans=min(ans,max(getMinDrops(i-1,e-1),
//     //                         getMinDrops(f-i,e)));
//     //     }
//     //     return dp[f][e]=ans+1;
//     // }
//     int getMinDropsIter(int n,int k){
//         vector<vector<int>>dp(n+1,vector<int>(k+1,1e9));

//          for(int i=0;i<=k;i++){
//             dp[0][i]=0;
//         }
         
//         for(int i=0;i<=n;i++){
//             dp[i][0]=1e9;
//             dp[i][1]=i;
//         }
       
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=k;j++){
//                 for(int f=1;f<=i;f++){
//                     dp[i][j]=min(dp[i][j],1+max(dp[f-1][j-1],
//                         dp[i-f][j]));
//                 }
//             }
//         }
//         // for(int i=0;i<=n;i++){
//         //     for(int j=0;j<=k;j++){
//         //        cout<<dp[i][j]<<",";
//         //     }
//         //     cout<<endl;
//         // }
//         return dp[n][k];
//     }
//     int superEggDrop(int k, int n) {
//         // memset(dp,-1,sizeof(dp));
//         return getMinDropsIter(n,k);
//     }
// };
class Solution {
public:
    
    int superEggDrop(int K, int N) {
        if(N==0||N==1) return N;     //Think for base case
        if(K==1) return N;
        
        vector<vector<int>> dp(K+1,vector<int> (N+1,0));
      for(int i=0;i<=K;i++)
        dp[i][0]=0,dp[i][1]=1;   //Filling from base case as if N==0 ans=0 , N==1 ans=1
      for(int i=0;i<=N;i++)
        dp[0][i]=0,dp[1][i]=i;   //Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)
        
        for(int i=2;i<K+1;i++)
        {
            for(int j=2;j<N+1;j++)
            {    int l=1,h=j,temp=0,ans=100000;
                 while(l<=h)
                 {
                    int mid=(l+h)/2;
                    int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
                    int right= dp[i][j-mid];  // not broken check for up floors of mid
                    temp=1+max(left,right);          //store max of both 
                    if(left<right){                  //since right is more than left and we need more in worst case 
                      l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward 
                    {    
                        h=mid-1;
                    }
                    ans=min(ans,temp);               //store minimum attempts
                 }
                 dp[i][j]=ans;
            }
        }
        return dp[K][N];
         
    }
};