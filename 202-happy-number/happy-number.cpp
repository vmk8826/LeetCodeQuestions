class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>mp;
        mp[n]=1;
        while(n!=1){
            long long temp=0;
            while(n){
                int mul= n%10;
                temp=temp+(mul*mul);
                n=n/10;
            }
            n=temp; 
            if(mp[n]){
                return false;
            }
            mp[n]=1;
        }
        return true;
    }
};