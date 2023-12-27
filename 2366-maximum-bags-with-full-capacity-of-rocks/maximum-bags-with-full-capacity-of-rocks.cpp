class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        vector<int>store;
        for(int i=0;i<c.size();i++){
            store.push_back(c[i]-r[i]);
        }
        sort(store.begin(),store.end());
        int i=0,ans=0;
        while(i<store.size()&&ar){
            if(ar>=store[i]){
                ar-=store[i];
                ans++;
                i++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};