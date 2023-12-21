class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>adj[n],inDeg(n);
        int ans=0;
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
            inDeg[p[i][0]]++;
        }
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0)qu.push(i);
        }
        while(!qu.empty()){
            int top=qu.front();
            qu.pop();
            ans++;
            for(auto it:adj[top]){
                inDeg[it]--;
                if(inDeg[it]==0)qu.push(it);
            }
        }
        if(ans==n)return true;
        return false;
    }
};