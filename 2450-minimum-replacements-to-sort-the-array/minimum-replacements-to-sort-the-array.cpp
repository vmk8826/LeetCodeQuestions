class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                long long curr = nums[i]/nums[i+1];
                if(nums[i]%nums[i+1]!=0){
                    curr++;
                }
                ans+=(curr-1);
                nums[i]=nums[i]/curr;
            }
        }
        return ans;
    }
};