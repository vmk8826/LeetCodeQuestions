class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        // vector<int>adj[n];
        vector<vector<int>>dis(n+1,vector<int>(n+1,INT_MAX/2));
        vector<bool>ans(q.size(),0);
        for(int i=0;i<pre.size();i++){
            // adj[pre[i][0]].push_back(pre[i][1]);
            dis[pre[i][0]][pre[i][1]]=1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dis[j][k]>dis[j][i]+dis[i][k]){
                        dis[j][k]=dis[j][i]+dis[i][k];
                    }
                }
            }
        }
        for(int i=0;i<q.size();i++){
            // cout<<q[i][0]<<" "<<q[i][1]<<" ";
            if(dis[q[i][0]][q[i][1]]!=INT_MAX/2)
                ans[i]=1;
        }
        return ans;
    }
};