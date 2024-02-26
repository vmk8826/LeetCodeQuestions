class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=mp[arr[i]-k]+1;
        }
        int ans=INT_MIN;
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};