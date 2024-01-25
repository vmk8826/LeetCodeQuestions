class Solution {
public:
    void getString(string s,string &ans,int n){
        if(n==0){
            ans=s;
            return;
        }
        int i=0;
        string ret="";
        while(i<s.size()){
            char ch=s[i];
            int curr=1;
            while(i<s.size()-1&&s[i+1]==ch){
                curr++;
                i++;
            }
            ret=ret+to_string(curr)+ch;
            i++;
        }
        getString(ret,ans,n-1);
    }
    string countAndSay(int n) {
        string ans;
        getString("1",ans,n-1);
        return ans;
    }
};