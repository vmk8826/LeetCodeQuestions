class Solution {
public:
    int rev(int n){
        int revNum=0;
        while(n>0){
            revNum=revNum*10+n%10;
            n=n/10;
        }
        return revNum;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int val=nums[i]-rev(nums[i]);
            mp[val]++;
        }
        long long ans=0;
        int mod=1e9+7;
        for(auto it: mp){
            long long val = (((long long)it.second-1)*
                            (long long)it.second)/2;
            ans=(ans%mod+val%mod)%mod;
        }
        return ans;
    }
};