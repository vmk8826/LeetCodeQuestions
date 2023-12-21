class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n],indegree(n,0),safe(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                qu.push(i);
        }
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            safe[curr]=1;
            for(auto it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    qu.push(it);
                }
            }
        }
        vector<int>ret;
        for(int i=0;i<n;i++){
            if(safe[i])ret.push_back(i);
        }
        return ret;
    }
};