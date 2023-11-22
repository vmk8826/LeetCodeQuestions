class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>mp;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
           for(int j=0;j<nums[i].size();j++){
               mp[i+j].push_back(nums[i][j]);
           }
        }
        for(auto it:mp){
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};