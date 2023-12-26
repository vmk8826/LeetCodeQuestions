class Solution {
public:
    long long minSteps(int s,int t){
        if(s>=t){
            return s-t;
        }
        if(t%2==0)return 1+minSteps(s,t/2);
        else return 1+minSteps(s,t+1);
    }
    int brokenCalc(int s, int t) {
        return minSteps(s,t);
    }
};