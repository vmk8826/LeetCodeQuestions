class Solution {
public:
    bool isPreReq(int start,int end,vector<int>adj[],int n){
        queue<int>qu;
        vector<int>vis(n,0);
        qu.push(start);
        while(!qu.empty()){
            int node = qu.front();
            vis[node]=1;
            qu.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    qu.push(it);
                    if(it==end)return true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<int>adj[n];
        vector<bool>ans;
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i=0;i<q.size();i++){
            ans.push_back(isPreReq(q[i][0],q[i][1],adj,n));
        }
        return ans;
    }
};