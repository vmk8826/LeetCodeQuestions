class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=1 && __gcd(i,j)!=1)continue;
                string num = to_string(i)+"/"+to_string(j);
                ans.push_back(num);
            }
        }
        return ans;
    }
};