class Solution {
public:
    int getSplits(string s){
        unordered_map<int,int>dp,dp1;
        for(int i=0;i<s.size();i++){
            dp[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            dp1[s[i]-'a']++;
            dp[s[i]-'a']--;
            if(dp[s[i]-'a']==0)dp.erase(s[i]-'a');
            if(dp1.size()==dp.size())ans++;
        }
        return ans;
    }
    int numSplits(string s) {
        return getSplits(s);
    }
};