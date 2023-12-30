class Solution {
public:
    void markVis(int st,vector<int>&vis,vector<int>adj[]){
        queue<int>qu;
        qu.push(st);
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            vis[curr]=1;
            for(auto it:adj[curr]){
                if(!vis[it])qu.push(it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& in) {
        vector<int>adj[in.size()];
        vector<int>vis(in.size(),0);
        for(int i=0;i<in.size();i++){
            for(int j=0;j<in.size();j++){
                if(in[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<in.size();i++){
            if(!vis[i]){
                ans++;
                markVis(i,vis,adj);
            }
        }
        return ans;
    }
};