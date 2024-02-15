class Solution {
public:
    std::string decodeAtIndex(string s, int k) {
        long long siz=0;
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i]))siz++;
        else siz=siz*(s[i]-'0');
    }
    cout<<siz<<" ";
    for(int i=s.size()-1;i>=0;i--){
        k=k%siz;
        if(k==0&&isalpha(s[i]))return string(1,s[i]);
        if(isalpha(s[i]))siz--;
        else siz=siz/(s[i]-'0');
    }
    return "";
    }
};