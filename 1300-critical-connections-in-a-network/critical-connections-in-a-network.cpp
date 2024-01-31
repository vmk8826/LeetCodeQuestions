class Solution {
public:
    void getBridges(int i,int par,int timer,vector<int>&low,vector<int>&time,
    vector<int>&vis,vector<int>adj[],vector<vector<int>>&ans){
        // cout<<i<<" "<<timer<<endl;
        vis[i]=1;
        low[i]=timer;
        time[i]=timer;
        for(auto it:adj[i]){
            if(it==par)continue;
            if(!vis[it]){
                getBridges(it,i,timer+1,low,time,vis,adj,ans);
                low[i]=min(low[i],low[it]);
                if(low[it]>time[i]){
                    ans.push_back({i,it});
                }
            }
            else{
                low[i]=min(low[i],time[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<int>low(n),time(n),vis(n,0),adj[n];
        vector<vector<int>>ans;
        for(int i=0;i<c.size();i++){
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i])
                getBridges(i,-1,0,low,time,vis,adj,ans);
        }
        return ans;
    }
};