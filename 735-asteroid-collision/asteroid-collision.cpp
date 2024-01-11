class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        int i=0;
        while(i<a.size()){
            if(a[i]>0){
                st.push(a[i]);
            }
            else{
                int flag=1;
                while(st.size()>0&&st.top()>0&&st.top()<=abs(a[i]))
                {
                    int curr=st.top();
                    st.pop();
                    if(curr==abs(a[i])){
                        flag=0;
                        break;
                    }
                }
                if(flag&&(st.empty()||st.top()<0))st.push(a[i]);
            }
            i++;
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};