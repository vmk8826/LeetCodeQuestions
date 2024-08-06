class Solution {
public:
    int minimumPushes(string word) {
        vector<int>charMap(26,0);
        for(int i=0;i<word.size();i++){
            charMap[word[i]-'a']++;
        }
        vector<int>sortMap;
        for(int i=0;i<26;i++){
            if(charMap[i]>0)
                sortMap.push_back(charMap[i]);
        }


        sort(sortMap.begin(),sortMap.end());
        reverse(sortMap.begin(),sortMap.end());
        int ans=0,count=1;

        for(int i=0;i<sortMap.size();i++){
            if(count<=8){
                ans+=sortMap[i];
                count++;
            }
            else if(count>8&&count<=16){
                ans+=(sortMap[i]*2);
                count++;
            }
            else if(count>16&&count<=24){
                ans+=(sortMap[i]*3);
                count++;
            }
            else{
                ans+=(sortMap[i]*4);
            }
        }
        return ans;
    }
};