class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>store(wordList.begin(),wordList.end());
        queue<pair<string,int>>qu;
        qu.push({beginWord,1});
        while(!qu.empty()){
            pair<string,int> curr =qu.front();
            string storeWord=curr.first;
            qu.pop();
            store.erase(curr.first);
            if(curr.first==endWord)return curr.second;
            for(int i=0;i<curr.first.size();i++){
                for(char ch='a';ch<='z';ch++){
                    curr.first[i]=ch;
                    if(store.find(curr.first)!=store.end()){
                        qu.push({curr.first,curr.second+1});
                    }
                } 
                curr.first=storeWord;
            }
        }
        return 0;
    }
};