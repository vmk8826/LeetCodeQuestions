class Solution {
public:
    int totalMoney(int n) {
        int quo=n/7,rem=n%7,ans=0,day=0;
        while(rem--){
            ans+=(quo+1)+day;
            day++;
        }
        ans=ans+28*quo+7*((quo*(quo-1))/2);
        return ans;
    }
};