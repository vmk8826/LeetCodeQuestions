class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>qu;
        int n=s.size();
        qu.push(0);
        int curr_max=0;
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            if(curr==s.size()-1)return true;
            for(int i=max(curr+minJump,curr_max);i<=min(curr + maxJump,n-1);i++){
                // cout<<i<<",";
                if(s[i]=='0'){
                    // cout<<i<<" ";
                    qu.push(i);
                }
            }
                // cout<<endl;
            curr_max = min(curr+maxJump+1, n);
        }
        return false;
    }
};