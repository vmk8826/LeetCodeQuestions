class Solution {
public:
    bool isPossible(int i,int k,unordered_map<int,int>&mp,int &maxi,
                    map<pair<int,int>,int>&mp2){
        if(i==maxi)return 1;
        if(i>maxi)return 0;
        if(k==0)return 0;
        if(mp2.find({i,k})!=mp2.end())return mp2[{i,k}];
        int move1=0,move2=0,move3=0;
        if(mp[i+k])
            move1=isPossible(i+k,k,mp,maxi,mp2);
        if(mp[i+k+1])
            move2=isPossible(i+(k+1),k+1,mp,maxi,mp2);
        if(mp[i+k-1])
            move3=isPossible(i+(k-1),k-1,mp,maxi,mp2);
        return mp2[{i,k}]=move1||move2||move3;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mp;
        map<pair<int,int>,int>mp1;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]++;
        }
        if(mp[1]==0)return 0;
        int maxi=stones[stones.size()-1];
        return isPossible(1,1,mp,maxi,mp1);
    }
};