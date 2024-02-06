class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        vector<pair<int, int>> vec(n);
        
        for(int i = 0; i<nums.size(); i++) {
            vec[i] = make_pair(nums[i], i);
        }
        
        auto lambda = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        };
        
        sort(begin(vec), end(vec), lambda);
        
        for(int i = 0; i<n; i++) {
            int j = i+1;
            while(j < n) {
                if(abs((long long)vec[j].first - (long long)vec[i].first) > t)
                    break;
                if(abs(vec[j].second - vec[i].second)<= k)
                    return true;
                j++;
            }
        }
        return false;
    }
};