class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>mp(26,0);
        for(int i=0;i<chars.size();i++){
            mp[chars[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            vector<int>currMp(26,0);
            for(int j=0;j<words[i].size();j++){
                currMp[words[i][j]-'a']++;
            }
            bool flag=true;
            for(int j=0;j<26;j++){
                if(mp[j]<currMp[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans+=words[i].size();
            }
        }
        return ans;
    }
};