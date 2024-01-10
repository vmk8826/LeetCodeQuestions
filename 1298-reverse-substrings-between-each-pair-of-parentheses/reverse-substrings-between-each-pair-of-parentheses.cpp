class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(s[i]==')'){
                string curr="";
                while(st.top()!='('){
                    curr+=st.top();
                    st.pop();
                }
                st.pop();
                int j=0;
                while(j<curr.size()){
                    st.push(curr[j]);
                    j++;
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};