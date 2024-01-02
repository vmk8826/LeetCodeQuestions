class Solution {
public:
    int isGood(unordered_map<int,int>mp1,unordered_map<int,int>&mp2){
        for(auto it:mp2){
            mp1[it.first]=mp1[it.first]-it.second;
            if(mp1[it.first]==0)mp1.erase(it.first);
        }
        if(mp1.size()==mp2.size())return true;
        return false;
    }
    int getSplits(string s){
        unordered_map<int,int>dp,dp1;
        for(int i=0;i<s.size();i++){
            dp[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            dp1[s[i]-'a']++;
            if(isGood(dp,dp1))ans++;
        }
        return ans;
    }
    int numSplits(string s) {
        return getSplits(s);
    }
};