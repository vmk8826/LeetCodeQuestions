class Solution {
public:
   bool check(vector<int>& arr) {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        unordered_set<int> arrSet;
        
        for (int num : arr) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            arrSet.insert(num);
        }
        
        if ((maxElement - minElement) % (arr.size() - 1) != 0) {
            return false;
        }
               
        int diff = (maxElement - minElement) / (arr.size() - 1);
        int curr = minElement + diff;
        
        while (curr < maxElement) {
            if (arrSet.find(curr) == arrSet.end()) {
                return false;
            }
            
            curr += diff;
        }
        
        return true;
   }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            vector<int>curr;
            if(r[i]-l[i]+1==1||r[i]-l[i]+1==2)ans.push_back(true);
            else{
                for(int j=l[i];j<=r[i];j++){
                curr.push_back(nums[j]);
                // cout<<nums[j]<<',';
                }
                // cout<<endl;
                ans.push_back(check(curr));
            }
        }
        return ans;
    }
};