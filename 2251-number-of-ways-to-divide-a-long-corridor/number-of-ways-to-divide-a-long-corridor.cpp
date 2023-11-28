class Solution {
public:
    int numberOfWays(string co) {
        long long i=0,ans=1,prev=0,mod=1e9+7,totSeats=0;
        while(i<co.size()){
            long long seats=0,curr=0;
            while(i<co.size()&&seats<2){
                if(co[i]=='S')seats++;
                i++;
            }
            totSeats+=seats;
            while(i<co.size()&&co[i]=='P'){
                curr++;
                i++;
            }
            ans=ans%mod*(prev+1)%mod;
            prev=curr;
        }
        if(totSeats%2==0&&totSeats!=0)return ans;
        else return 0;
    }
};