class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>mat(matrix.size(),vector<int>(matrix[0].size(),0));
          int maxlen=0;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]=='1'){
            mat[i][0]=1;
                maxlen=1;
            }
        }
        for(int i=1;i<matrix[0].size();i++){
            if(matrix[0][i]=='1'){
            mat[0][i]=1;
                maxlen=1;
            }
        }
      
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                int curr = min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1]));
                mat[i][j]=curr+1;  
                    maxlen=max(maxlen,mat[i][j]);
                }
                // cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return maxlen*maxlen;
    }
};