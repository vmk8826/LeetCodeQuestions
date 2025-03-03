class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ret;
        int i=0;
        while(i<words.size()){
            int currSize = 0, j=i;
            while(currSize-1<=maxWidth&&j<words.size()){
                currSize+=(words[j].size()+1);
                if(currSize-1<=maxWidth)j++;
            }
            currSize=0;
            int k=i;
            while(k<j)
            {
                currSize+=words[k].size();
                k++;
            }
            int space = maxWidth - currSize,extraSpace=0,eachSpace;
            if(j-i>1)eachSpace = space/(j-i-1);
            if(j-i>1)extraSpace = space%(j-i-1);
            int isOneWord = j-i;
            string currString="";
            while(i<j){
                if(isOneWord>1){
                    currString+=words[i];
                    if(extraSpace>0&&i<j-1){
                        for(int k=0;k<eachSpace+1;k++){
                            currString+=" ";
                        }
                    }else if(extraSpace<=0&&i<j-1){
                        for(int k=0;k<eachSpace;k++){
                            currString+=" ";
                        }
                    }
                    i++;
                    extraSpace--;
                }
                else{
                    currString+=words[i];
                    for(int k=0;k<space;k++){
                        currString+=" ";
                    }
                    i++;
                }
            }
            ret.push_back(currString);
        }
        
        string word="";
        i=0;
        while(i<ret[ret.size()-1].size()&&ret[ret.size()-1][i]!=' '){
            word+=ret[ret.size()-1][i];
            i++;
        }
       
        i=words.size()-1;
        while(words[i]!=word){
            i--;
        }
         
        ret.pop_back();
        word="";
        while(i<words.size()){
            if(i!=words.size()-1)word+=words[i]+" ";
            else word+=words[i];
            i++;
        }
        
        int spaces = maxWidth-word.size();
        while(spaces>0){
            word+=" ";
            spaces--;
        }
        ret.push_back(word);
        return ret;
    }
};