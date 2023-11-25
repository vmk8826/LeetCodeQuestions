class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>preSum(nums.size(),0),postSum(nums.size(),0)
        ,ans;
        preSum[0]=0;
        postSum[nums.size()-1]=0;
        for(int i=1;i<nums.size();i++){
            preSum[i]+=preSum[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            postSum[i]=postSum[i+1]+nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            int res = i*nums[i]- preSum[i];
            res+= postSum[i]-nums[i]*(nums.size()-i-1);
            ans.push_back(res);
        }
        return ans;
    }
};