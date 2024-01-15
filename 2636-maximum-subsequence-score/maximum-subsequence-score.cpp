class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        vector<pair<int,int>>temp;
        for(int i=0;i<nums1.size();i++){
            temp.push_back({nums2[i],nums1[i]});
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum=sum+temp[i].second;
            pq.push(temp[i].second);
        }
        ans=temp[k-1].first*sum;
        // cout<<ans;
        for(int i=k;i<nums1.size();i++){
            sum=sum+temp[i].second-pq.top();
            ans=max(ans,(long long)(temp[i].first*sum));
            pq.pop();
            pq.push(temp[i].second);
        }
        return ans;
    }
};