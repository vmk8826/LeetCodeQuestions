class Solution {
public:
   class DSU{ 
        public:
        vector<int>par;
        DSU(int n){
            par.resize(n);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }
        void markParent(int a,int b){
            int parA=getParent(a);
            int parB=getParent(b);
            par[parA]=parB;
        }
        int getParent(int a){
            if(par[a]==a)return a;
            return par[a]=getParent(par[a]);
        }
    };
    int makeConnected(int n, vector<vector<int>>& c) {
        DSU curr(n);
        int nodes=0;
        for(int i=0;i<c.size();i++){
            int parA=curr.getParent(c[i][0]);
            int parB=curr.getParent(c[i][1]);
            if(parA==parB)nodes++;
            else{
                curr.markParent(c[i][0],c[i][1]);
            }
        }
        int counter=0;
        for(int i=0;i<n;i++){
            if(curr.par[i]==i)counter++;
        }
        if(nodes>=counter-1)return counter-1;
        return -1;
    }
};