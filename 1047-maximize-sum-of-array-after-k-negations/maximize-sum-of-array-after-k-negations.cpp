class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int curr=pq.top();
            // cout<<curr<<" ";

            pq.pop();
            curr=curr*-1;
            pq.push(curr);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};