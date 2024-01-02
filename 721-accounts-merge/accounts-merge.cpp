class Solution {
public:
    class makeDSU{
        public:
        vector<int>rank,parent;
        makeDSU(int n){
            rank.resize(n+1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                rank[i]=1;
                parent[i]=i;
            }
        }
        int findParent(int i){
            if(parent[i]==i)return i;
            return parent[i]=findParent(parent[i]);
        }
        void merge(int i,int j){
            int par1=findParent(i);
            int par2=findParent(j);

            if(rank[par1]>rank[par2])parent[par2]=par1;
            else parent[par1]=par2;
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        makeDSU dsu(n);
        unordered_map<string,int>mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }
                else{
                    dsu.merge(mp[accounts[i][j]],i);
                }
            }
        }

        vector<vector<string>>ans,store(n);
    
        for(auto it:mp){
            int curr=dsu.findParent(it.second);
            store[curr].push_back(it.first);
        }

        for(int i=0;i<n;i++){
            vector<string>now=store[i];
            sort(now.begin(),now.end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<now.size();j++){
                temp.push_back(now[j]);
            }
            if(temp.size()>1)
            ans.push_back(temp);
        }
        return ans;
    }
};