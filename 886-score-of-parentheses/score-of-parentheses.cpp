class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                if(st.top()==0){
                    st.pop();
                    st.push(1);
                }
                else{
                    int curr=0;
                    while(st.top()!=0){
                        curr+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*curr);
                }
            }
            i++;
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};