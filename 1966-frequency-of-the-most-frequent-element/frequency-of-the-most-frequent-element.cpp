class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long i=0,j=0,currSum=0,len=0,ans=-1e9;
        while(j<nums.size()){
            currSum+=nums[j];
            len=j-i+1;
            while(i<=j&&currSum+k<len*nums[j]){
                currSum-=nums[i];
                i++;
                len=j-i+1;
            }
            ans=max(ans,len);
            j++;
        }
        return ans;
    }
};