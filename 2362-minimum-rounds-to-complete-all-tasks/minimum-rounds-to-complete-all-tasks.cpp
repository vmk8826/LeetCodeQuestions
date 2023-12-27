class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int ans=0;
        for(auto mov:mp){
            int it = mov.second;
            // cout<<mov.first<<" "<<it<<",";
           if(it==1)return -1;
           else if(it%3==0)ans+=it/3;
           else ans+=it/3+1;
        }
        return ans;
    }
};