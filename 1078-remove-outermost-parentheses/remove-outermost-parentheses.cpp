class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(st.top()!=0){
                    ans.push_back(')');
                    st.pop();
                }
                else{
                    st.pop();
                }
            }
           else{
               if(st.size()==0)
                    st.push(0);
                else {
                    ans.push_back('(');
                    st.push(1);
                }
           }

        }
        return ans;
    }
};