class Solution {
public:
    void getAns(int i,vector<string>&mp,string &str,string curr,
    vector<string>&ans){
        if(i==str.size()){
            if(curr.size()!=0)
                ans.push_back(curr);
            return;
        }
        int num=str[i]-'0';
        for(int j=0;j<mp[num].size();j++){
            curr.push_back(mp[num][j]);
            getAns(i+1,mp,str,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>str={"","","abc","def","ghi","jkl",
        "mno","pqrs","tuv","wxyz"};
        vector<string>ans;
         getAns(0,str,digits,{},ans);
         return ans;
    }
};