class Solution {
public:
    void Cycles(vector<int>adj[],vector<int>&vis,int s){
       vis[s]=1;
        for(auto it : adj[s]){
           if(!vis[it]){
             Cycles(adj,vis,it);
           }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n+1];
        for(int i=0;i<connections.size();i++){
           int a = connections[i][0],b=connections[i][1];
           adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>vis(n+1,0);
        int compCount=0;
        for(int i=0;i<n;i++){
           if(!vis[i]){
               compCount++;
              Cycles(adj,vis,i);
           }
        }
        // cout<<compCount;
        if(connections.size()<n-1)return -1;
        else return compCount-1;
    }
};