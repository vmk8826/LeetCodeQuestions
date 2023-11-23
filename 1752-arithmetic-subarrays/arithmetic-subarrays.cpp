class Solution {
public:
    bool checkArithmetic(vector<int>&curr){
        sort(curr.begin(),curr.end());
        int diff=curr[1]-curr[0];
        int i=1;
        while(i<curr.size()-1&&(curr[i+1]-curr[i])==diff){
            i++;
        }
        if(i==curr.size()-1)return true;
        return false;
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
                ans.push_back(checkArithmetic(curr));
            }
        }
        return ans;
    }
};