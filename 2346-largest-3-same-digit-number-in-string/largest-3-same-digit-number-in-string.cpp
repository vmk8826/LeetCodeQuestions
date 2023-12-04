class Solution {
public:
    bool isSame(string s){
        if(s[0]==s[1]&&s[1]==s[2])return true;
        return false;
    }
    string largestGoodInteger(string num) {
        string curr="",ans="";
        for(int i=0;i<3;i++){
            curr.push_back(num[i]);
        }
        if(isSame(curr)){
            ans=curr;
        }
        for(int i=3;i<num.size();i++){
            curr.erase(0,1);
            curr.push_back(num[i]);
            // cout< <curr<<" ";
            if(isSame(curr)){
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};