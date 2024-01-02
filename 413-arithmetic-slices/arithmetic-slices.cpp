class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i=0,j=1,ans=0;
        while(j<nums.size()){
            while(j<nums.size()-1&&nums[j]-nums[j-1]==nums[j+1]-nums[j])j++;
            int count=j-i+1;
            ans+=(count*(count+1))/2-(2*count-1);
            i=j;
            j++;
        }
        return ans;
    }
};