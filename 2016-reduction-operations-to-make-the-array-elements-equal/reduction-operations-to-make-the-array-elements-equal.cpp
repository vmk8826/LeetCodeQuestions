class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0,slide=0;
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            if(it->first!=mini){
                slide+=it->second;
                ans+=slide;
            }
            // cout<<it->first<<" ";
        }
        return ans;
    }
};