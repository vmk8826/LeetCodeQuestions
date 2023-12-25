class Solution {
public:
    std::unordered_map<int,int>mp;
    int getAns(int n,vector<int>vis){
        if(n==0)return true;
        if(n<0)return false;
        if(mp.find(n)!=mp.end())return mp[n];
        int ans=0;
        for(int i=0;i<=15;i++){
            if(!vis[i]){
                vis[i]=1;
                int curr=n-pow(3,i);
                if(getAns(curr,vis)){
                    return mp[n]=true;
                }
            }
        }
        return mp[n]=false;
    }
    bool checkPowersOfThree(int n) {
        vector<int>vis(16,0);
        return getAns(n,vis);
    }
};