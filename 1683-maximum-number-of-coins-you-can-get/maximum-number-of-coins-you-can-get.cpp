class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int j=piles.size()-2,i=0,ans=0;
        while(i<j){
            ans+=piles[j];
            j-=2;
            i++;
        }
        return ans;
    }
};