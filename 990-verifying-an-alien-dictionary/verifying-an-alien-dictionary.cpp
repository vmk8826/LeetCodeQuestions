class Solution {
public:
    bool comp(string &s1,string &s2,unordered_map<char,int>&rank){
        int i=0,j=0;
        while(i<s1.size()&&j<s2.size()){
            if(rank[s1[i]]<rank[s2[j]])return 1;
            else if(rank[s1[i]]>rank[s2[j]])return 0;
            i++;
            j++;
        }
        if(i!=s1.size())return false;
        if(j!=s2.size())return true;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(!comp(words[i],words[j],mp))return false;
            }
        }
        return true;
    }

};