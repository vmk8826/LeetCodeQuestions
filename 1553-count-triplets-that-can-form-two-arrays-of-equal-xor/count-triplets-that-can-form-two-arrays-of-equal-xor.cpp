class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int k=i+1;k<arr.size();k++){
                int xorTot=0;
                for(int j=i;j<=k;j++){
                    xorTot=xorTot^arr[j];
                }
                int xorCurr=0;
                for(int j=i;j<k;j++){
                    xorCurr=xorCurr^arr[j];
                    if(xorCurr==(xorTot^xorCurr)){
                        // cout<<i<<","<<j<<","<<k<<"->"<<xorCurr<<" "<<xorTot<<endl;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};