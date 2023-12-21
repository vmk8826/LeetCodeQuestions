class Solution {
public:
    int mod = 1e9+7;
    long long fastPower(long long n,long long pow){
        long long ans=1;
        n=n;
        while(pow>0){
            if(pow&1)
                ans=(n*ans)%mod;
                pow=pow/2;
                n=(n*n)%mod;
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long ans=(fastPower(5,n-n/2)*fastPower(4,n/2));
        return ans%mod;
    }
};