class Solution {
public:
    int partitionString(string s) {
        int i=0,count=0,prev=0;
        unordered_map<int,int>mp;
        while(i<s.size()){
            mp[s[i]]++;
            if(mp.size()!=i-prev+1){
                prev=i;
                mp.clear();
                i--;
                count++;
            }
            i++;
        }
        return count+1;
    }
};