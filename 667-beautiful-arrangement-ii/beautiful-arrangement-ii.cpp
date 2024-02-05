class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans(n);
        int l=1,r=k+1,i=0;
        while(l<=r){
            if(i%2==0){
                ans[i++]=l;
                l++;
            }
            else{
                ans[i++]=r;
                r--;
            }
        }
        for(int x=k+2;x<=n;x++){
            ans[i++]=x;
        }
        return ans;
    }
};