class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int papb=0,glab=0,metb=0,ans=0;
        for(int i=g.size()-1;i>=0;i--){
            int pap=0,gla=0,met=0;
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]=='P'){
                    papb=1;
                    pap++;
                }
                if(g[i][j]=='M'){
                    metb=1;
                    met++;
                }
                if(g[i][j]=='G'){
                    glab=1;
                    gla++;
                }
            }
            if(glab){
                if(i==0)ans+=gla;
                else ans+=t[i-1]+gla;
            }
            if(metb){
                if(i==0)ans+=met;
                else ans+=t[i-1]+met;
            }
            if(papb){
                if(i==0)ans+=pap;
                else ans+=t[i-1]+pap;
            }
        }
        return ans;
    }
};