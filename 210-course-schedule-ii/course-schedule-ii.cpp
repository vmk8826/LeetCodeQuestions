class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n],inDeg(n,0),ans;
        for(int i=0;i<pre.size();i++){
                adj[pre[i][1]].push_back(pre[i][0]);
                inDeg[pre[i][0]]++;
        }
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0)
                qu.push(i);
        }
        while(!qu.empty()){
            int top=qu.front();
            qu.pop();
            ans.push_back(top);
            for(auto it:adj[top]){
                inDeg[it]--;
                if(inDeg[it]==0){
                    qu.push(it);
                }
            }
        }
        if(ans.size()<n)return {};
        return ans;
    }
};