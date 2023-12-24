class Solution {
public:
    pair<int,int> getLoudest(int i,vector<int>adj[],
    vector<int>vis,vector<int>&q,vector<pair<int,int>>&dp){
        if(dp[i].first!=-1)return dp[i];
        vis[i]=1;
        int mini=q[i];
        int ans=i;
        for(auto it:adj[i]){
            if(!vis[it]){
                pair<int,int>curr=getLoudest(it,adj,vis,q,dp);
                if(mini>curr.second){
                    ans=curr.first;
                    mini=curr.second;
                }
            }
        }
        return dp[i]={ans,mini};
    }
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
        vector<int>adj[q.size()];
        for(int i=0;i<r.size();i++){
            adj[r[i][1]].push_back(r[i][0]);
        }
        vector<int>ans;
        vector<pair<int,int>>dp(q.size(),{-1,-1});
        for(int i=0;i<q.size();i++){
            vector<int>vis(q.size(),0);
            ans.push_back(getLoudest(i,adj,vis,q,dp).first);
        }
        return ans;
    }
};