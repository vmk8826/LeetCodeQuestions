class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int tot=1,temp=n;
        while(temp){
            int curr=tot,day=0;
            while(day<7&&temp>0){
                ans=ans+curr;
                curr++;
                day++;
                temp--;
            }
            tot++;
        }
        return ans;
    }
};