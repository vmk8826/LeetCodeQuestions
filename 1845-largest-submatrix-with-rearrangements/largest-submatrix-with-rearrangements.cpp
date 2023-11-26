class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        vector<int>temp(m[0].size(),0);
        int ans=0;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j])temp[j]+=1;
                if(!m[i][j]){
                    temp[j]=0;
                }
            }
            vector<int>temp1=temp;
            sort(temp1.begin(),temp1.end());
            reverse(temp1.begin(),temp1.end());
            int k=0;
            while(k<temp1.size()){
                while(k<temp1.size()-1&&temp1[k]==temp1[k+1])k++;
                ans=max(ans,temp1[k]*(k+1));
                k++;
            }
        }
        
        return ans;
    }
};