class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans=nums[0];
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
           while(!pq.empty()&&pq.top().second<(i-k))pq.pop();
           int curr=nums[i]+pq.top().first;
           pq.push({curr,i});
           if(i==nums.size()-1)ans=curr;
        }
        return ans;
    }
};