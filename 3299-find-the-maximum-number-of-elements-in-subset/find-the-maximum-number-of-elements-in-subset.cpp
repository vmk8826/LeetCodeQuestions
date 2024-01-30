class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        long long ans=1;
        for(auto it:mp){
            // cout<<it.first<<" ";
            long long curr=it.first;
            if(curr==1)continue;
            long long count=1;
            while(mp.find(sqrt(curr))!=mp.end()&&(sqrt(curr)*sqrt(curr))==curr){
                if(mp[sqrt(curr)]>=2){
                    count+=2;
                    curr=sqrt(curr);    
                }
                else break;
            }
            ans=max(ans,count);
        }
        if(mp[1]%2==0)mp[1]=mp[1]-1;

        ans=max(ans,mp[1]);

        return ans;
    }
};